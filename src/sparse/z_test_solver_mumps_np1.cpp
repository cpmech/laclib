#include <vector>
#include "solver_mumps.h"
#include "triplet_for_mumps.h"
#include "../check/check.h"
#include "../mpiaux/mpiaux.h"
#include "../util/doctest_mpi.h"
using namespace std;

#define ICNTL(I) icntl[(I)-1] // macro such that indices match documentation
#define INFOG(I) infog[(I)-1] // macro to make indices match documentation

MPI_TEST_CASE("testing sparse solver MUMPS (NP1)", 1)
{
    auto mpi = MpiAux::make_new(std::vector<int>{});
    auto trip = triplet_for_mumps_new(5, 5, 13);
    trip->put_zero_based(0, 0, +1.0); // << duplicated
    trip->put_zero_based(0, 0, +1.0); // << duplicated
    trip->put_zero_based(1, 0, +3.0);
    trip->put_zero_based(0, 1, +3.0);
    trip->put_zero_based(2, 1, -1.0);
    trip->put_zero_based(4, 1, +4.0);
    trip->put_zero_based(1, 2, +4.0);
    trip->put_zero_based(2, 2, -3.0);
    trip->put_zero_based(3, 2, +1.0);
    trip->put_zero_based(4, 2, +2.0);
    trip->put_zero_based(2, 3, +2.0);
    trip->put_zero_based(1, 4, +6.0);
    trip->put_zero_based(4, 4, +1.0);

    SUBCASE("make_new")
    {
        auto solver = MumpsSolver::make_new(mpi, MUMPS_SYMMETRY_NONE);

        CHECK(solver.get()->data.par == MUMPS_HOST_ALSO_WORKS);
        CHECK(solver.get()->data.sym == MUMPS_SYMMETRY_NONE);
        CHECK(solver.get()->data.ICNTL(1) == -1);
        CHECK(solver.get()->data.ICNTL(2) == -1);
        CHECK(solver.get()->data.ICNTL(3) == -1);
        CHECK(solver.get()->data.ICNTL(4) == -1);
        CHECK(solver.get()->factorized == false);
    }

    SUBCASE("analize_and_factorize")
    {
        auto solver = MumpsSolver::make_new(mpi, MUMPS_SYMMETRY_NONE);
        auto options = MumpsOptions::make_new();
        auto verbose = false;

        auto status = solver->analize_and_factorize(trip.get(), options, verbose);
        CHECK(options.ordering == MUMPS_ORDERING_AUTO);
        CHECK(options.scaling == MUMPS_SCALING_AUTO);
        CHECK(options.pct_inc_workspace == MUMPS_DEFAULT_PCT_INC_WORKSPACE);
        CHECK(options.max_work_memory == 0);
        CHECK(status == 0);
        CHECK(solver.get()->factorized == true);
        CHECK(solver.get()->data.INFOG(7) == MUMPS_ORDERING_AMF);
    }

    SUBCASE("solve system")
    {
        auto solver = MumpsSolver::make_new(mpi, MUMPS_SYMMETRY_NONE);
        auto options = MumpsOptions::make_new();
        auto rhs_is_distributed = false;
        auto verbose = false;

        auto status = solver->analize_and_factorize(trip.get(), options, verbose);
        CHECK(status == 0);
        CHECK(solver.get()->factorized == true);

        auto rhs = vector<double>{8.0, 45.0, -3.0, 3.0, 19.0};
        auto x = vector<double>{0, 0, 0, 0, 0};
        auto x_correct = vector<double>{1, 2, 3, 4, 5};

        status = solver->solve(x, rhs, rhs_is_distributed, verbose);
        CHECK(status == 0);
        CHECK(equal_vectors_tol(x, x_correct, 1e-14) == true);
    }
}