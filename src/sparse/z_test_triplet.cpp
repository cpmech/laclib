#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../util/doctest.h"
#include "../check/equal_vectors.h"
#include "triplet.h"
#include <vector>
using namespace std;

TEST_CASE("testing Triplet")
{
    auto T = triplet_new(3, 3, 4);

    REQUIRE(T->pos == 0);
    REQUIRE(T->max == 4);

    SUBCASE("triplet_new")
    {
        vector<size_t> Icorrect{0, 0, 0, 0};
        vector<size_t> Jcorrect{0, 0, 0, 0};
        vector<double> Xcorrect{0.0, 0.0, 0.0, 0.0};

        CHECK(T->m == 3);
        CHECK(T->n == 3);
        CHECK(T->pos == 0);
        CHECK(T->max == 4);
        CHECK(T->I.size() == 4);
        CHECK(T->J.size() == 4);
        CHECK(T->X.size() == 4);
        CHECK(equal_vectors(T->I, Icorrect));
        CHECK(equal_vectors(T->J, Jcorrect));
        CHECK(equal_vectors_tol(T->X, Xcorrect, 1e-15));
    }

    SUBCASE("put")
    {
        vector<size_t> Icorrect{0, 1, 2, 0};
        vector<size_t> Jcorrect{0, 1, 2, 1};
        vector<double> Xcorrect{10.0, 11.0, 12.0, 4.0};

        T->put(0, 0, 10.0);
        T->put(1, 1, 11.0);
        T->put(2, 2, 12.0);
        T->put(0, 1, 4.0);

        CHECK(T->pos == 4);
        CHECK(equal_vectors(T->I, Icorrect));
        CHECK(equal_vectors(T->J, Jcorrect));
        CHECK(equal_vectors_tol(T->X, Xcorrect, 1e-15));
    }

    SUBCASE("put: exception")
    {
        CHECK_THROWS_WITH(T->put(-1, 0, 0.0), "triplet_put: index of row is outside range");
        CHECK_THROWS_WITH(T->put(3, 0, 0.0), "triplet_put: index of row is outside range");
        CHECK_THROWS_WITH(T->put(0, -1, 0.0), "triplet_put: index of column is outside range");
        CHECK_THROWS_WITH(T->put(0, 3, 0.0), "triplet_put: index of column is outside range");

        T->put(0, 0, 0.0);
        T->put(0, 0, 0.0);
        T->put(0, 0, 0.0);
        T->put(0, 0, 0.0);

        CHECK_THROWS_WITH(T->put(0, 0, 0.0), "triplet_put: max number of items has been exceeded");
    }
}
