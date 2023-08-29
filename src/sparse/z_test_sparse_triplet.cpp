#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <vector>

#include "../check/check.h"
#include "../util/doctest.h"
#include "sparse_triplet.h"
using namespace std;

TEST_CASE("testing SparseTriplet (put)") {
    SUBCASE("default values") {
        auto trip = SparseTriplet::make_new(3, 3, 4);

        vector<MUMPS_INT> I_correct{0, 0, 0, 0};
        vector<MUMPS_INT> J_correct{0, 0, 0, 0};
        vector<double> X_correct{0.0, 0.0, 0.0, 0.0};

        CHECK(trip->m == 3);
        CHECK(trip->n == 3);
        CHECK(trip->pos == 0);
        CHECK(trip->max == 4);
        CHECK(trip->symmetric == false);
        CHECK(trip->I.size() == 4);
        CHECK(trip->J.size() == 4);
        CHECK(trip->X.size() == 4);
        CHECK(equal_vectors(trip->I, I_correct));
        CHECK(equal_vectors(trip->J, J_correct));
        CHECK(equal_vectors_tol(trip->X, X_correct, 1e-15));
    }

    SUBCASE("put") {
        auto trip = SparseTriplet::make_new(3, 3, 4);

        vector<MUMPS_INT> I_correct{0, 1, 2, 0};
        vector<MUMPS_INT> J_correct{0, 1, 2, 1};
        vector<double> X_correct{10.0, 11.0, 12.0, 4.0};

        trip->put(0, 0, 10.0);
        trip->put(1, 1, 11.0);
        trip->put(2, 2, 12.0);
        trip->put(0, 1, 4.0);

        CHECK(trip->pos == 4);
        CHECK(equal_vectors(trip->I, I_correct));
        CHECK(equal_vectors(trip->J, J_correct));
        CHECK(equal_vectors_tol(trip->X, X_correct, 1e-15));
    }

    SUBCASE("put: one_based") {
        bool one_based = true;
        auto trip = SparseTriplet::make_new(3, 3, 4, one_based);

        vector<MUMPS_INT> I_correct{1, 2, 3, 1};
        vector<MUMPS_INT> J_correct{1, 2, 3, 2};
        vector<double> X_correct{10.0, 11.0, 12.0, 4.0};

        trip->put(0, 0, 10.0);
        trip->put(1, 1, 11.0);
        trip->put(2, 2, 12.0);
        trip->put(0, 1, 4.0);

        CHECK(trip->pos == 4);
        CHECK(equal_vectors(trip->I, I_correct));
        CHECK(equal_vectors(trip->J, J_correct));
        CHECK(equal_vectors_tol(trip->X, X_correct, 1e-15));
    }

    SUBCASE("put: exceptions") {
        auto trip = SparseTriplet::make_new(3, 3, 4);

        CHECK_THROWS_WITH(trip->put(-1, 0, 10.0), "SparseTriplet::put: index of row is outside range");
        CHECK_THROWS_WITH(trip->put(3, 0, 10.0), "SparseTriplet::put: index of row is outside range");
        CHECK_THROWS_WITH(trip->put(0, -1, 11.0), "SparseTriplet::put: index of column is outside range");
        CHECK_THROWS_WITH(trip->put(0, 3, 11.0), "SparseTriplet::put: index of column is outside range");

        trip->put(0, 0, 1);
        trip->put(0, 0, 2);
        trip->put(0, 0, 3);
        trip->put(0, 0, 4);

        CHECK_THROWS_WITH(trip->put(0, 0, 4.0), "SparseTriplet::put: max number of items has been exceeded");
    }
}
