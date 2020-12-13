#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../util/doctest.h"
#include "triplet_for_mumps.h"
#include "solver_mumps.h"
#include <vector>
using namespace std;

TEST_CASE("testing sparse solver MUMPS")
{
    SUBCASE("MUMPS allocs properly")
    {
        auto solver = MumpsSolver::make_new();

        CHECK(solver.get()->data.comm_fortran == -987654);
    }

    /*
    SUBCASE("solve system")
    {
        auto trip = triplet_new(5, 5, 13);
        triplet_put(trip.get(), 0, 0, +1.0); // << duplicated
        triplet_put(trip.get(), 0, 0, +1.0); // << duplicated
        triplet_put(trip.get(), 1, 0, +3.0);
        triplet_put(trip.get(), 0, 1, +3.0);
        triplet_put(trip.get(), 2, 1, -1.0);
        triplet_put(trip.get(), 4, 1, +4.0);
        triplet_put(trip.get(), 1, 2, +4.0);
        triplet_put(trip.get(), 2, 2, -3.0);
        triplet_put(trip.get(), 3, 2, +1.0);
        triplet_put(trip.get(), 4, 2, +2.0);
        triplet_put(trip.get(), 2, 3, +2.0);
        triplet_put(trip.get(), 1, 4, +6.0);
        triplet_put(trip.get(), 4, 4, +1.0);

        auto b = vector<double>{8.0, 45.0, -3.0, 3.0, 19.0};
    }
    */
}