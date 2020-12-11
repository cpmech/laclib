#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../util/doctest.h"
#include "equal_vectors.h"
#include <vector>
#include <string>
using namespace std;

TEST_CASE("equal_vectors")
{
    SUBCASE("int vectors")
    {
        vector<int> a{1, 2, 3};
        vector<int> b{1, 2, 3};
        vector<int> c{1, 2, 4};
        vector<int> d{1, 2};
        CHECK(equal_vectors(a, b) == true);
        CHECK(equal_vectors(b, c) == false);
        CHECK(equal_vectors(c, d) == false);
    }

    SUBCASE("size_t vectors")
    {
        vector<size_t> a{1, 2, 3};
        vector<size_t> b{1, 2, 3};
        vector<size_t> c{1, 2, 4};
        vector<size_t> d{1, 2};
        CHECK(equal_vectors(a, b) == true);
        CHECK(equal_vectors(b, c) == false);
        CHECK(equal_vectors(c, d) == false);
    }

    SUBCASE("string vectors")
    {
        vector<string> a{"1", "2", "3"};
        vector<string> b{"1", "2", "3"};
        vector<string> c{"1", "2", "4"};
        vector<string> d{"1", "2"};
        CHECK(equal_vectors(a, b) == true);
        CHECK(equal_vectors(b, c) == false);
        CHECK(equal_vectors(c, d) == false);
    }
}

TEST_CASE("equal_vectors_tol")
{
    SUBCASE("float vectors")
    {
        float tolerance = 1e-6;
        vector<float> a{1.0f, 2.0f, 3.0f};
        vector<float> b{1.0f, 2.0f, 3.0f + tolerance};
        vector<float> c{1.0f, 2.0f, 3.0f + 1e-5};
        vector<float> d{1.0f, 2.0f};
        CHECK(equal_vectors_tol(a, b, tolerance) == true);
        CHECK(equal_vectors_tol(b, c, tolerance) == false);
        CHECK(equal_vectors_tol(c, d, tolerance) == false);
    }

    SUBCASE("double vectors")
    {
        double tolerance = 1e-15;
        vector<double> a{1.0, 2.0, 3.0};
        vector<double> b{1.0, 2.0, 3.0 + tolerance};
        vector<double> c{1.0, 2.0, 3.0 + 1e-14};
        vector<double> d{1.0, 2.0};
        CHECK(equal_vectors_tol(a, b, tolerance) == true);
        CHECK(equal_vectors_tol(b, c, tolerance) == false);
        CHECK(equal_vectors_tol(c, d, tolerance) == false);
    }
}
