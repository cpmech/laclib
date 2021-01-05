#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../util/doctest.h"
#include "../util/path_tools.h"
#include "../check/check.h"
#include "read_matrix_for_mumps.h"
#include <vector>
using namespace std;

TEST_CASE("read_matrix_for_mumps")
{
    auto data_path = path_get_current() + "/../../../data/sparse-matrix/";

    vector<MUMPS_INT> Icorrect = {1, 2, 1, 3, 5, 2, 3, 4, 5, 3, 2, 5};
    vector<MUMPS_INT> Jcorrect = {1, 1, 2, 2, 2, 3, 3, 3, 3, 4, 5, 5};
    vector<double> Xcorrect = {2, 3, 3, -1, 4, 4, -3, 1, 2, 2, 6, 1};

    SUBCASE("cannot open file")
    {
        CHECK_THROWS_WITH(read_matrix_for_mumps("invalid.mtx"), "read_matrix_for_mumps: cannot open file");
    }

    SUBCASE("read sparse-matrix bad")
    {
        auto s = data_path + "bad";
        CHECK_THROWS_WITH(read_matrix_for_mumps(s + "1.mtx"), "read_matrix_for_mumps: number of tokens in the header is incorrect");
        CHECK_THROWS_WITH(read_matrix_for_mumps(s + "2.mtx"), "read_matrix_for_mumps: option must be \"matrix\"");
        CHECK_THROWS_WITH(read_matrix_for_mumps(s + "3.mtx"), "read_matrix_for_mumps: type must be \"coordinate\"");
        CHECK_THROWS_WITH(read_matrix_for_mumps(s + "4.mtx"), "read_matrix_for_mumps: number kind must be \"real\"");
        CHECK_THROWS_WITH(read_matrix_for_mumps(s + "5.mtx"), "read_matrix_for_mumps: matrix must be \"general\" or \"symmetric\"");
        CHECK_THROWS_WITH(read_matrix_for_mumps(s + "6.mtx"), "read_matrix_for_mumps: cannot parse the dimensions (m,n,nnz)");
        CHECK_THROWS_WITH(read_matrix_for_mumps(s + "7.mtx"), "read_matrix_for_mumps: cannot parse the dimensions (m,n,nnz)");
        CHECK_THROWS_WITH(read_matrix_for_mumps(s + "8.mtx"), "read_matrix_for_mumps: cannot parse the values (i,j,x)");
        CHECK_THROWS_WITH(read_matrix_for_mumps(s + "9.mtx"), "read_matrix_for_mumps: cannot parse the values (i,j,x)");
    }

    SUBCASE("read sparse-matrix ok1")
    {
        auto mtx = data_path + "ok1.mtx";
        auto trip = read_matrix_for_mumps(mtx);

        CHECK(trip->symmetric == false);
        CHECK(equal_vectors(trip->I, Icorrect) == true);
        CHECK(equal_vectors(trip->J, Jcorrect) == true);
        CHECK(equal_vectors_tol(trip->X, Xcorrect, 1e-15) == true);
    }
}