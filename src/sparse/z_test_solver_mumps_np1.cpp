#include "../util/doctest_mpi.h"
#include "triplet_for_mumps.h"
#include "solver_mumps.h"
#include <vector>
using namespace std;

#define ICNTL(I) icntl[(I)-1] // macro such that indices match documentation

MPI_TEST_CASE("testing sparse solver MUMPS (NP1)", 1)
{
    auto trip = triplet_for_mumps_new(5, 5, 13);
    trip->put_zero_based(0, 0, +1.0); // << duplicated
    trip->put_zero_based(0, 0, +2.0); // << duplicated
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
        auto solver = MumpsSolver::make_new();

        CHECK(solver.get()->options.verbose == false);
        CHECK(solver.get()->options.symmetry == SYMMETRY_NONE);
        CHECK(solver.get()->options.ordering == ORDERING_AUTO);
        CHECK(solver.get()->options.scaling == SCALING_AUTO);
        CHECK(solver.get()->called_initialize == false);
        CHECK(solver.get()->called_analize_and_factorize == false);
    }

    SUBCASE("initialize")
    {
        auto options = MumpsOptions::make_new();
        auto solver = MumpsSolver::make_new();
        solver->initialize(options);

        CHECK(solver.get()->data.comm_fortran == -987654);
        CHECK(solver.get()->data.ICNTL(1) == -1);
        CHECK(solver.get()->data.ICNTL(2) == -1);
        CHECK(solver.get()->data.ICNTL(3) == -1);
        CHECK(solver.get()->data.ICNTL(4) == -1);
        CHECK(solver.get()->called_initialize == true);
        CHECK(solver.get()->called_analize_and_factorize == false);

        solver->terminate();

        CHECK(solver.get()->called_initialize == false);
        CHECK(solver.get()->called_analize_and_factorize == false);
    }

    SUBCASE("analize_and_factorize")
    {
        auto options = MumpsOptions::make_new();
        auto solver = MumpsSolver::make_new();
        solver->initialize(options);

        CHECK(solver.get()->called_initialize == true);

        solver->analize_and_factorize(trip.get());

        CHECK(solver.get()->called_initialize == true);
        CHECK(solver.get()->called_analize_and_factorize == true);

        solver->terminate();

        CHECK(solver.get()->called_initialize == false);
        CHECK(solver.get()->called_analize_and_factorize == false);
    }

    /*
    SUBCASE("solve system")
    {

        auto b = vector<double>{8.0, 45.0, -3.0, 3.0, 19.0};
    }
    */
}
