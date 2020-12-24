#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../util/doctest.h"
#include "../util/path_tools.h"
#include "../check/check.h"
#include "read_matrix_for_mumps.h"
#include <vector>
using namespace std;

TEST_CASE("read_matrix_for_mumps")
{
    SUBCASE("cannot open file")
    {
        CHECK_THROWS_WITH(read_matrix_for_mumps("invalid.mtx"), "read_matrix_for_mumps: cannot open file");
    }

    SUBCASE("read sparse-matrix ok1")
    {
        vector<MUMPS_INT> Icorrect = {1, 2, 1, 3, 5, 2, 3, 4, 5, 3, 2, 5};
        vector<MUMPS_INT> Jcorrect = {1, 1, 2, 2, 2, 3, 3, 3, 3, 4, 5, 5};
        vector<double> Xcorrect = {2, 3, 3, -1, 4, 4, -3, 1, 2, 2, 6, 1};

        auto data_path = path_get_current() + "/../../../data";
        auto mtx_path = data_path + "/sparse-matrix/ok1.mtx";
        auto res = read_matrix_for_mumps(mtx_path);

        CHECK(equal_vectors(res.trip.get()->I, Icorrect) == true);
        CHECK(equal_vectors(res.trip.get()->J, Jcorrect) == true);
        CHECK(equal_vectors_tol(res.trip.get()->X, Xcorrect, 1e-15) == true);
    }

    SUBCASE("read sparse-matrix bad")
    {
        auto data_path = path_get_current() + "/../../../data";
        auto s = data_path + "/sparse-matrix/bad";
        CHECK_THROWS_WITH(read_matrix_for_mumps(s + "1.mtx"), "read_matrix_for_mumps: header starting with %%MatrixMarket is incorrect");
        CHECK_THROWS_WITH(read_matrix_for_mumps(s + "2.mtx"), "read_matrix_for_mumps: can only read \"matrix\" MatrixMarket at the moment");
        CHECK_THROWS_WITH(read_matrix_for_mumps(s + "3.mtx"), "read_matrix_for_mumps: can only read \"coordinate\" MatrixMarket at the moment");
        CHECK_THROWS_WITH(read_matrix_for_mumps(s + "4.mtx"), "read_matrix_for_mumps: the given MatrixMarket file must have the word \"real\" in the header");
        CHECK_THROWS_WITH(read_matrix_for_mumps(s + "5.mtx"), "read_matrix_for_mumps: only works with \"general\", \"symmetric\" and \"unsymmetric\" MatrixMarket files");
        CHECK_THROWS_WITH(read_matrix_for_mumps(s + "6.mtx"), "read_matrix_for_mumps: the number of columns in the line with dimensions must be 3 (m,n,nnz)");
        CHECK_THROWS_WITH(read_matrix_for_mumps(s + "7.mtx"), "read_matrix_for_mumps: cannot parse m, n, or nnz values");
        CHECK_THROWS_WITH(read_matrix_for_mumps(s + "8.mtx"), "read_matrix_for_mumps: the number of columns in the data lines must be 3 (i,j,x)");
        CHECK_THROWS_WITH(read_matrix_for_mumps(s + "9.mtx"), "read_matrix_for_mumps: cannot parse i, j or x values");
    }
}
