#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../util/doctest.h"
#include "../check/check.h"
#include "triplet.h"
#include <vector>
using namespace std;

TEST_CASE("testing Triplet")
{
    auto trip = triplet_new(3, 3, 4);

    REQUIRE(trip->pos == 0);
    REQUIRE(trip->max == 4);

    SUBCASE("triplet_new")
    {
        vector<size_t> Icorrect{0, 0, 0, 0};
        vector<size_t> Jcorrect{0, 0, 0, 0};
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

    SUBCASE("put")
    {
        vector<size_t> Icorrect{0, 1, 2, 0};
        vector<size_t> Jcorrect{0, 1, 2, 1};
        vector<double> Xcorrect{10.0, 11.0, 12.0, 4.0};

        trip->put(0, 0, 10.0);
        trip->put(1, 1, 11.0);
        trip->put(2, 2, 12.0);
        trip->put(0, 1, 4.0);

        CHECK(trip->pos == 4);
        CHECK(equal_vectors(trip->I, Icorrect));
        CHECK(equal_vectors(trip->J, Jcorrect));
        CHECK(equal_vectors_tol(trip->X, Xcorrect, 1e-15));
    }

    SUBCASE("put: exception")
    {
        CHECK_THROWS_WITH(trip->put(-1, 0, 0.0), "triplet_put: index of row is outside range");
        CHECK_THROWS_WITH(trip->put(3, 0, 0.0), "triplet_put: index of row is outside range");
        CHECK_THROWS_WITH(trip->put(0, -1, 0.0), "triplet_put: index of column is outside range");
        CHECK_THROWS_WITH(trip->put(0, 3, 0.0), "triplet_put: index of column is outside range");

        trip->put(0, 0, 0.0);
        trip->put(0, 0, 0.0);
        trip->put(0, 0, 0.0);
        trip->put(0, 0, 0.0);

        CHECK_THROWS_WITH(trip->put(0, 0, 0.0), "triplet_put: max number of items has been exceeded");
    }
}
