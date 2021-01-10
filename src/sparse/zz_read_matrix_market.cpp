#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../util/doctest.h"
#include "../util/path_tools.h"
#include "../util/print_vector.h"
#include "../check/check.h"
#include "read_matrix_market.h"
#include <vector>
using namespace std;

TEST_CASE("read_matrix_market")
{
    auto data_path = path_get_current() + "/../../../data/sparse-matrix/";

    SUBCASE("cannot open file")
    {
        CHECK_THROWS_WITH(read_matrix_market("invalid.mtx"), "read_matrix_market: cannot open file");
    }

    SUBCASE("read sparse-matrix bad")
    {
        auto s = data_path + "bad";
        CHECK_THROWS_WITH(read_matrix_market(s + "1.mtx"), "read_matrix_market: number of tokens in the header is incorrect");
        CHECK_THROWS_WITH(read_matrix_market(s + "2.mtx"), "read_matrix_market: option must be \"matrix\"");
        CHECK_THROWS_WITH(read_matrix_market(s + "3.mtx"), "read_matrix_market: type must be \"coordinate\"");
        CHECK_THROWS_WITH(read_matrix_market(s + "4.mtx"), "read_matrix_market: number kind must be \"real\"");
        CHECK_THROWS_WITH(read_matrix_market(s + "5.mtx"), "read_matrix_market: matrix must be \"general\" or \"symmetric\"");
        CHECK_THROWS_WITH(read_matrix_market(s + "6.mtx"), "read_matrix_market: cannot parse the dimensions (m,n,nnz)");
        CHECK_THROWS_WITH(read_matrix_market(s + "7.mtx"), "read_matrix_market: cannot parse the dimensions (m,n,nnz)");
        CHECK_THROWS_WITH(read_matrix_market(s + "8.mtx"), "read_matrix_market: cannot parse the values (i,j,x)");
        CHECK_THROWS_WITH(read_matrix_market(s + "9.mtx"), "read_matrix_market: cannot parse the values (i,j,x)");
    }

    SUBCASE("read sparse-matrix ok1")
    {
        auto mtx = data_path + "ok1.mtx";
        auto trip = read_matrix_market(mtx);

        vector<MUMPS_INT> Icorrect = {0, 1, 0, 2, 4, 1, 2, 3, 4, 2, 1, 4};
        vector<MUMPS_INT> Jcorrect = {0, 0, 1, 1, 1, 2, 2, 2, 2, 3, 4, 4};
        vector<double> Xcorrect = {2, 3, 3, -1, 4, 4, -3, 1, 2, 2, 6, 1};

        CHECK(trip->symmetric == false);
        CHECK(equal_vectors(trip->I, Icorrect) == true);
        CHECK(equal_vectors(trip->J, Jcorrect) == true);
        CHECK(equal_vectors_tol(trip->X, Xcorrect, 1e-15) == true);
    }

    SUBCASE("read sparse-matrix ok2; onebased")
    {
        auto mtx = data_path + "ok2.mtx";
        bool onebased = true;
        auto trip = read_matrix_market(mtx, onebased);

        vector<MUMPS_INT> Icorrect = {1, 2, 3, 4, 5, 1, 1, 1, 1, 2, 2, 2, 3, 3, 4};
        vector<MUMPS_INT> Jcorrect = {1, 2, 3, 4, 5, 2, 3, 4, 5, 3, 4, 5, 4, 5, 5};
        vector<double> Xcorrect = {2, 2, 9, 7, 8, 1, 1, 3, 2, 2, 1, 1, 1, 5, 1};

        CHECK(trip->symmetric == true);
        CHECK(equal_vectors(trip->I, Icorrect) == true);
        CHECK(equal_vectors(trip->J, Jcorrect) == true);
        CHECK(equal_vectors_tol(trip->X, Xcorrect, 1e-15) == true);
    }
}
