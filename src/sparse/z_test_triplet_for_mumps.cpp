#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../util/doctest.h"
#include "../check/check.h"
#include "triplet_for_mumps.h"
#include <vector>
using namespace std;

TEST_CASE("testing TripletForMumps (put_zero_based)")
{
    auto trip = triplet_for_mumps_new(3, 3, 4);

    REQUIRE(trip->pos == 0);
    REQUIRE(trip->max == 4);

    SUBCASE("triplet_for_mumps_new")
    {
        vector<MUMPS_INT> Icorrect{0, 0, 0, 0};
        vector<MUMPS_INT> Jcorrect{0, 0, 0, 0};
        vector<double> Xcorrect{0.0, 0.0, 0.0, 0.0};

        CHECK(trip->m == 3);
        CHECK(trip->n == 3);
        CHECK(trip->pos == 0);
        CHECK(trip->max == 4);
        CHECK(trip->I.size() == 4);
        CHECK(trip->J.size() == 4);
        CHECK(trip->X.size() == 4);
        CHECK(equal_vectors(trip->I, Icorrect));
        CHECK(equal_vectors(trip->J, Jcorrect));
        CHECK(equal_vectors_tol(trip->X, Xcorrect, 1e-15));
    }

    SUBCASE("put_zero_based")
    {
        vector<MUMPS_INT> Icorrect{1, 2, 3, 1};
        vector<MUMPS_INT> Jcorrect{1, 2, 3, 2};
        vector<double> Xcorrect{10.0, 11.0, 12.0, 4.0};

        trip->put_zero_based(0, 0, 10.0);
        trip->put_zero_based(1, 1, 11.0);
        trip->put_zero_based(2, 2, 12.0);
        trip->put_zero_based(0, 1, 4.0);

        CHECK(trip->pos == 4);
        CHECK(equal_vectors(trip->I, Icorrect));
        CHECK(equal_vectors(trip->J, Jcorrect));
        CHECK(equal_vectors_tol(trip->X, Xcorrect, 1e-15));
    }

    SUBCASE("put_zero_based: exceptions")
    {
        CHECK_THROWS_WITH(trip->put_zero_based(-1, 0, 10.0), "TripletForMumps::put_zero_based: index of row is outside range");
        CHECK_THROWS_WITH(trip->put_zero_based(3, 0, 10.0), "TripletForMumps::put_zero_based: index of row is outside range");
        CHECK_THROWS_WITH(trip->put_zero_based(0, -1, 11.0), "TripletForMumps::put_zero_based: index of column is outside range");
        CHECK_THROWS_WITH(trip->put_zero_based(0, 3, 11.0), "TripletForMumps::put_zero_based: index of column is outside range");

        trip->put_zero_based(0, 0, 1);
        trip->put_zero_based(0, 0, 2);
        trip->put_zero_based(0, 0, 3);
        trip->put_zero_based(0, 0, 4);

        CHECK_THROWS_WITH(trip->put_zero_based(0, 0, 4.0), "TripletForMumps::put_zero_based: max number of items has been exceeded");
    }
}

TEST_CASE("testing TripletForMumps (put_one_based)")
{
    auto trip = triplet_for_mumps_new(3, 3, 4);

    REQUIRE(trip->pos == 0);
    REQUIRE(trip->max == 4);

    SUBCASE("triplet_for_mumps_new")
    {
        vector<MUMPS_INT> Icorrect{0, 0, 0, 0};
        vector<MUMPS_INT> Jcorrect{0, 0, 0, 0};
        vector<double> Xcorrect{0.0, 0.0, 0.0, 0.0};

        CHECK(trip->m == 3);
        CHECK(trip->n == 3);
        CHECK(trip->pos == 0);
        CHECK(trip->max == 4);
        CHECK(trip->I.size() == 4);
        CHECK(trip->J.size() == 4);
        CHECK(trip->X.size() == 4);
        CHECK(equal_vectors(trip->I, Icorrect));
        CHECK(equal_vectors(trip->J, Jcorrect));
        CHECK(equal_vectors_tol(trip->X, Xcorrect, 1e-15));
    }

    SUBCASE("put_one_based")
    {
        vector<MUMPS_INT> Icorrect{1, 2, 3, 1};
        vector<MUMPS_INT> Jcorrect{1, 2, 3, 2};
        vector<double> Xcorrect{10.0, 11.0, 12.0, 4.0};

        trip->put_one_based(1, 1, 10.0);
        trip->put_one_based(2, 2, 11.0);
        trip->put_one_based(3, 3, 12.0);
        trip->put_one_based(1, 2, 4.0);

        CHECK(trip->pos == 4);
        CHECK(equal_vectors(trip->I, Icorrect));
        CHECK(equal_vectors(trip->J, Jcorrect));
        CHECK(equal_vectors_tol(trip->X, Xcorrect, 1e-15));
    }

    SUBCASE("put_one_based: exceptions")
    {
        CHECK_THROWS_WITH(trip->put_one_based(0, 1, 10.0), "TripletForMumps::put_one_based: index of row is outside range");
        CHECK_THROWS_WITH(trip->put_one_based(4, 1, 10.0), "TripletForMumps::put_one_based: index of row is outside range");
        CHECK_THROWS_WITH(trip->put_one_based(1, 0, 11.0), "TripletForMumps::put_one_based: index of column is outside range");
        CHECK_THROWS_WITH(trip->put_one_based(1, 4, 11.0), "TripletForMumps::put_one_based: index of column is outside range");

        trip->put_one_based(1, 1, 1);
        trip->put_one_based(1, 1, 2);
        trip->put_one_based(1, 1, 3);
        trip->put_one_based(1, 1, 4);

        CHECK_THROWS_WITH(trip->put_one_based(1, 1, 4.0), "TripletForMumps::put_one_based: max number of items has been exceeded");
    }
}
