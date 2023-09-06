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
    SUBCASE("identity works") {}
    SUBCASE("filled works") {}
    SUBCASE("from works") {}
    SUBCASE("diagonal works") {}
    SUBCASE("fill works") {}
    SUBCASE("get works") {}
    SUBCASE("set works") {}
}
