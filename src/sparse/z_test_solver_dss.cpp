#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <vector>

#include "../analysis/index.h"
#include "../check/index.h"
#include "../util/doctest.h"
#include "../util/print_vector.h"
#include "coo_matrix.h"
#include "solver_dss.h"

using namespace std;

TEST_CASE("testing sparse solver Intel DSS") {
    set_num_threads(1);

    // 1  2  .  .  .
    // 3  4  .  .  .
    // .  .  5  6  .
    // .  .  7  8  .
    // .  .  .  .  9
    auto coo = CooMatrix::make_new(FULL_MATRIX, 5, 9);
    coo->put(0, 0, 1.0);
    coo->put(0, 1, 2.0);
    coo->put(1, 0, 3.0);
    coo->put(1, 1, 4.0);
    coo->put(2, 2, 5.0);
    coo->put(2, 3, 6.0);
    coo->put(3, 2, 7.0);
    coo->put(3, 3, 8.0);
    coo->put(4, 4, 9.0);

    // auto rhs = vector<double>{1.0, 2.0, 3.0, 4.0, 5.0};
    // auto x = vector<double>{0.0, 0.0, 0.0, 0.0, 0.0};

    auto options = DssOptions::make_new();
    // options->symmetric = true;
    // options->positive_definite = true;
    auto solver = SolverDss::make_new(options);

    solver->analyze(coo, true);
    solver->factorize();
    // solver->solve(x, rhs);

    // print_vector("x", x);
}
