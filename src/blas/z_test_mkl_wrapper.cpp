#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../util/doctest.h"
#include "../check/check.h"
#include "mkl_wrapper.h"
#include <vector>
using namespace std;

TEST_CASE("mkl_wrapper")
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
}