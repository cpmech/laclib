#include "check.h"
#include "report.h"
#include "stats.h"
#include "../../src/laclib.h"
using namespace std;

void run(int argc, char **argv)
{
    // allocate mpi and report
    auto mpi = MpiAux::make_new();
    auto report = Report::make_new(mpi);
    auto mpi_size = mpi->size();

    // get arguments from command line
    vector<string> defaults{"bfwb62", "metis"};
    auto args = extract_arguments_or_use_defaults(argc, argv, defaults);
    auto path = path_get_current() + "/../../../benchmarks/sparse/data/";
    auto name = args[0];
    auto filename = path + name + ".mtx";
    auto ordering = mumps_string_to_ordering(args[1]);

    // read matrix
    auto onebased = true;
    auto trip = read_matrix_market(filename, onebased);
    report->measure_step(STEP_READ_MATRIX);

    // allocate solver and options
    auto solver = SolverMumps::make_new(mpi, trip->symmetric);
    auto options = MumpsOptions::make_new();
    auto verbose = true;

    // set options
    options.ordering = ordering;
    options.max_work_memory = 30000 / mpi_size;

    // start linear solver execution /////////////////////////////////////////////////////////////////
    report->solver_start_stopwatch();

    solver->analyze(trip, options, verbose);
    report->measure_step(STEP_ANALYZE);

    solver->factorize(verbose);
    report->measure_step(STEP_FACTORIZE);

    auto rhs = vector<double>(trip->n, 1.0);
    auto x = vector<double>(trip->n, 0.0);
    auto rhs_is_distributed = false;

    solver->solve(x, rhs, rhs_is_distributed, verbose);
    report->measure_step(STEP_SOLVE);

    // stop linear solver execution /////////////////////////////////////////////////////////////////
    report->solver_stop_stopwatch();

    // check results
    check_x(mpi, name, x);

    // write report
    auto stats = Stats::make_new(mpi, trip, x, rhs);
    report->write_json("mumps", name, options, trip, stats);
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
