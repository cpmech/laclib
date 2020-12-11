#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../util/doctest.h"
#include "../check/equal_vectors.h"
#include "triplet.h"
#include <vector>

TEST_CASE("testing Triplet")
{
    auto T = triplet_new(3, 3, 4);

    REQUIRE(T->pos == 0);
    REQUIRE(T->max == 4);

    SUBCASE("triplet_new")
    {
        triplet_print(T.get());

        std::vector<size_t> Icorrect{0, 0, 0, 0};
        std::vector<size_t> Jcorrect{0, 0, 0, 0};
        std::vector<double> Xcorrect{0.0, 0.0, 0.0, 0.0};

        CHECK(T->m == 3);
        CHECK(T->n == 3);
        CHECK(T->pos == 0);
        CHECK(T->max == 4);
        CHECK(T->I.size() == 4);
        CHECK(T->J.size() == 4);
        CHECK(T->X.size() == 4);
        CHECK(equal_int_vectors(T->I, Icorrect));
        CHECK(equal_int_vectors(T->J, Jcorrect));
        CHECK(equal_flt_vectors(T->X, Xcorrect, 1e-15));
    }

    SUBCASE("triplet_put")
    {
        std::vector<size_t> Icorrect{0, 1, 2, 0};
        std::vector<size_t> Jcorrect{0, 1, 2, 1};
        std::vector<double> Xcorrect{10.0, 11.0, 12.0, 4.0};

        triplet_put(T.get(), 0, 0, 10.0);
        triplet_put(T.get(), 1, 1, 11.0);
        triplet_put(T.get(), 2, 2, 12.0);
        triplet_put(T.get(), 0, 1, 4.0);

        CHECK(T->pos == 4);
        CHECK(equal_int_vectors(T->I, Icorrect));
        CHECK(equal_int_vectors(T->J, Jcorrect));
        CHECK(equal_flt_vectors(T->X, Xcorrect, 1e-15));
    }

    SUBCASE("triplet_put with exception")
    {
        CHECK_THROWS_WITH(triplet_put(T.get(), 3, 0, 0.0), "triplet_put: index of row is outside range");
        CHECK_THROWS_WITH(triplet_put(T.get(), 0, 3, 0.0), "triplet_put: index of column is outside range");

        triplet_put(T.get(), 0, 0, 0.0);
        triplet_put(T.get(), 0, 0, 0.0);
        triplet_put(T.get(), 0, 0, 0.0);
        triplet_put(T.get(), 0, 0, 0.0);

        CHECK_THROWS_WITH(triplet_put(T.get(), 0, 0, 0.0), "triplet_put: max number of items has been exceeded");
    }
}
