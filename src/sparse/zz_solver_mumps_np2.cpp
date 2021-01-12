#include <vector>
#include "solver_mumps.h"
#include "sparse_triplet.h"
#include "../check/check.h"
#include "../mpiaux/mpiaux.h"
#include "../util/doctest_mpi.h"
using namespace std;

#define ICNTL(I) icntl[(I)-1] // macro such that indices match documentation
#define INFOG(I) infog[(I)-1] // macro to make indices match documentation

MPI_TEST_CASE("testing sparse solver MUMPS (NP2)", 2)
{
    auto mpi = MpiAux::make_new();
    bool onebased = true;

    std::unique_ptr<SparseTriplet> trip;

    if (mpi.rank() == 0)
    {
        trip = SparseTriplet::make_new(5, 5, 6, onebased);
        trip->put(0, 0, +1.0); // << duplicated
        trip->put(0, 0, +1.0); // << duplicated
        trip->put(1, 0, +3.0);
        trip->put(0, 1, +3.0);
        trip->put(2, 1, -1.0);
        trip->put(4, 1, +4.0);
    }
    else
    {
        trip = SparseTriplet::make_new(5, 5, 7, onebased);
        trip->put(1, 2, +4.0);
        trip->put(2, 2, -3.0);
        trip->put(3, 2, +1.0);
        trip->put(4, 2, +2.0);
        trip->put(2, 3, +2.0);
        trip->put(1, 4, +6.0);
        trip->put(4, 4, +1.0);
    }

    SUBCASE("make_new")
    {
        auto solver = SolverMumps::make_new(mpi, MUMPS_SYMMETRY_NONE);

        CHECK(solver.get()->data.par == 1);
        CHECK(solver.get()->data.sym == MUMPS_SYMMETRY_NONE);
        CHECK(solver.get()->data.ICNTL(1) == -1);
        CHECK(solver.get()->data.ICNTL(2) == -1);
        CHECK(solver.get()->data.ICNTL(3) == -1);
        CHECK(solver.get()->data.ICNTL(4) == -1);
        CHECK(solver.get()->factorized == false);
    }

    SUBCASE("analize_and_factorize")
    {
        auto solver = SolverMumps::make_new(mpi, MUMPS_SYMMETRY_NONE);
        auto options = MumpsOptions::make_new();

        solver->analyze_and_factorize(trip, options);
        CHECK(options.ordering == MUMPS_ORDERING_AUTO);
        CHECK(options.scaling == MUMPS_SCALING_AUTO);
        CHECK(options.pct_inc_workspace == 100);
        CHECK(options.max_work_memory == 0);
        CHECK(solver.get()->factorized == true);
    }

    SUBCASE("solve system")
    {
        auto solver = SolverMumps::make_new(mpi, MUMPS_SYMMETRY_NONE);

        solver->analyze_and_factorize(trip);
        CHECK(solver.get()->factorized == true);

        auto rhs = vector<double>{8.0, 45.0, -3.0, 3.0, 19.0};
        auto x = vector<double>{0, 0, 0, 0, 0};
        auto x_correct = vector<double>{1, 2, 3, 4, 5};

        solver->solve(x, rhs);
        CHECK(equal_vectors_tol(x, x_correct, 1e-14) == true);
    }
}
