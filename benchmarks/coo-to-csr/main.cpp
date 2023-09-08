#include <memory>
#include <string>

#include "../../src/laclib.h"

#ifndef MTX_DIR
#define MTX_DIR "$HOME/Downloads/matrix-market"
#endif

#ifndef OUT_DIR
#define OUT_DIR "/tmp/laclib/results/latest"
#endif

using namespace std;

void run(int argc, char **argv) {
    // get arguments from command line
    vector<string> defaults{
        "bfwb62", // default matrix_name
        "1",      // default omp_num_threads
    };
    auto args = extract_arguments_or_use_defaults(argc, argv, defaults);
    auto matrix_name = args[0];
    auto omp_num_threads = std::atoi(args[1].c_str());

    // allocate report
    auto report = Report::make_new();

    // read matrix
    auto filename = string(MTX_DIR) + "/" + matrix_name + ".mtx";
    auto coo = read_matrix_market(filename);
    report->measure_step(STEP_READ_MATRIX);

    // convert from coo to csr
#ifdef USE_MKL
    auto method = "mkl";
    auto csr = CsrMatrixMkl::from(coo);
    report->measure_step(STEP_CONVERSION);
#else
    auto method = "local";
    auto csr = CsrMatrix::from(coo);
    report->measure_step(STEP_CONVERSION);
#endif

    // write report
    report->write_json_conversion(OUT_DIR,
                                  method,
                                  matrix_name,
                                  omp_num_threads,
                                  coo);
}

MAIN_FUNCTION(run)
