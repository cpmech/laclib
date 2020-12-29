#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../util/doctest.h"
#include "../util/path_tools.h"
#include "../check/check.h"
#include "read_matrix.h"
#include <vector>
using namespace std;

TEST_CASE("read_matrix")
{
    vector<size_t> Icorrect = {0, 1, 0, 2, 4, 1, 2, 3, 4, 2, 1, 4};
    vector<size_t> Jcorrect = {0, 0, 1, 1, 1, 2, 2, 2, 2, 3, 4, 4};
    vector<double> Xcorrect = {2, 3, 3, -1, 4, 4, -3, 1, 2, 2, 6, 1};

    auto data_path = path_get_current() + "/../../../data";

    SUBCASE("cannot open file")
    {
        CHECK_THROWS_WITH(read_matrix("invalid.mtx", true), "read_matrix: cannot open file");
    }

    SUBCASE("read sparse-matrix ok1")
    {
        auto mtx = data_path + "/sparse-matrix/ok1.mtx";
        auto mirrorIfSym = false;
        auto res = read_matrix(mtx, mirrorIfSym);

        CHECK(res.symmetric == false);
        CHECK(equal_vectors(res.trip.get()->I, Icorrect) == true);
        CHECK(equal_vectors(res.trip.get()->J, Jcorrect) == true);
        CHECK(equal_vectors_tol(res.trip.get()->X, Xcorrect, 1e-15) == true);
    }

    SUBCASE("read sparse-matrix ok2")
    {
        auto mtx = data_path + "/sparse-matrix/ok2.mtx";
        auto mirrorIfSym = false;
        auto res = read_matrix(mtx, mirrorIfSym);

        CHECK(res.symmetric == false);
        CHECK(equal_vectors(res.trip.get()->I, Icorrect) == true);
        CHECK(equal_vectors(res.trip.get()->J, Jcorrect) == true);
        CHECK(equal_vectors_tol(res.trip.get()->X, Xcorrect, 1e-15) == true);
    }

    SUBCASE("read sparse-matrix bad")
    {
        auto data_path = path_get_current() + "/../../../data";
        auto s = data_path + "/sparse-matrix/bad";
        CHECK_THROWS_WITH(read_matrix(s + "1.mtx", false), "read_matrix: header starting with %%MatrixMarket is incorrect");
        CHECK_THROWS_WITH(read_matrix(s + "2.mtx", false), "read_matrix: can only read \"matrix\" MatrixMarket at the moment");
        CHECK_THROWS_WITH(read_matrix(s + "3.mtx", false), "read_matrix: can only read \"coordinate\" MatrixMarket at the moment");
        CHECK_THROWS_WITH(read_matrix(s + "4.mtx", false), "read_matrix: the given MatrixMarket file must have the word \"real\" in the header");
        CHECK_THROWS_WITH(read_matrix(s + "5.mtx", false), "read_matrix: only works with \"general\", \"symmetric\" and \"unsymmetric\" MatrixMarket files");
        CHECK_THROWS_WITH(read_matrix(s + "6.mtx", false), "read_matrix: the number of columns in the line with dimensions must be 3 (m,n,nnz)");
        CHECK_THROWS_WITH(read_matrix(s + "7.mtx", false), "read_matrix: cannot parse m, n, or nnz values");
        CHECK_THROWS_WITH(read_matrix(s + "8.mtx", false), "read_matrix: the number of columns in the data lines must be 3 (i,j,x)");
        CHECK_THROWS_WITH(read_matrix(s + "9.mtx", false), "read_matrix: cannot parse i, j or x values");
    }
}
