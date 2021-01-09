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
}
