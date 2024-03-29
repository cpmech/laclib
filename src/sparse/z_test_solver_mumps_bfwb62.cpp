#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <iostream>
#include <vector>

#include "../../data/sparse-matrix/bfwb62_x_correct.h"
#include "../laclib.h"
#include "../util/doctest.h"

#ifndef DATA_DIR
#define DATA_DIR "data"
#endif

using namespace std;

TEST_CASE("solve bfwb62 system") {
    set_num_threads(1);

    auto data_path = string(DATA_DIR) + "/sparse-matrix/";

    auto mtx_path = data_path + "bfwb62.mtx";
    auto coo = read_matrix_market(mtx_path);

    auto options = MumpsOptions::make_new(is_symmetric(coo->layout));
    auto solver = SolverMumps::make_new(options);

    solver->analyze_and_factorize(coo);
    CHECK(solver.get()->analyzed);
    CHECK(solver.get()->factorized);

    auto rhs = vector<double>(coo->dimension, 1.0);
    auto x = vector<double>(coo->dimension, 0.0);

    solver->solve(x, rhs);

    cout << "\n";
    print_vector("x", x);
    cout << "\n";
    print_vector("x_correct", bfwb62_x_correct);
    cout << "\n";

    CHECK(equal_vectors_tol(x, bfwb62_x_correct, 1e-10, true));
}
