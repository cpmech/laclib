#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <iostream>
#include <vector>

#include "../check/check.h"
#include "../util/doctest.h"
#include "sparse_triplet.h"

using namespace std;

TEST_CASE("testing SparseTriplet (put)") {
    SUBCASE("default values") {
        auto trip = SparseTriplet::make_new(false, 3, 4);

        vector<size_t> I_correct{0, 0, 0, 0};
        vector<size_t> J_correct{0, 0, 0, 0};
        vector<double> X_correct{0.0, 0.0, 0.0, 0.0};

        CHECK(trip->lower_triangular == false);
        CHECK(trip->dimension == 3);
        CHECK(trip->pos == 0);
        CHECK(trip->max == 4);
        CHECK(trip->indices_i.size() == 4);
        CHECK(trip->indices_j.size() == 4);
        CHECK(trip->values_aij.size() == 4);
        CHECK(equal_vectors(trip->indices_i, I_correct));
        CHECK(equal_vectors(trip->indices_j, J_correct));
        CHECK(equal_vectors_tol(trip->values_aij, X_correct, 1e-15));
        CHECK(trip->ij_to_pos.size() == 0);
    }

    SUBCASE("put") {
        auto trip = SparseTriplet::make_new(false, 3, 4);

        vector<size_t> I_correct{0, 1, 2, 0};
        vector<size_t> J_correct{0, 1, 2, 1};
        vector<double> X_correct{10.0, 11.0, 12.0, 4.0};

        trip->put(0, 0, 10.0);
        trip->put(1, 1, 11.0);
        trip->put(2, 2, 12.0);
        trip->put(0, 1, 4.0);

        CHECK(trip->pos == 4);
        CHECK(equal_vectors(trip->indices_i, I_correct));
        CHECK(equal_vectors(trip->indices_j, J_correct));
        CHECK(equal_vectors_tol(trip->values_aij, X_correct, 1e-15));

        CHECK(trip->ij_to_pos.size() == 4);
        if (false) {
            for (const auto &[key, value] : trip->ij_to_pos) {
                const auto [i, j] = key;
                std::cout << "(" << i << "," << j << ") → " << value << "\n";
            }
        }
        CHECK(trip->ij_to_pos.at({0, 0}) == 0);
        CHECK(trip->ij_to_pos.at({1, 1}) == 1);
        CHECK(trip->ij_to_pos.at({2, 2}) == 2);
        CHECK(trip->ij_to_pos.at({0, 1}) == 3);
    }

    SUBCASE("put: with duplicates") {
        size_t max = 6; // could also be 4, but suppose we don't know about the duplicates
        auto trip = SparseTriplet::make_new(false, 3, max);

        vector<size_t> I_correct{0, 1, 2, 0, /*extra; not used*/ 0, 0};
        vector<size_t> J_correct{0, 1, 2, 1, /*extra; not used*/ 0, 0};
        vector<double> X_correct{10.0, 11.0, 12.0, 4.0, /*extra; not used*/ 0.0, 0.0};

        trip->put(0, 0, 5.0);
        trip->put(0, 0, 5.0); // << duplicate
        trip->put(1, 1, 11.0);
        trip->put(2, 2, 6.0);
        trip->put(2, 2, 6.0); // << duplicate
        trip->put(0, 1, 4.0);

        CHECK(trip->pos == 4);
        CHECK(equal_vectors(trip->indices_i, I_correct));
        CHECK(equal_vectors(trip->indices_j, J_correct));
        CHECK(equal_vectors_tol(trip->values_aij, X_correct, 1e-15));

        CHECK(trip->ij_to_pos.size() == 4);
        if (false) {
            for (const auto &[key, value] : trip->ij_to_pos) {
                const auto [i, j] = key;
                std::cout << "(" << i << "," << j << ") → " << value << "\n";
            }
        }
        CHECK(trip->ij_to_pos.at({0, 0}) == 0);
        CHECK(trip->ij_to_pos.at({1, 1}) == 1);
        CHECK(trip->ij_to_pos.at({2, 2}) == 2);
        CHECK(trip->ij_to_pos.at({0, 1}) == 3);
    }

    SUBCASE("put: exceptions") {
        auto trip = SparseTriplet::make_new(false, 3, 4);

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
