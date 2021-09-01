#include "../../src/laclib.h"
#include "check.h"
using namespace std;

void run(int argc, char **argv) {
    // allocate mpi and report
    auto report = Report::make_new();

    // get arguments from command line
    vector<string> defaults{
        "bfwb62",  // default matrix_name
        "1",       // default omp_num_threads
        "metis",   // default ordering
    };
    auto args = extract_arguments_or_use_defaults(argc, argv, defaults);
    auto matrix_name = args[0];
    auto omp_num_threads = std::atoi(args[1].c_str());
    auto ordering = mumps_string_to_ordering(args[2]);

    // read matrix
    auto path = path_get_current() + "/../../../benchmarks/sparse/data/";
    auto filename = path + matrix_name + ".mtx";
    auto onebased = true;
    auto trip = read_matrix_market(filename, onebased);
    report->measure_step(STEP_READ_MATRIX);

    // set number of threads
    set_num_threads(omp_num_threads);

    // set options
    auto options = MumpsOptions::make_new(trip->symmetric);
    options->omp_num_threads = omp_num_threads;
    options->ordering = ordering;
    options->max_work_memory = 30000;

    // allocate solver
    auto solver = SolverMumps::make_new(options);
    auto verbose = true;

    // set right-hand-side and solution vector
    auto rhs = vector<double>(trip->n, 1.0);
    auto x = vector<double>(trip->n, 0.0);

    // start linear solver execution /////////////////////////////////////
    report->solver_start_stopwatch();

    solver->analyze(trip, verbose);
    report->measure_step(STEP_ANALYZE);

    solver->factorize(verbose);
    report->measure_step(STEP_FACTORIZE);

    solver->solve(x, rhs, verbose);
    report->measure_step(STEP_SOLVE);

    report->solver_stop_stopwatch();
    // stop linear solver execution //////////////////////////////////////

    // check results
    check_x(matrix_name, x);

    // write report
    auto stats = Stats::make_new(trip, x, rhs);
    auto out_dir = path_get_current() + "/../../../benchmarks/sparse/results/latest/";
    report->write_json(out_dir, "mumps", matrix_name, options, trip, stats);
}

int main(int argc, char **argv) {
    try {
        run(argc, argv);
    }
    CATCH_ALL
    return 0;
}
