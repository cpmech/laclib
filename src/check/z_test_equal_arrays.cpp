#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <array>
#include <complex>
#include <string>

#include "../util/doctest.h"
#include "index.h"

using namespace std;

TEST_CASE("equal_arrays") {
    SUBCASE("int arrays") {
        int a[3] = {1, 2, 3};
        int b[3] = {1, 2, 3};
        int c[3] = {1, 2, 4};
        CHECK(equal_arrays(3, a, b));
        CHECK(equal_arrays(3, b, c) == false);
    }

    SUBCASE("size_t arrays") {
        size_t a[3] = {1, 2, 3};
        size_t b[3] = {1, 2, 3};
        size_t c[3] = {1, 2, 4};
        CHECK(equal_arrays(3, a, b));
        CHECK(equal_arrays(3, b, c) == false);
    }

    SUBCASE("string arrays") {
        string a[3] = {"1", "2", "3"};
        string b[3] = {"1", "2", "3"};
        string c[3] = {"1", "2", "4"};
        CHECK(equal_arrays(3, a, b));
        CHECK(equal_arrays(3, b, c) == false);
    }
}

TEST_CASE("equal_arrays_tol") {
    SUBCASE("float arrays") {
        float tolerance = 1e-6;
        float a[3] = {1.0f, 2.0f, 3.0f};
        float b[3] = {1.0f, 2.0f, 3.0f + tolerance};
        float c[3] = {1.0f, 2.0f, 3.0f + 1e-5};
        CHECK(equal_arrays_tol(3, a, b, tolerance));
        CHECK(equal_arrays_tol(3, b, c, tolerance) == false);
    }

    SUBCASE("double arrays") {
        double tolerance = 1e-15;
        double a[3] = {1.0, 2.0, 3.0};
        double b[3] = {1.0, 2.0, 3.0 + tolerance};
        double c[3] = {1.0, 2.0, 3.0 + 1e-14};
        CHECK(equal_arrays_tol(3, a, b, tolerance));
        CHECK(equal_arrays_tol(3, b, c, tolerance) == false);
    }
}
