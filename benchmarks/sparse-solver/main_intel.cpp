#include <iostream>
#include <string>

#include "../../src/laclib.h"
#include "check.h"

#ifndef MTX_DIR
#define MTX_DIR "$HOME/Downloads/matrix-market"
#endif

#ifndef OUT_DIR
#define OUT_DIR "/tmp/laclib/results/latest"
#endif

using namespace std;

void run(int argc, char **argv) {
    // allocate report
    auto report = Report::make_new();

    // get arguments from command line
    vector<string> defaults{
        "bfwb62", // default matrix_name
        "1",      // default omp_num_threads
        "metis",  // default ordering
    };
    auto args = extract_arguments_or_use_defaults(argc, argv, defaults);
    auto matrix_name = args[0];
    auto omp_num_threads = std::atoi(args[1].c_str());

    // read matrix
    auto filename = string(MTX_DIR) + "/" + matrix_name + ".mtx";
    auto coo = read_matrix_market(filename, SWAP_TO_UPPER);
    report->measure_step(STEP_READ_MATRIX);

    // set number of threads
    set_num_threads(omp_num_threads);

    // set options
    auto options = DssOptions::make_new(is_symmetric(coo->layout));

    // allocate solver
    auto solver = SolverDss::make_new(options);
    std::string solver_name = "intel";
    std::string str_ordering = "unknown";

    // set verbose mode
    auto verbose = true;

    // set right-hand-side and solution vector
    auto rhs = vector<double>(coo->dimension, 1.0);
    auto x = vector<double>(coo->dimension, 0.0);

    // start linear solver execution /////////////////////////////////////
    report->solver_start_stopwatch();

    auto csr = CsrMatrixMkl::from(coo);
    report->measure_step(STEP_CONVERSION);

    // if (!csr->ok_for_dss(true)) {
    //     throw "matrix is not OK for DSS";
    // }

    solver->analyze(csr, verbose);
    report->measure_step(STEP_ANALYZE);

    solver->factorize(csr, verbose);
    report->measure_step(STEP_FACTORIZE);

    solver->solve(x, rhs, verbose);
    report->measure_step(STEP_SOLVE);

    report->solver_stop_stopwatch();
    // stop linear solver execution //////////////////////////////////////

    // check results
    check_x(matrix_name, x);

    // write report
    auto stats = Stats::make_new(coo, x, rhs);
    report->write_json(OUT_DIR,
                       solver_name,
                       matrix_name,
                       str_ordering,
                       omp_num_threads,
                       coo,
                       stats);
}

int main(int argc, char **argv) {
    try {
        run(argc, argv);
    }
    CATCH_ALL
    return 0;
}
