#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <vector>

#include "../analysis/index.h"
#include "../check/index.h"
#include "../util/doctest.h"
#include "../util/print_vector.h"
#include "coo_matrix.h"
#include "csr_matrix.h"
#include "solver_dss.h"

using namespace std;

TEST_CASE("testing sparse solver Intel DSS") {
    SUBCASE("from example") {
        set_num_threads(1);

        //  9.00  1.5   6.0  0.750   3.0
        //  1.50  0.5   0.0  0.000   0.0
        //  6.00  0.0  12.0  0.000   0.0
        //  0.75  0.0   0.0  0.625   0.0
        //  3.00  0.0   0.0  0.000  16.0
        auto coo = CooMatrix::make_new(UPPER_TRIANGULAR, 5, 9);
        // diagonal
        coo->put(0, 0, 9.0);
        coo->put(1, 1, 0.5);
        coo->put(2, 2, 12.0);
        coo->put(3, 3, 0.625);
        coo->put(4, 4, 16.0);
        // upper diagonal
        coo->put(0, 1, 1.5);
        coo->put(0, 2, 6.0);
        coo->put(0, 3, 0.75);
        coo->put(0, 4, 3.0);

        // convert COO to CSR
        auto csr = CsrMatrixMkl::from(coo);

        auto rhs = vector<double>{1.0, 2.0, 3.0, 4.0, 5.0};
        auto x = vector<double>{0.0, 0.0, 0.0, 0.0, 0.0};

        auto options = DssOptions::make_new();
        options->symmetric = true;
        options->positive_definite = true;
        auto solver = SolverDss::make_new(options);

        solver->analyze(csr);
        solver->factorize(csr);
        solver->solve(x, rhs);

        print_vector("x", x);

        auto x_correct = vector<double>{-979.0 / 3.0, 983.0, 1961.0 / 12.0, 398.0, 123.0 / 2.0};

        CHECK(equal_vectors_tol(x, x_correct, 1e-11));
    }
}
