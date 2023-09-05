#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <vector>

#include "../check/index.h"
#include "../util/doctest.h"
#include "cblas_tools.h"
using namespace std;

TEST_CASE("CBLAS tools") {
    SUBCASE("set_num_threads") {
        set_num_threads(1);
    }

    SUBCASE("max_abs_value") {
        auto x = std::vector<double>{1, 5, -9, 2, 6, 0, 3, 7, -1, 4, 8, -2};
        auto res = max_abs_value(x);
        CHECK(equal_scalars_tol(res, 9.0, 1e-15));
    }

    SUBCASE("daxpy") {
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
}
