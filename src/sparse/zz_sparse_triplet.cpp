#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../util/doctest.h"
#include "../check/check.h"
#include "sparse_triplet.h"
#include <vector>
using namespace std;

TEST_CASE("testing SparseTriplet (put)")
{
    SUBCASE("default values")
    {
        auto trip = SparseTriplet::make_new(3, 3, 4);

        vector<MUMPS_INT> Icorrect{0, 0, 0, 0};
        vector<MUMPS_INT> Jcorrect{0, 0, 0, 0};
        vector<double> Xcorrect{0.0, 0.0, 0.0, 0.0};

        CHECK(trip->m == 3);
        CHECK(trip->n == 3);
        CHECK(trip->pos == 0);
        CHECK(trip->max == 4);
        CHECK(trip->symmetric == false);
        CHECK(trip->I.size() == 4);
        CHECK(trip->J.size() == 4);
        CHECK(trip->X.size() == 4);
        CHECK(equal_vectors(trip->I, Icorrect));
        CHECK(equal_vectors(trip->J, Jcorrect));
        CHECK(equal_vectors_tol(trip->X, Xcorrect, 1e-15));
    }

    SUBCASE("put")
    {
        auto trip = SparseTriplet::make_new(3, 3, 4);

        vector<MUMPS_INT> Icorrect{0, 1, 2, 0};
        vector<MUMPS_INT> Jcorrect{0, 1, 2, 1};
        vector<double> Xcorrect{10.0, 11.0, 12.0, 4.0};

        trip->put(0, 0, 10.0);
        trip->put(1, 1, 11.0);
        trip->put(2, 2, 12.0);
        trip->put(0, 1, 4.0);

        CHECK(trip->pos == 4);
        CHECK(equal_vectors(trip->I, Icorrect));
        CHECK(equal_vectors(trip->J, Jcorrect));
        CHECK(equal_vectors_tol(trip->X, Xcorrect, 1e-15));
    }

    SUBCASE("put: onebased")
    {
        bool onebased = true;
        auto trip = SparseTriplet::make_new(3, 3, 4, onebased);

        vector<MUMPS_INT> Icorrect{1, 2, 3, 1};
        vector<MUMPS_INT> Jcorrect{1, 2, 3, 2};
        vector<double> Xcorrect{10.0, 11.0, 12.0, 4.0};

        trip->put(0, 0, 10.0);
        trip->put(1, 1, 11.0);
        trip->put(2, 2, 12.0);
        trip->put(0, 1, 4.0);

        CHECK(trip->pos == 4);
        CHECK(equal_vectors(trip->I, Icorrect));
        CHECK(equal_vectors(trip->J, Jcorrect));
        CHECK(equal_vectors_tol(trip->X, Xcorrect, 1e-15));
    }

    SUBCASE("put: exceptions")
    {
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

    SUBCASE("partition_by_nnz: exceptions")
    {
        auto trip = SparseTriplet::make_new(3, 3, 4);
        CHECK_THROWS_WITH(trip->partition_by_nnz(-1, 1), "SparseTriplet::partition_by_nnz: mpi_rank must be greater than or equal to 0");
        CHECK_THROWS_WITH(trip->partition_by_nnz(0, 0), "SparseTriplet::partition_by_nnz: mpi_size must be greater than or equal to 1");
        CHECK_THROWS_WITH(trip->partition_by_nnz(2, 1), "SparseTriplet::partition_by_nnz: mpi_rank must be smaller than mpi_size");
    }

    SUBCASE("partition_by_nnz")
    {
        bool onebased = true;
        auto trip = SparseTriplet::make_new(5, 5, 12, onebased);
        trip->put(0, 0, +2.0);
        trip->put(1, 0, +3.0);
        trip->put(0, 1, +3.0);
        trip->put(2, 1, -1.0);
        trip->put(4, 1, +4.0);
        trip->put(1, 2, +4.0);
        trip->put(2, 2, -3.0);
        trip->put(3, 2, +1.0);
        trip->put(4, 2, +2.0);
        trip->put(2, 3, +2.0);
        trip->put(1, 4, +6.0);
        trip->put(4, 4, +1.0);

        auto trip_0 = trip->partition_by_nnz(0, 2);
        auto trip_1 = trip->partition_by_nnz(1, 2);

        vector<MUMPS_INT> Icorrect_0 = {1, 2, 1, 3, 5, 2};
        vector<MUMPS_INT> Jcorrect_0 = {1, 1, 2, 2, 2, 3};
        vector<double> Xcorrect_0 = {2, 3, 3, -1, 4, 4};

        CHECK(trip_0->onebased == trip->onebased);
        CHECK(trip_0->symmetric == trip->symmetric);
        CHECK(equal_vectors(trip_0->I, Icorrect_0) == true);
        CHECK(equal_vectors(trip_0->J, Jcorrect_0) == true);
        CHECK(equal_vectors_tol(trip_0->X, Xcorrect_0, 1e-15) == true);

        vector<MUMPS_INT> Icorrect_1 = {3, 4, 5, 3, 2, 5};
        vector<MUMPS_INT> Jcorrect_1 = {3, 3, 3, 4, 5, 5};
        vector<double> Xcorrect_1 = {-3, 1, 2, 2, 6, 1};

        CHECK(trip_1->onebased == trip->onebased);
        CHECK(trip_1->symmetric == trip->symmetric);
        CHECK(equal_vectors(trip_1->I, Icorrect_1) == true);
        CHECK(equal_vectors(trip_1->J, Jcorrect_1) == true);
        CHECK(equal_vectors_tol(trip_1->X, Xcorrect_1, 1e-15) == true);
    }
}
