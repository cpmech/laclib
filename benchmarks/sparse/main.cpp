#include "mpi.h"
#include "check.h"
#include "report.h"
#include "../../src/laclib.h"
using namespace std;

// NOTE: the code must be wrapped within "run"  because the destructor of SolverMumps relies
// on the MPI, so cannot be called before MPI_Finalize. Also, this makes it convenient for try/catch

void run(int argc, char **argv)
{
    // allocate mpi and report
    auto mpi = MpiAux::make_new();
    auto report = Report::make_new(mpi);

    // get arguments from command line
    vector<string> defaults{"bfwb62", "metis"};
    auto args = extract_arguments_or_use_defaults(argc, argv, defaults);
    auto path = path_get_current() + "/../../../data/sparse-matrix/";
    auto name = args[0];
    auto ordering = mumps_string_to_ordering(args[1]);

    // read matrix
    report.print("reading matrix ", name);
    auto onebased = true;
    auto trip = read_matrix_market(path + name + ".mtx", onebased, mpi.rank(), mpi.size());
    report.print("... symmetric = ", trip->symmetric ? "true" : "false");
    report.print("... number of rows (equal to columns) = ", trip->m);
    report.print("... number of non-zeros (pattern entries) = ", trip->pos);
    report.measure_step(STEP_READ_MATRIX);

    // allocate solver and options
    auto solver = SolverMumps::make_new(mpi, trip->symmetric);
    auto options = MumpsOptions::make_new();
    auto verbose = mpi.rank() == 0;

    // set options
    options.ordering = ordering;
    options.pct_inc_workspace = 100;
    options.max_work_memory = 30000 / mpi.size();

    // start linear solver execution /////////////////////////////////////////////////////////////////
    report.solver_start_stopwatch();

    report.print("analyzing", "");
    solver->analyze(trip, options, verbose);
    report.measure_step(STEP_ANALYZE);

    report.print("factorizing", "");
    solver->factorize(verbose);
    report.measure_step(STEP_FACTORIZE);

    auto rhs = vector<double>(trip->n, 1.0);
    auto x = vector<double>(trip->n, 0.0);
    auto rhs_is_distributed = false;

    report.print("solving", "");
    solver->solve(x, rhs, rhs_is_distributed, verbose);
    report.measure_step(STEP_SOLVE);

    // stop linear solver execution /////////////////////////////////////////////////////////////////
    report.solver_stop_stopwatch();

    // write report
    report.write_json("mumps", name, trip, options);

    // check results
    check_x(mpi, name, x);
    check_ax(mpi, name, trip, x, rhs);
}

int main(int argc, char **argv)
{
    MPI_Init(&argc, &argv);

    try
    {
        run(argc, argv);
    }
    CATCH_ALL

    MPI_Finalize();
    return 0;
}