#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <vector>

#include "../check/check.h"
#include "../util/doctest.h"
#include "../util/print_vector.h"
#include "sparse_blas.h"
using namespace std;

TEST_CASE("sparse_blas") {
    SUBCASE("sp_matvecmul: default options") {
        // { 1.0,  2.0,  3.0,  4.0,  5.0},
        // { 0.1,  0.2,  0.3,  0.4,  0.5},
        // {10.0, 20.0, 30.0, 40.0, 50.0},
        auto trip = SparseTriplet::make_new(3, 5, 15);
        trip->put(0, 0, 1);
        trip->put(0, 1, 2);
        trip->put(0, 2, 3);
        trip->put(0, 3, 4);
        trip->put(0, 4, 5);

        trip->put(1, 0, 0.1);
        trip->put(1, 1, 0.2);
        trip->put(1, 2, 0.3);
        trip->put(1, 3, 0.4);
        trip->put(1, 4, 0.5);

        trip->put(2, 0, 10);
        trip->put(2, 1, 20);
        trip->put(2, 2, 30);
        trip->put(2, 3, 40);
        trip->put(2, 4, 50);

        vector<double> u = {0.1, 0.2, 0.3, 0.4, 0.5};
        vector<double> v(trip->m);
        vector<double> v_correct{5.5, 0.55, 55};

        sp_matvecmul(v, 1.0, trip, u);
        CHECK(equal_vectors_tol(v, v_correct, 1e-15));
    }

    SUBCASE("sp_matvecmul: check_sizes = true") {
        auto trip = SparseTriplet::make_new(3, 5, 15);
        vector<double> u = {0.1, 0.2, 0.3, 0.4, 0.5};
        vector<double> v(10);
        vector<double> vv(3);
        vector<double> uu = {0.1, 0.2, 0.3, 0.4, 0.5, 0.6};
        CHECK_THROWS_WITH(sp_matvecmul(v, 1.0, trip, u), "sp_matvecmul: size of v must be equal to the number of rows of a");
        CHECK_THROWS_WITH(sp_matvecmul(vv, 1.0, trip, uu), "sp_matvecmul: size of u must be equal to the number of columns of a");
    }

    SUBCASE("sp_matvecmul: fill_zeros = false") {
        // {0.1, 0.2, 0.3},
        // {1.0, 0.2, 0.3},
        // {2.0, 0.2, 0.3},
        // {3.0, 0.2, 0.3},
        auto trip = SparseTriplet::make_new(4, 3, 12);
        trip->put(0, 0, 0.1);
        trip->put(0, 1, 0.2);
        trip->put(0, 2, 0.3);

        trip->put(1, 0, 1.0);
        trip->put(1, 1, 0.2);
        trip->put(1, 2, 0.3);

        trip->put(2, 0, 2.0);
        trip->put(2, 1, 0.2);
        trip->put(2, 2, 0.3);

        trip->put(3, 0, 3.0);
        trip->put(3, 1, 0.2);
        trip->put(3, 2, 0.3);

        vector<double> u = {20, 10, 30};
        vector<double> v = {6, 2, 4, 8};
        vector<double> v_correct{12.5, 17.5, 29.5, 43.5};
        sp_matvecmul(v, 0.5, trip, u, true, false);
        CHECK(equal_vectors_tol(v, v_correct, 1e-15));
    }

    SUBCASE("sp_matvecmul: triplet is onebased") {
        // { 1.0,  2.0,  3.0,  4.0,  5.0},
        // { 0.1,  0.2,  0.3,  0.4,  0.5},
        // {10.0, 20.0, 30.0, 40.0, 50.0},
        bool onebased = true;
        auto trip = SparseTriplet::make_new(3, 5, 15, onebased);
        trip->put(0, 0, 1);
        trip->put(0, 1, 2);
        trip->put(0, 2, 3);
        trip->put(0, 3, 4);
        trip->put(0, 4, 5);

        trip->put(1, 0, 0.1);
        trip->put(1, 1, 0.2);
        trip->put(1, 2, 0.3);
        trip->put(1, 3, 0.4);
        trip->put(1, 4, 0.5);

        trip->put(2, 0, 10);
        trip->put(2, 1, 20);
        trip->put(2, 2, 30);
        trip->put(2, 3, 40);
        trip->put(2, 4, 50);

        vector<double> u = {0.1, 0.2, 0.3, 0.4, 0.5};
        vector<double> v(trip->m);
        vector<double> v_correct{5.5, 0.55, 55};

        sp_matvecmul(v, 1.0, trip, u);
        CHECK(equal_vectors_tol(v, v_correct, 1e-15));
    }

    SUBCASE("sp_matvecmul: triplet has symmetric = true") {
        // {2, 1, 1, 3, 2},
        // {1, 2, 2, 1, 1},
        // {1, 2, 9, 1, 5},
        // {3, 1, 1, 7, 1},
        // {2, 1, 5, 1, 8},
        bool onebased = false;
        bool symmetric = true;
        auto trip = SparseTriplet::make_new(5, 5, 15, onebased, symmetric);

        trip->put(0, 0, 2.0);
        trip->put(1, 1, 2.0);
        trip->put(2, 2, 9.0);
        trip->put(3, 3, 7.0);
        trip->put(4, 4, 8.0);

        trip->put(0, 1, 1.0);
        trip->put(0, 2, 1.0);
        trip->put(0, 3, 3.0);
        trip->put(0, 4, 2.0);

        trip->put(1, 2, 2.0);
        trip->put(1, 3, 1.0);
        trip->put(1, 4, 1.0);

        trip->put(2, 3, 1.0);
        trip->put(2, 4, 5.0);

        trip->put(3, 4, 1.0);

        vector<double> u = {
            -629.0 / 98.0,
            +237.0 / 49.0,
            -53.0 / 49.0,
            +62.0 / 49.0,
            +23.0 / 14.0,
        };

        vector<double> v(trip->m, 0.0);
        sp_matvecmul(v, 1.0, trip, u);

        print_vector("v", v);

        vector<double> v_correct{-2, 4, 3, -5, 1};
        CHECK(equal_vectors_tol(v, v_correct, 1e-14));
    }
}
