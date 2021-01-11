#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../util/doctest.h"
#include "../util/path_tools.h"
#include "../check/check.h"
#include "read_matrix_market.h"
#include <vector>
using namespace std;

TEST_CASE("read_matrix_market_part")
{
    auto data_path = path_get_current() + "/../../../data/sparse-matrix/";
    auto mtx = data_path + "ok1.mtx";

    SUBCASE("default => full")
    {
        bool onebased = false;
        auto trip = read_matrix_market_part(mtx, onebased);

        vector<MUMPS_INT> Icorrect = {0, 1, 0, 2, 4, 1, 2, 3, 4, 2, 1, 4};
        vector<MUMPS_INT> Jcorrect = {0, 0, 1, 1, 1, 2, 2, 2, 2, 3, 4, 4};
        vector<double> Xcorrect = {2, 3, 3, -1, 4, 4, -3, 1, 2, 2, 6, 1};

        CHECK(trip->symmetric == false);
        CHECK(equal_vectors(trip->I, Icorrect) == true);
        CHECK(equal_vectors(trip->J, Jcorrect) == true);
        CHECK(equal_vectors_tol(trip->X, Xcorrect, 1e-15) == true);
    }

    SUBCASE("by row")
    {
        bool onebased = false;
        auto trip_0 = read_matrix_market_part(mtx, onebased, 0, 2);
        auto trip_1 = read_matrix_market_part(mtx, onebased, 1, 2);

        vector<MUMPS_INT> Icorrect_0 = {0, 1, 0, 1, 1};
        vector<MUMPS_INT> Jcorrect_0 = {0, 0, 1, 2, 4};
        vector<double> Xcorrect_0 = {2, 3, 3, 4, 6};

        CHECK(equal_vectors(trip_0->I, Icorrect_0) == true);
        CHECK(equal_vectors(trip_0->J, Jcorrect_0) == true);
        CHECK(equal_vectors_tol(trip_0->X, Xcorrect_0, 1e-15) == true);

        vector<MUMPS_INT> Icorrect_1 = {2, 4, 2, 3, 4, 2, 4};
        vector<MUMPS_INT> Jcorrect_1 = {1, 1, 2, 2, 2, 3, 4};
        vector<double> Xcorrect_1 = {-1, 4, -3, 1, 2, 2, 1};

        CHECK(equal_vectors(trip_1->I, Icorrect_1) == true);
        CHECK(equal_vectors(trip_1->J, Jcorrect_1) == true);
        CHECK(equal_vectors_tol(trip_1->X, Xcorrect_1, 1e-15) == true);
    }

    SUBCASE("by nnz (and onebased)")
    {
        bool onebased = true;
        auto trip_0 = read_matrix_market_part(mtx, onebased, 0, 2, PARTITION_BY_NNZ);
        auto trip_1 = read_matrix_market_part(mtx, onebased, 1, 2, PARTITION_BY_NNZ);

        vector<MUMPS_INT> Icorrect_0 = {1, 2, 1, 3, 5, 2};
        vector<MUMPS_INT> Jcorrect_0 = {1, 1, 2, 2, 2, 3};
        vector<double> Xcorrect_0 = {2, 3, 3, -1, 4, 4};

        CHECK(equal_vectors(trip_0->I, Icorrect_0) == true);
        CHECK(equal_vectors(trip_0->J, Jcorrect_0) == true);
        CHECK(equal_vectors_tol(trip_0->X, Xcorrect_0, 1e-15) == true);

        vector<MUMPS_INT> Icorrect_1 = {3, 4, 5, 3, 2, 5};
        vector<MUMPS_INT> Jcorrect_1 = {3, 3, 3, 4, 5, 5};
        vector<double> Xcorrect_1 = {-3, 1, 2, 2, 6, 1};

        CHECK(equal_vectors(trip_1->I, Icorrect_1) == true);
        CHECK(equal_vectors(trip_1->J, Jcorrect_1) == true);
        CHECK(equal_vectors_tol(trip_1->X, Xcorrect_1, 1e-15) == true);
    }

    SUBCASE("by col")
    {
        bool onebased = false;
        auto trip_0 = read_matrix_market_part(mtx, onebased, 0, 2, PARTITION_BY_COL);
        auto trip_1 = read_matrix_market_part(mtx, onebased, 1, 2, PARTITION_BY_COL);

        vector<MUMPS_INT> Icorrect_0 = {0, 1, 0, 2, 4};
        vector<MUMPS_INT> Jcorrect_0 = {0, 0, 1, 1, 1};
        vector<double> Xcorrect_0 = {2, 3, 3, -1, 4};

        CHECK(equal_vectors(trip_0->I, Icorrect_0) == true);
        CHECK(equal_vectors(trip_0->J, Jcorrect_0) == true);
        CHECK(equal_vectors_tol(trip_0->X, Xcorrect_0, 1e-15) == true);

        vector<MUMPS_INT> Icorrect_1 = {1, 2, 3, 4, 2, 1, 4};
        vector<MUMPS_INT> Jcorrect_1 = {2, 2, 2, 2, 3, 4, 4};
        vector<double> Xcorrect_1 = {4, -3, 1, 2, 2, 6, 1};

        CHECK(equal_vectors(trip_1->I, Icorrect_1) == true);
        CHECK(equal_vectors(trip_1->J, Jcorrect_1) == true);
        CHECK(equal_vectors_tol(trip_1->X, Xcorrect_1, 1e-15) == true);
    }
}
