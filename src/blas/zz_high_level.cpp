#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../util/doctest.h"
#include "../check/check.h"
#include "high_level.h"
#include <vector>
using namespace std;

TEST_CASE("high level functions")
{
    SUBCASE("norm_inf")
    {
        auto x = std::vector<double>{1, 5, -9, 2, 6, 0, 3, 7, -1, 4, 8, -2};
        auto res = norm_inf(x);
        CHECK(equal_scalars_tol(res, 9.0, 1e-15) == true);
    }
}
