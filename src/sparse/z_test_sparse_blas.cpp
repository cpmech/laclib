#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../util/doctest.h"
#include "../check/check.h"
#include "sparse_blas.h"
#include <vector>
using namespace std;

TEST_CASE("sparse_blas")
{
    SUBCASE("sp_matvecmul with TripletForMumps")
    {
        auto trip = TripletForMumps::make_new(3, 5, 15);
        trip->put_zero_based(0, 0, 1);
        trip->put_zero_based(0, 1, 2);
        trip->put_zero_based(0, 2, 3);
        trip->put_zero_based(0, 3, 4);
        trip->put_zero_based(0, 4, 5);
        trip->put_zero_based(1, 0, 0.1);
        trip->put_zero_based(1, 1, 0.2);
        trip->put_zero_based(1, 2, 0.3);
        trip->put_zero_based(1, 3, 0.4);
        trip->put_zero_based(1, 4, 0.5);
        trip->put_zero_based(2, 0, 10);
        trip->put_zero_based(2, 1, 20);
        trip->put_zero_based(2, 2, 30);
        trip->put_zero_based(2, 3, 40);
        trip->put_zero_based(2, 4, 50);

        vector<double> u = {0.1, 0.2, 0.3, 0.4, 0.5};
        vector<double> v(trip->m);
        vector<double> v_correct{5.5, 0.55, 55};

        sp_matvecmul(v, 1.0, trip, u);
        CHECK(equal_vectors_tol(v, v_correct, 1e-15));
    }

    SUBCASE("sp_matvecmul check_sizes")
    {
        auto trip = TripletForMumps::make_new(3, 5, 15);
        vector<double> u = {0.1, 0.2, 0.3, 0.4, 0.5};
        vector<double> v(10);
        vector<double> vv(3);
        vector<double> uu = {0.1, 0.2, 0.3, 0.4, 0.5, 0.6};
        CHECK_THROWS_WITH(sp_matvecmul(v, 1.0, trip, u), "size of v must be equal to the number of rows of a");
        CHECK_THROWS_WITH(sp_matvecmul(vv, 1.0, trip, uu), "size of u must be equal to the number of columns of a");
    }

    SUBCASE("sp_matvecmul fill_zeros = false")
    {
        /*
		{0.1, 0.2, 0.3},
		{1.0, 0.2, 0.3},
		{2.0, 0.2, 0.3},
		{3.0, 0.2, 0.3},
        */
        auto trip = TripletForMumps::make_new(4, 3, 12);
        trip->put_one_based(1, 1, 0.1);
        trip->put_one_based(1, 2, 0.2);
        trip->put_one_based(1, 3, 0.3);
        trip->put_one_based(2, 1, 1.0);
        trip->put_one_based(2, 2, 0.2);
        trip->put_one_based(2, 3, 0.3);
        trip->put_one_based(3, 1, 2.0);
        trip->put_one_based(3, 2, 0.2);
        trip->put_one_based(3, 3, 0.3);
        trip->put_one_based(4, 1, 3.0);
        trip->put_one_based(4, 2, 0.2);
        trip->put_one_based(4, 3, 0.3);

        vector<double> u = {20, 10, 30};
        vector<double> v = {6, 2, 4, 8};
        vector<double> v_correct{12.5, 17.5, 29.5, 43.5};
        sp_matvecmul(v, 0.5, trip, u, true, false);
        CHECK(equal_vectors_tol(v, v_correct, 1e-15));
    }
}
