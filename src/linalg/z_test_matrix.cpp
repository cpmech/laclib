#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <vector>

#include "../check/index.h"
#include "../util/doctest.h"
#include "matrix.h"

using namespace std;

TEST_CASE("matrix") {
    SUBCASE("make_new works") {
        auto mat = Matrix::make_new(3, 2);
        CHECK(mat->nrow == 3);
        CHECK(mat->ncol == 2);
        auto correct = vector<double>{0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
        CHECK(equal_vectors_tol(mat->data, correct, 1e-17));
    }
    SUBCASE("identity works") {
        auto mat = Matrix::identity(3);
        CHECK(mat->nrow == 3);
        CHECK(mat->ncol == 3);
        auto correct = vector<double>{1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0};
        CHECK(equal_vectors_tol(mat->data, correct, 1e-17));
    }
    SUBCASE("filled works") {
        auto mat = Matrix::filled(2, 3, 10.0);
        CHECK(mat->nrow == 2);
        CHECK(mat->ncol == 3);
        auto correct = vector<double>{10.0, 10.0, 10.0, 10.0, 10.0, 10.0};
        CHECK(equal_vectors_tol(mat->data, correct, 1e-17));
    }
    SUBCASE("diagonal works") {
        auto diagonal = vector<double>{1.0, 2.0, 3.0};
        auto mat = Matrix::diagonal(diagonal);
        CHECK(mat->nrow == 3);
        CHECK(mat->ncol == 3);
        auto correct = vector<double>{1.0, 0.0, 0.0, 0.0, 2.0, 0.0, 0.0, 0.0, 3.0};
        CHECK(equal_vectors_tol(mat->data, correct, 1e-17));
    }
    SUBCASE("from_row_major works") {
        auto mat = Matrix::from_row_major(3, 3, vector<double>{
                                                    1.0, 2.0, 3.0, // 0
                                                    4.0, 5.0, 6.0, // 0
                                                    7.0, 8.0, 9.0, // 0
                                                });
        auto correct = vector<double>{1.0, 4.0, 7.0, 2.0, 5.0, 8.0, 3.0, 6.0, 9.0};
        CHECK(equal_vectors_tol(mat->data, correct, 1e-17));
    }
    SUBCASE("get_copy works") {
        auto original = Matrix::make_new(2, 3);
        original->data[0] = 1.0;
        original->data[1] = 2.0;
        original->data[2] = 3.0;
        original->data[3] = 4.0;
        original->data[4] = 5.0;
        original->data[5] = 6.0;
        auto copy = original->get_copy();
        auto correct = vector<double>{1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
        CHECK(equal_vectors_tol(copy->data, correct, 1e-17));
    }
    SUBCASE("fill works") {
        auto mat = Matrix::make_new(3, 2);
        mat->fill(10.0);
        CHECK(mat->nrow == 3);
        CHECK(mat->ncol == 2);
        auto correct = vector<double>{10.0, 10.0, 10.0, 10.0, 10.0, 10.0};
        CHECK(equal_vectors_tol(mat->data, correct, 1e-17));
    }
    SUBCASE("get works") {
        // 1.0 2.0
        // 3.0 4.0
        auto mat = Matrix::make_new(2, 2);
        mat->data[0] = 1.0;
        mat->data[1] = 3.0;
        mat->data[2] = 2.0;
        mat->data[3] = 4.0;
        CHECK(equal_scalars_tol(mat->get(0, 0), 1.0, 1e-17));
        CHECK(equal_scalars_tol(mat->get(0, 1), 2.0, 1e-17));
        CHECK(equal_scalars_tol(mat->get(1, 0), 3.0, 1e-17));
        CHECK(equal_scalars_tol(mat->get(1, 1), 4.0, 1e-17));
    }
    SUBCASE("set works") {
        auto mat = Matrix::make_new(2, 2);
        // 1.0 2.0
        // 3.0 4.0
        mat->set(0, 0, 1.0);
        mat->set(0, 1, 2.0);
        mat->set(1, 0, 3.0);
        mat->set(1, 1, 4.0);
        auto correct = vector<double>{1.0, 3.0, 2.0, 4.0};
        CHECK(equal_vectors_tol(mat->data, correct, 1e-17));
    }
}
