#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <vector>

#include "../check/index.h"
#include "../util/doctest.h"
#include "../util/print_vector.h"
#include "mat_vec_mul.h"
#include "matrix.h"

using namespace std;

TEST_CASE("matrix-vector-multiplication") {
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
        a->print();
        auto u = vector<double>{1.0, 3.0, 8.0, 5.0};
        auto v = vector<double>(a->nrow, 0.0);
        mat_vec_mul(v, 1.0, a, u);
        print_vector("v", v);
        auto correct = vector<double>{4.0, 8.0, 12.0};
        // CHECK(equal_vectors_tol(v, correct, 1e-15));
    }
}
