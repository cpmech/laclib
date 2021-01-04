#include "mpi.h"
#include "check.h"
#include "report.h"
#include "../../src/laclib.h"
using namespace std;

// NOTE: the code must be wrapped within "run"  because the destructor of MumpsSolver relies
// on the MPI, so cannot be called before MPI_Finalize. Also, this makes it convenient for try/catch

void run(int argc, char **argv)
{
    // allocate mpi and report
    auto mpi = MpiAux::make_new();
    auto report = Report::make_new(mpi);

    // get matrix name from command line
    auto name = extract_first_argument(argc, argv, "bfwb62");
    auto path = path_get_current() + "/../../../data/sparse-matrix/";

    // read matrix
    report.print("reading matrix ", name);
    auto data = read_matrix_for_mumps(path + name + ".mtx");
    report.print("... symmetric = ", data.symmetric ? "true" : "false");
    report.print("... number of rows (equal to columns) = ", data.trip->m);
    report.print("... number of non-zeros (pattern entries) = ", data.trip->pos);
    report.measure_step(STEP_READ_MATRIX);

    // allocate solver and options
    auto solver = MumpsSolver::make_new(mpi, data.symmetric);
    auto options = MumpsOptions::make_new();
    auto verbose = mpi.rank() == 0;

    // set options
    options.ordering = MUMPS_ORDERING_AMF;
    options.pct_inc_workspace = 100;
    options.max_work_memory = 30000;

    // start linear solver execution /////////////////////////////////////////////////////////////////
    report.solver_start_stopwatch();

    report.print("analyzing", "");
    solver->analyze(data.trip.get(), options, verbose);
    report.measure_step(STEP_ANALYZE);

    report.print("factorizing", "");
    solver->factorize(verbose);
    report.measure_step(STEP_FACTORIZE);

    auto n = data.trip->n;
    auto rhs = vector<double>(n, 1.0);
    auto x = vector<double>(n, 0.0);
    auto rhs_is_distributed = false;

    report.print("solving", "");
    solver->solve(x, rhs, rhs_is_distributed, verbose);
    report.measure_step(STEP_SOLVE);

    // stop linear solver execution /////////////////////////////////////////////////////////////////
    report.solver_stop_stopwatch();

    // write report
    report.write_json("mumps", name, data, options);

    // check results
    check_x(mpi, name, x);
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