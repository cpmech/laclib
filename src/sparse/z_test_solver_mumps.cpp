#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <vector>

#include "../analysis/index.h"
#include "../check/index.h"
#include "../util/doctest.h"
#include "coo_matrix.h"
#include "solver_mumps.h"
using namespace std;

#define ICNTL(I) icntl[(I)-1] // macro such that indices match documentation
#define INFOG(I) infog[(I)-1] // macro to make indices match documentation

TEST_CASE("testing sparse solver MUMPS (NP1)") {
    set_num_threads(1);

    auto coo = CooMatrix::make_new(FULL_MATRIX, 5, 13);
    coo->put(0, 0, +1.0); // << duplicated
    coo->put(0, 0, +1.0); // << duplicated
    coo->put(1, 0, +3.0);
    coo->put(0, 1, +3.0);
    coo->put(2, 1, -1.0);
    coo->put(4, 1, +4.0);
    coo->put(1, 2, +4.0);
    coo->put(2, 2, -3.0);
    coo->put(3, 2, +1.0);
    coo->put(4, 2, +2.0);
    coo->put(2, 3, +2.0);
    coo->put(1, 4, +6.0);
    coo->put(4, 4, +1.0);

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
        solver->analyze(coo);
        CHECK(solver.get()->analyzed);
        CHECK(solver.get()->factorized == false);

        solver->factorize();
        CHECK(solver.get()->analyzed);
        CHECK(solver.get()->factorized);

        solver->solve(x, rhs);
        CHECK(equal_vectors_tol(x, x_correct, 1e-14));
    }

    SUBCASE("using analyze_and_factorize and solve") {
        solver->analyze_and_factorize(coo);
        CHECK(solver.get()->analyzed);
        CHECK(solver.get()->factorized);

        solver->solve(x, rhs);
        CHECK(equal_vectors_tol(x, x_correct, 1e-14));
    }
}
