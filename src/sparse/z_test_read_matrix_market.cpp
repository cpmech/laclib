#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <iostream>
#include <vector>

#include "../check/index.h"
#include "../util/doctest.h"
#include "../util/print_vector.h"
#include "read_matrix_market.h"

#ifndef DATA_DIR
#define DATA_DIR "data"
#endif

using namespace std;

TEST_CASE("read_matrix_market") {

    auto data_path = string(DATA_DIR) + "/sparse-matrix/";

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
        CHECK_THROWS_WITH(read_matrix_market(s + "10.mtx"), "CooMatrix::put: j > i is incorrect for lower triangular layout");
    }

    SUBCASE("read sparse-matrix ok1") {
        auto mtx = data_path + "ok1.mtx";
        auto coo = read_matrix_market(mtx);

        vector<INT> correct_i = {0, 1, 0, 2, 4, 1, 2, 3, 4, 2, 1, 4};
        vector<INT> correct_j = {0, 0, 1, 1, 1, 2, 2, 2, 2, 3, 4, 4};
        vector<double> correct_aij = {2, 3, 3, -1, 4, 4, -3, 1, 2, 2, 6, 1};

        CHECK(coo->layout == FULL_MATRIX);
        CHECK(equal_vectors(coo->indices_i, correct_i));
        CHECK(equal_vectors(coo->indices_j, correct_j));
        CHECK(equal_vectors_tol(coo->values_aij, correct_aij, 1e-15));
    }

    SUBCASE("symmetric cases") {
        SUBCASE("'leave as lower' works") {
            auto mtx = data_path + "sym1.mtx";
            auto coo = read_matrix_market(mtx);
            vector<INT> correct_i = {/*diag*/ 0, 1, 2, 3, 4, /*lower*/ 1, 2, 4, 2, 3, 4};
            vector<INT> correct_j = {/*diag*/ 0, 1, 2, 3, 4, /*lower*/ 0, 0, 0, 1, 1, 3};
            vector<double> correct_aij = {/*diag*/ 10.0, 20.0, 30.0, 40.0, 50.0, /*lower*/ 1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
            CHECK(coo->layout == LOWER_TRIANGULAR);
            CHECK(equal_vectors(coo->indices_i, correct_i));
            CHECK(equal_vectors(coo->indices_j, correct_j));
            CHECK(equal_vectors_tol(coo->values_aij, correct_aij, 1e-15));
        }
    }
}
