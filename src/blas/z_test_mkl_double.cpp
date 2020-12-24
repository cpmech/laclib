#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../util/doctest.h"
#include "../util/print_vector.h"
#include "../check/check.h"
#include "mkl_double.h"
#include <vector>
#include <iostream>
using namespace std;

TEST_CASE("mkl_double")
{
    SUBCASE("ddot")
    {
        auto x = vector<double>{20, 10, 30, 123, 123};
        auto y = vector<double>{-15, -5, -24, 666, 666, 666};
        int n = 3;
        int incx = 1;
        int incy = 1;
        auto res = ddot(n, x, incx, y, incy);
        double correct = -1070.0;
        CHECK(equal_scalars_tol(res, correct, 1e-15));
    }

    SUBCASE("dscal")
    {
        double alpha = 0.5;
        auto x = vector<double>{20, 10, 30, 123, 123};
        int n = 3;
        int incx = 1;
        dscal(n, alpha, x, incx);
        auto x_correct = vector<double>{10, 5, 15, 123, 123};
        CHECK(equal_vectors_tol(x, x_correct, 1e-15));
    }

    SUBCASE("daxpy")
    {
        double alpha = 0.5;
        auto x = vector<double>{20, 10, 30, 123, 123};
        auto y = vector<double>{-15, -5, -24, 666, 666, 666};
        int n = 3;
        int incx = 1;
        int incy = 1;
        daxpy(n, alpha, x, incx, y, incy);
        auto x_correct = vector<double>{20, 10, 30, 123, 123};
        auto y_correct = vector<double>{-5, 0, -9, 666, 666, 666};
        CHECK(equal_vectors_tol(x, x_correct, 1e-15));
        CHECK(equal_vectors_tol(y, y_correct, 1e-15));
    }
}