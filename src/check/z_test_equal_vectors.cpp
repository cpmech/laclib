#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../util/doctest.h"
#include "equal_vectors.h"
#include <vector>

TEST_CASE("equal_int_vectors")
{
    SUBCASE("int vectors")
    {
        std::vector<int> a{1, 2, 3};
        std::vector<int> b{1, 2, 3};
        std::vector<int> c{1, 2, 4};
        std::vector<int> d{1, 2};
        CHECK(equal_int_vectors(a, b) == true);
        CHECK(equal_int_vectors(b, c) == false);
        CHECK(equal_int_vectors(c, d) == false);
    }

    SUBCASE("size_t vectors")
    {
        std::vector<size_t> a{1, 2, 3};
        std::vector<size_t> b{1, 2, 3};
        std::vector<size_t> c{1, 2, 4};
        std::vector<size_t> d{1, 2};
        CHECK(equal_int_vectors(a, b) == true);
        CHECK(equal_int_vectors(b, c) == false);
        CHECK(equal_int_vectors(c, d) == false);
    }

    SUBCASE("float vectors")
    {
        float tolerance = 1e-6;
        std::vector<float> a{1.0f, 2.0f, 3.0f};
        std::vector<float> b{1.0f, 2.0f, 3.0f + tolerance};
        std::vector<float> c{1.0f, 2.0f, 3.0f + 1e-5};
        std::vector<float> d{1.0f, 2.0f};
        CHECK(equal_flt_vectors(a, b, tolerance) == true);
        CHECK(equal_flt_vectors(b, c, tolerance) == false);
        CHECK(equal_flt_vectors(c, d, tolerance) == false);
    }

    SUBCASE("double vectors")
    {
        double tolerance = 1e-15;
        std::vector<double> a{1.0, 2.0, 3.0};
        std::vector<double> b{1.0, 2.0, 3.0 + tolerance};
        std::vector<double> c{1.0, 2.0, 3.0 + 1e-14};
        std::vector<double> d{1.0, 2.0};
        CHECK(equal_flt_vectors(a, b, tolerance) == true);
        CHECK(equal_flt_vectors(b, c, tolerance) == false);
        CHECK(equal_flt_vectors(c, d, tolerance) == false);
    }
}
