#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <iostream>
#include <vector>

#include "../check/check.h"
#include "../util/doctest.h"
#include "../util/print_vector.h"
#include "sparse_triplet.h"

using namespace std;

TEST_CASE("testing SparseTriplet (put)") {
    SUBCASE("default values") {
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
        CHECK(trip->ij_to_pos.size() == 0);
    }

    SUBCASE("put") {
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
        auto trip = SparseTriplet::make_new(FULL_MATRIX, 3, max);

        vector<INT> I_correct{0, 1, 2, 0, /*extra; not used*/ 0, 0};
        vector<INT> J_correct{0, 1, 2, 1, /*extra; not used*/ 0, 0};
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

    SUBCASE("convert to csr works with small matrix") {
        // 1  2  .  .  .
        // 3  4  .  .  .
        // .  .  5  6  .
        // .  .  7  8  .
        // .  .  .  .  9
        auto trip = SparseTriplet::make_new(FULL_MATRIX, 5, 9);
        trip->put(4, 4, 9.0);
        trip->put(0, 0, 1.0);
        trip->put(1, 0, 3.0);
        trip->put(2, 2, 5.0);
        trip->put(2, 3, 6.0);
        trip->put(0, 1, 2.0);
        trip->put(3, 2, 7.0);
        trip->put(1, 1, 4.0);
        trip->put(3, 3, 8.0);

        auto csr = trip->to_csr(false);
        print_vector("p", csr.row_pointers);
        print_vector("j", csr.column_indices);
        print_vector("x", csr.values);

        vector<INT> correct_p{0, 2, 4, 6, 8, 9};
        vector<INT> correct_j{0, 1, 0, 1, 2, 3, 2, 3, 4};
        vector<double> correct_x{1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0};
        CHECK(equal_vectors(csr.row_pointers, correct_p));
        CHECK(equal_vectors(csr.column_indices, correct_j));
        CHECK(equal_vectors_tol(csr.values, correct_x, 1e-15));
    }
}
