#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <vector>

#include "../../data/sparse-matrix/bfwb62_x_correct.h"
#include "../laclib.h"
#include "../util/doctest.h"

#ifndef DATA_DIR
#define DATA_DIR "data"
#endif

using namespace std;

TEST_CASE("testing sparse solver Intel DSS") {
    SUBCASE("from example") {
        // enforce one thread (because tests may run concurrently)
        set_num_threads(1);

        // read matrix
        auto data_path = string(DATA_DIR) + "/sparse-matrix/";
        auto mtx_path = data_path + "bfwb62.mtx";
        auto coo = read_matrix_market(mtx_path, SWAP_TO_UPPER);

        // right-hand side and solution vector
        auto rhs = vector<double>(coo->dimension, 1.0);
        auto x = vector<double>(coo->dimension, 0.0);

        // convert COO to CSR
        auto csr = CsrMatrixMkl::from(coo);

        // allocate the solver
        auto options = DssOptions::make_new();
        options->symmetric = true;
        options->positive_definite = false; // this matrix is not pos-def
        auto solver = SolverDss::make_new(options);

        // solve linear system
        solver->analyze(csr);
        solver->factorize(csr);
        solver->solve(x, rhs);

        // results
        cout << "\n";
        print_vector("x", x);
        cout << "\n";
        print_vector("x_correct", bfwb62_x_correct);
        cout << "\n";

        // check
        CHECK(equal_vectors_tol(x, bfwb62_x_correct, 1e-10));
    }
}
