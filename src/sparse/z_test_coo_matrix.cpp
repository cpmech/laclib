#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <vector>

#include "../check/index.h"
#include "../util/doctest.h"
#include "coo_matrix.h"

#define _SUBCASE(name) if (false)

using namespace std;

TEST_CASE("testing SparseTriplet") {
    SUBCASE("make_new works with default values") {
        auto trip = SparseTriplet::make_new(FULL_MATRIX, 3, 4);

        vector<INT> I_correct{0, 0, 0, 0};
        vector<INT> J_correct{0, 0, 0, 0};
        vector<double> X_correct{0.0, 0.0, 0.0, 0.0};

        CHECK(trip->layout == FULL_MATRIX);
        CHECK(trip->dimension == 3);
        CHECK(trip->pos == 0);
        CHECK(trip->max == 4);
        CHECK(trip->indices_i.size() == 4);
        CHECK(trip->indices_j.size() == 4);
        CHECK(trip->values_aij.size() == 4);
        CHECK(equal_vectors(trip->indices_i, I_correct));
        CHECK(equal_vectors(trip->indices_j, J_correct));
        CHECK(equal_vectors_tol(trip->values_aij, X_correct, 1e-15));
    }

    SUBCASE("put works") {
        auto trip = SparseTriplet::make_new(FULL_MATRIX, 3, 4);

        vector<INT> I_correct{0, 1, 2, 0};
        vector<INT> J_correct{0, 1, 2, 1};
        vector<double> X_correct{10.0, 11.0, 12.0, 4.0};

        trip->put(0, 0, 10.0);
        trip->put(1, 1, 11.0);
        trip->put(2, 2, 12.0);
        trip->put(0, 1, 4.0);

        CHECK(trip->pos == 4);
        CHECK(equal_vectors(trip->indices_i, I_correct));
        CHECK(equal_vectors(trip->indices_j, J_correct));
        CHECK(equal_vectors_tol(trip->values_aij, X_correct, 1e-15));
    }

    SUBCASE("put works with duplicates") {
        size_t max = 6;
        auto trip = SparseTriplet::make_new(FULL_MATRIX, 3, max);

        vector<INT> I_correct{0, 1, 2, 0, 0, 2};
        vector<INT> J_correct{0, 1, 2, 1, 0, 2};
        vector<double> X_correct{5.0, 11.0, 6.0, 4.0, 5.0, 6.0};

        trip->put(0, 0, 5.0);
        trip->put(1, 1, 11.0);
        trip->put(2, 2, 6.0);
        trip->put(0, 1, 4.0);
        trip->put(0, 0, 5.0); // << duplicate
        trip->put(2, 2, 6.0); // << duplicate

        CHECK(trip->pos == 6);
        CHECK(equal_vectors(trip->indices_i, I_correct));
        CHECK(equal_vectors(trip->indices_j, J_correct));
        CHECK(equal_vectors_tol(trip->values_aij, X_correct, 1e-15));
    }

    SUBCASE("put handles exceptions") {
        auto trip = SparseTriplet::make_new(FULL_MATRIX, 3, 4);

        CHECK_THROWS_WITH(trip->put(-1, 0, 10.0), "SparseTriplet::put: index of row is outside range");
        CHECK_THROWS_WITH(trip->put(3, 0, 10.0), "SparseTriplet::put: index of row is outside range");
        CHECK_THROWS_WITH(trip->put(0, -1, 11.0), "SparseTriplet::put: index of column is outside range");
        CHECK_THROWS_WITH(trip->put(0, 3, 11.0), "SparseTriplet::put: index of column is outside range");

        trip->put(0, 0, 1);
        trip->put(0, 1, 2);
        trip->put(1, 0, 3);
        trip->put(1, 1, 4);

        CHECK_THROWS_WITH(trip->put(0, 0, 4.0), "SparseTriplet::put: max number of items has been exceeded");
    }
}
