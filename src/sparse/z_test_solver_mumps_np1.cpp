#include "../util/doctest_mpi.h"
#include "triplet_for_mumps.h"
#include "solver_mumps.h"
#include <vector>
using namespace std;

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

    SUBCASE("MUMPS allocs properly")
    {
        auto solver = MumpsSolver::make_new();

        CHECK(solver.get()->data.comm_fortran == -987654);
    }

    SUBCASE("MUMPS init is OK")
    {
        auto options = MumpsOptions::make_new();
        options.verbose = true;

        auto solver = MumpsSolver::make_new();
        solver->init(options);

        solver->terminate();
    }

    /*
    SUBCASE("solve system")
    {

        auto b = vector<double>{8.0, 45.0, -3.0, 3.0, 19.0};
    }
    */
}
