#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../util/doctest.h"
#include "../check/check.h"
#include "conversions.h"
#include <vector>
using namespace std;

TEST_CASE("conversions")
{
    SUBCASE("vecvec_to_colmaj")
    {
        auto a = std::vector<std::vector<double>>{
            {1, 2, +3, +4},
            {5, 6, +7, +8},
            {9, 0, -1, -2},
        };
        auto a_cm = vecvec_to_colmaj(a);
        auto a_correct = std::vector<double>{1, 5, 9, 2, 6, 0, 3, 7, -1, 4, 8, -2};
        CHECK(equal_vectors_tol(a_cm, a_correct, 1e-15));
    }

    SUBCASE("colmaj_to_vecvec")
    {
        size_t m = 3;
        size_t n = 4;
        auto a_cm = std::vector<double>{1, 5, 9, 2, 6, 0, 3, 7, -1, 4, 8, -2};
        auto a = colmaj_to_vecvec(m, n, a_cm);
        auto a_correct = std::vector<std::vector<double>>{
            {1, 2, +3, +4},
            {5, 6, +7, +8},
            {9, 0, -1, -2},
        };
        for (size_t i = 0; i < m; i++)
        {
            for (size_t j = 0; j < n; j++)
            {
                CHECK(a[i][j] == a_correct[i][j]);
            }
        }
    }

    SUBCASE("colmaj_extract_row")
    {
        // 1, 2, +3, +4
        // 5, 6, +7, +8
        // 9, 0, -1, -2
        size_t m = 3;
        size_t n = 4;
        auto a = std::vector<double>{1, 5, 9, 2, 6, 0, 3, 7, -1, 4, 8, -2};
        auto row0 = colmaj_extract_row(0, m, n, a);
        auto row1 = colmaj_extract_row(1, m, n, a);
        auto row2 = colmaj_extract_row(2, m, n, a);
        auto row0_correct = vector<double>{1, 2, +3, +4};
        auto row1_correct = vector<double>{5, 6, +7, +8};
        auto row2_correct = vector<double>{9, 0, -1, -2};
        CHECK(equal_vectors_tol(row0, row0_correct, 1e-15));
        CHECK(equal_vectors_tol(row1, row1_correct, 1e-15));
        CHECK(equal_vectors_tol(row2, row2_correct, 1e-15));
    }

    SUBCASE("colmaj_extract_col")
    {
        // 1, 2, +3, +4
        // 5, 6, +7, +8
        // 9, 0, -1, -2
        size_t m = 3;
        size_t n = 4;
        auto a = std::vector<double>{1, 5, 9, 2, 6, 0, 3, 7, -1, 4, 8, -2};
        auto col0 = colmaj_extract_col(0, m, n, a);
        auto col1 = colmaj_extract_col(1, m, n, a);
        auto col2 = colmaj_extract_col(2, m, n, a);
        auto col3 = colmaj_extract_col(3, m, n, a);
        auto col0_correct = vector<double>{1, 5, 9};
        auto col1_correct = vector<double>{2, 6, 0};
        auto col2_correct = vector<double>{3, 7, -1};
        auto col3_correct = vector<double>{4, 8, -2};
        CHECK(equal_vectors_tol(col0, col0_correct, 1e-15));
        CHECK(equal_vectors_tol(col1, col1_correct, 1e-15));
        CHECK(equal_vectors_tol(col2, col2_correct, 1e-15));
        CHECK(equal_vectors_tol(col3, col3_correct, 1e-15));
    }
}