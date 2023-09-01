#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <vector>

#include "../check/index.h"
#include "../sparse/coo_matrix.h"
#include "../util/doctest.h"
#include "stats.h"
using namespace std;

TEST_CASE("Stats") {
    SUBCASE("make_new") {
        // | 1  3 -2 |
        // | 3  5  6 |
        // | 2  4  3 |
        auto trip = SparseTriplet::make_new(FULL_MATRIX, 3, 9);
        trip->put(0, 0, 1.0);
        trip->put(0, 1, 3.0);
        trip->put(0, 2, -2.0);
        trip->put(1, 0, 3.0);
        trip->put(1, 1, 5.0);
        trip->put(1, 2, 6.0);
        trip->put(2, 0, 2.0);
        trip->put(2, 1, 4.0);
        trip->put(2, 2, 3.0);

        auto x = vector<double>{-15.0, 8.0, 2.0};
        auto rhs = vector<double>{5.0, 7.0, 8.0};

        auto stats = Stats::make_new(trip, x, rhs);

        CHECK(stats->max_abs_a == 6);
        CHECK(stats->max_abs_ax == 8);
        CHECK(stats->max_abs_diff == 0);
        CHECK(stats->relative_error == 0);
        CHECK(stats->nanoseconds > 0);
    }
}
