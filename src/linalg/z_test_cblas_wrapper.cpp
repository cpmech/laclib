#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <vector>

#include "../check/index.h"
#include "../util/doctest.h"
#include "../util/print_vector.h"
#include "cblas_wrapper.h"
#include "matrix.h"

using namespace std;

TEST_CASE("CBLAS wrapper") {

    SUBCASE("set_num_threads works (probably)") {
        set_num_threads(1);
    }

    SUBCASE("max_abs_value works") {
        auto x = std::vector<double>{1, 5, -9, 2, 6, 0, 3, 7, -1, 4, 8, -2};
        auto res = max_abs_value(x);
        CHECK(equal_scalars_tol(res, 9.0, 1e-15));
    }

    SUBCASE("daxpy works") {
        double alpha = 0.5;
        auto x = vector<double>{20, 10, 30, 123, 123};
        auto y = vector<double>{-15, -5, -24, 666, 666, 666};
        int n = 3;
        daxpy(n, alpha, x, y);
        auto x_correct = vector<double>{20, 10, 30, 123, 123};
        auto y_correct = vector<double>{-5, 0, -9, 666, 666, 666};
        CHECK(equal_vectors_tol(x, x_correct, 1e-15));
        CHECK(equal_vectors_tol(y, y_correct, 1e-15));
    }

    SUBCASE("mat_vec_mul works") {
        auto a = Matrix::make_new(3, 4);
        //  5.0, -2.0, 0.0, 1.0
        // 10.0, -4.0, 0.0, 2.0
        // 15.0, -6.0, 0.0, 3.0
        a->set(0, 0, 5.0);
        a->set(0, 1, -2.0);
        a->set(0, 3, 1.0);
        a->set(1, 0, 10.0);
        a->set(1, 1, -4.0);
        a->set(1, 3, 2.0);
        a->set(2, 0, 15.0);
        a->set(2, 1, -6.0);
        a->set(2, 3, 3.0);
        // a->print();
        auto u = vector<double>{1.0, 3.0, 8.0, 5.0};
        auto v = vector<double>(a->nrow, 0.0);
        mat_vec_mul(v, 1.0, a, u);
        // print_vector("v", v);
        auto correct = vector<double>{4.0, 8.0, 12.0};
        CHECK(equal_vectors_tol(v, correct, 1e-15));
    }
}
