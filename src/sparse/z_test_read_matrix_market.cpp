#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <vector>

#include "../check/check.h"
#include "../util/doctest.h"
#include "../util/path_tools.h"
#include "../util/print_vector.h"
#include "read_matrix_market.h"
using namespace std;

TEST_CASE("read_matrix_market") {
    auto data_path = path_get_current() + "/../../../data/sparse-matrix/";

    SUBCASE("cannot open file") {
        CHECK_THROWS_WITH(read_matrix_market("invalid.mtx"), "read_matrix_market: cannot open file");
    }

    SUBCASE("read sparse-matrix bad") {
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
        CHECK_THROWS_WITH(read_matrix_market(s + "10.mtx"), "SparseTriplet::put: j > i is incorrect for lower triangular layout");
    }

    SUBCASE("read sparse-matrix ok1") {
        auto mtx = data_path + "ok1.mtx";
        auto trip = read_matrix_market(mtx);

        vector<INT> correct_i = {0, 1, 0, 2, 4, 1, 2, 3, 4, 2, 1, 4};
        vector<INT> correct_j = {0, 0, 1, 1, 1, 2, 2, 2, 2, 3, 4, 4};
        vector<double> correct_aij = {2, 3, 3, -1, 4, 4, -3, 1, 2, 2, 6, 1};

        CHECK(trip->layout == FULL_MATRIX);
        CHECK(equal_vectors(trip->indices_i, correct_i) == true);
        CHECK(equal_vectors(trip->indices_j, correct_j) == true);
        CHECK(equal_vectors_tol(trip->values_aij, correct_aij, 1e-15) == true);
    }
}
