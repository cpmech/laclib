#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <vector>

#include "../analysis/index.h"
#include "../check/index.h"
#include "../util/doctest.h"
#include "solver_mumps.h"
#include "sparse_triplet.h"
using namespace std;

#define ICNTL(I) icntl[(I)-1] // macro such that indices match documentation
#define INFOG(I) infog[(I)-1] // macro to make indices match documentation

TEST_CASE("testing sparse solver MUMPS (NP1)") {
    set_num_threads(1);

    auto trip = SparseTriplet::make_new(FULL_MATRIX, 5, 13);
    trip->put(0, 0, +1.0); // << duplicated
    trip->put(0, 0, +1.0); // << duplicated
    trip->put(1, 0, +3.0);
    trip->put(0, 1, +3.0);
    trip->put(2, 1, -1.0);
    trip->put(4, 1, +4.0);
    trip->put(1, 2, +4.0);
    trip->put(2, 2, -3.0);
    trip->put(3, 2, +1.0);
    trip->put(4, 2, +2.0);
    trip->put(2, 3, +2.0);
    trip->put(1, 4, +6.0);
    trip->put(4, 4, +1.0);

    auto rhs = vector<double>{8.0, 45.0, -3.0, 3.0, 19.0};
    auto x = vector<double>{0, 0, 0, 0, 0};
    auto x_correct = vector<double>{1, 2, 3, 4, 5};

    auto options = MumpsOptions::make_new();
    auto solver = SolverMumps::make_new(options);

    REQUIRE(solver.get()->data.par == MUMPS_PAR_HOST_ALSO_WORKS);
    REQUIRE(solver.get()->data.sym == MUMPS_SYMMETRY_NONE);
    REQUIRE(solver.get()->data.ICNTL(1) == -1);
    REQUIRE(solver.get()->data.ICNTL(2) == -1);
    REQUIRE(solver.get()->data.ICNTL(3) == -1);
    REQUIRE(solver.get()->data.ICNTL(4) == -1);
    REQUIRE(solver.get()->analyzed == false);
    REQUIRE(solver.get()->factorized == false);

    SUBCASE("using analyze, factorize and solve") {
        solver->analyze(trip);
        CHECK(solver.get()->analyzed == true);
        CHECK(solver.get()->factorized == false);

        solver->factorize();
        CHECK(solver.get()->analyzed == true);
        CHECK(solver.get()->factorized == true);

        solver->solve(x, rhs);
        CHECK(equal_vectors_tol(x, x_correct, 1e-14) == true);
    }

    SUBCASE("using analyze_and_factorize and solve") {
        solver->analyze_and_factorize(trip);
        CHECK(solver.get()->analyzed == true);
        CHECK(solver.get()->factorized == true);

        solver->solve(x, rhs);
        CHECK(equal_vectors_tol(x, x_correct, 1e-14) == true);
    }
}
