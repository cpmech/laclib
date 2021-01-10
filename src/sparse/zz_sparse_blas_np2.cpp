#include "../util/doctest_mpi.h"
#include "../check/check.h"
#include "../mpiaux/mpiaux.h"
#include "sparse_blas.h"
#include <vector>
using namespace std;

MPI_TEST_CASE("testing sparse solver MUMPS (NP2)", 2)
{
    SUBCASE("sp_matvecmul with SparseTriplet")
    {
        auto mpi = MpiAux::make_new();

        size_t m = 3;
        size_t n = 5;

        std::unique_ptr<SparseTriplet> trip;
        std::vector<double> v_correct(m, 0.0);

        if (mpi.rank() == 0)
        {
            trip = SparseTriplet::make_new(m, n, 10);
            trip->put_zero_based(0, 0, 1);
            trip->put_zero_based(0, 1, 2);
            trip->put_zero_based(0, 2, 3);
            trip->put_zero_based(0, 3, 4);
            trip->put_zero_based(0, 4, 5);
            trip->put_zero_based(2, 0, 10);
            trip->put_zero_based(2, 1, 20);
            trip->put_zero_based(2, 2, 30);
            trip->put_zero_based(2, 3, 40);
            trip->put_zero_based(2, 4, 50);
            v_correct[0] = 5.5;
            v_correct[2] = 55.0;
        }
        else
        {
            trip = SparseTriplet::make_new(3, 5, 5);
            trip->put_zero_based(1, 0, 0.1);
            trip->put_zero_based(1, 1, 0.2);
            trip->put_zero_based(1, 2, 0.3);
            trip->put_zero_based(1, 3, 0.4);
            trip->put_zero_based(1, 4, 0.5);
            v_correct[1] = 0.55;
        }

        vector<double> u = {0.1, 0.2, 0.3, 0.4, 0.5};
        vector<double> v(m, 1234.0);

        sp_matvecmul(v, 1.0, trip, u, true, true);
        CHECK(equal_vectors_tol(v, v_correct, 1e-15));
    }
}
