#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <vector>

#include "../check/index.h"
#include "../util/doctest.h"
#include "sparse_blas.h"

using namespace std;

TEST_CASE("sparse_blas") {
    SUBCASE("sp_mat_vec_mul: default options") {
        // { 1.0,  2.0,  3.0},
        // { 0.1,  0.2,  0.3},
        // {10.0, 20.0, 30.0},
        auto trip = SparseTriplet::make_new(FULL_MATRIX, 3, 9);
        trip->put(0, 0, 1);
        trip->put(0, 1, 2);
        trip->put(0, 2, 3);

        trip->put(1, 0, 0.1);
        trip->put(1, 1, 0.2);
        trip->put(1, 2, 0.3);

        trip->put(2, 0, 10);
        trip->put(2, 1, 20);
        trip->put(2, 2, 30);

        vector<double> u = {0.1, 0.2, 0.3};
        vector<double> v(trip->dimension);
        vector<double> v_correct{1.4, 0.14, 14};

        sp_mat_vec_mul(v, 1.0, trip, u);
        CHECK(equal_vectors_tol(v, v_correct, 1e-15));
    }

    SUBCASE("sp_mat_vec_mul: check_sizes = true") {
        auto trip = SparseTriplet::make_new(FULL_MATRIX, 5, 15);
        vector<double> u_correct(5);
        vector<double> v_correct(5);
        vector<double> u_wrong(3);
        vector<double> v_wrong(3);
        CHECK_THROWS_WITH(sp_mat_vec_mul(v_wrong, 1.0, trip, u_correct), "sp_mat_vec_mul: size of v must be equal to the dimension of a");
        CHECK_THROWS_WITH(sp_mat_vec_mul(v_correct, 1.0, trip, u_wrong), "sp_mat_vec_mul: size of u must be equal to the dimension of a");
    }

    SUBCASE("sp_mat_vec_mul: fill_zeros = false") {
        // {0.1, 0.2, 0.3},
        // {1.0, 0.2, 0.3},
        // {2.0, 0.2, 0.3},
        auto trip = SparseTriplet::make_new(FULL_MATRIX, 3, 9);
        trip->put(0, 0, 0.1);
        trip->put(0, 1, 0.2);
        trip->put(0, 2, 0.3);

        trip->put(1, 0, 1.0);
        trip->put(1, 1, 0.2);
        trip->put(1, 2, 0.3);

        trip->put(2, 0, 2.0);
        trip->put(2, 1, 0.2);
        trip->put(2, 2, 0.3);

        vector<double> u = {20, 10, 30};
        vector<double> v = {6, 2, 4};
        vector<double> v_correct{12.5, 17.5, 29.5};
        sp_mat_vec_mul(v, 0.5, trip, u, true, false);
        CHECK(equal_vectors_tol(v, v_correct, 1e-15));
    }

    SUBCASE("sp_matvecmul: lower_diagonal") {
        // {2, 1, 1, 3, 2},
        // {1, 2, 2, 1, 1},
        // {1, 2, 9, 1, 5},
        // {3, 1, 1, 7, 1},
        // {2, 1, 5, 1, 8},
        auto trip = SparseTriplet::make_new(LOWER_TRIANGULAR, 5, 15);

        trip->put(0, 0, 2.0);
        trip->put(1, 1, 2.0);
        trip->put(2, 2, 9.0);
        trip->put(3, 3, 7.0);
        trip->put(4, 4, 8.0);

        trip->put(1, 0, 1.0);
        trip->put(2, 0, 1.0);
        trip->put(3, 0, 3.0);
        trip->put(4, 0, 2.0);

        trip->put(2, 1, 2.0);
        trip->put(3, 1, 1.0);
        trip->put(4, 1, 1.0);

        trip->put(3, 2, 1.0);
        trip->put(4, 2, 5.0);

        trip->put(4, 3, 1.0);

        vector<double> u = {
            -629.0 / 98.0,
            +237.0 / 49.0,
            -53.0 / 49.0,
            +62.0 / 49.0,
            +23.0 / 14.0,
        };

        vector<double> v(trip->dimension, 0.0);
        sp_mat_vec_mul(v, 1.0, trip, u);

        vector<double> v_correct{-2, 4, 3, -5, 1};
        CHECK(equal_vectors_tol(v, v_correct, 1e-14));
    }
}
