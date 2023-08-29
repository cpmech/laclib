#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <vector>

#include "../analysis/index.h"
#include "../check/check.h"
#include "../util/doctest.h"
#include "../util/print_vector.h"
#include "solver_dss.h"
#include "sparse_triplet.h"
using namespace std;

TEST_CASE("testing sparse solver Intel DSS") {
    set_num_threads(1);

    bool one_based = true;
    auto trip = SparseTriplet::make_new(5, 5, 9, one_based);
    /* this is the unsymmetric case
    trip->put(0, 0, 1.0);
    trip->put(0, 1, 2.0);
    trip->put(1, 0, 3.0);
    trip->put(1, 1, 4.0);
    trip->put(2, 2, 5.0);
    trip->put(2, 3, 6.0);
    trip->put(3, 2, 7.0);
    trip->put(3, 3, 8.0);
    trip->put(4, 4, 9.0);
    auto rhs = vector<double>{0.0, 1.0, 2.0, 3.0, 4.0};
    */

    auto rhs = vector<double>{1.0, 2.0, 3.0, 4.0, 5.0};
    auto x = vector<double>{0.0, 0.0, 0.0, 0.0, 0.0};

    auto options = DssOptions::make_new();
    options->symmetric = true;
    options->positive_definite = true;
    auto solver = SolverDss::make_new(options);

    solver->analyze(trip);
    solver->factorize();
    // solver->solve(x, rhs);

    print_vector("x", x);
}
