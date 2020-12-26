#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../util/doctest.h"
#include "../util/print_vector.h"
#include "../check/check.h"
#include "auxiliary.h"
#include "conversions.h"
#include "mkl_double.h"
#include <cmath>
#include <vector>
#include <iostream>
using namespace std;

#define CMGET(a, num_rows, i, j) a[i + j * num_rows]

void checksvd(
    int m,
    int n,
    std::vector<double> a,
    std::vector<double> s_correct,
    double tols,
    double tolusv,
    bool verbose = false)
{
    // copy matrix a
    auto a_copy = a;

    // compute dimensions
    int min_mn = m < n ? m : n;
    int lda = m;
    int ldu = m;
    int ldvt = n;

    // allocate output arrays
    auto s = std::vector<double>(min_mn, 0.0);
    auto u = std::vector<double>(m * m, 0.0);
    auto vt = std::vector<double>(n * n, 0.0);
    auto superb = std::vector<double>(min_mn, 0.0);

    // perform SVD
    char jobu = 'A';
    char jobvt = 'A';
    dgesvd(jobu, jobvt, m, n, a, lda, s, u, ldu, vt, ldvt, superb);

    // compare results
    CHECK(equal_vectors_tol(s, s_correct, tols));

    // check SVD
    auto usv = std::vector<double>(m * n, 0.0);
    for (size_t i = 0; i < m; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            for (size_t k = 0; k < min_mn; k++)
            {
                CMGET(usv, m, i, j) += CMGET(u, m, i, k) * s[k] * CMGET(vt, n, k, j);
            }
        }
    }
    if (verbose)
    {
        print_colmaj("usv", "%13g", m, n, usv);
        print_colmaj("a", "%13g", m, n, a_copy);
    }
    CHECK(equal_vectors_tol(usv, a_copy, tolusv));
}

TEST_CASE("mkl_double")
{
    // 4 x 5
    auto a_mat = vecvec_to_colmaj(vector<vector<double>>{
        {1, 2, +0, 1, -1},
        {2, 3, -1, 1, +1},
        {1, 2, +0, 4, -1},
        {4, 0, +3, 1, +1},
    });

    // 5 x 4
    auto at_mat = vecvec_to_colmaj(vector<vector<double>>{
        {+1, +2, +1, +4},
        {+2, +3, +2, +0},
        {+0, -1, +0, +3},
        {+1, +1, +4, +1},
        {-1, +1, -1, +1},
    });

    // 5 x 3
    auto b_mat = vecvec_to_colmaj(vector<vector<double>>{
        {1, 0, 0},
        {0, 0, 3},
        {0, 0, 1},
        {1, 0, 1},
        {0, 2, 0},
    });

    // 4 x 3
    auto c_mat = vecvec_to_colmaj(vector<vector<double>>{
        {+0.50, 0, +0.25},
        {+0.25, 0, -0.25},
        {-0.25, 0, +0.00},
        {-0.25, 0, +0.00},
    });

    // 3 x 5
    auto bt_mat = vecvec_to_colmaj(vector<vector<double>>{
        {1, 0, 0, 1, 0},
        {0, 0, 0, 0, 2},
        {0, 3, 1, 1, 0},
    });

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

    SUBCASE("dgemv")
    {
        auto a = vector<double>{0.1, 1, 2, 3, 0.2, 0.2, 0.2, 0.2, 0.3, 0.3, 0.3, 0.3};

        // perform mv
        int m = 4;
        int n = 3;
        double alpha = 0.5;
        double beta = 2.0;
        auto x = vector<double>{20, 10, 30};
        auto y = vector<double>{3, 1, 2, 4};
        int lda = m;
        int incx = 1;
        int incy = 1;
        dgemv(false, m, n, alpha, a, lda, x, incx, beta, y, incy);
        auto y_correct = vector<double>{12.5, 17.5, 29.5, 43.5};
        CHECK(equal_vectors_tol(y, y_correct, 1e-15));

        // perform mv with transpose
        dgemv(true, m, n, alpha, a, lda, y, incy, beta, x, incx);
        auto x_correct = vector<double>{144.125, 30.3, 75.45};
        CHECK(equal_vectors_tol(x, x_correct, 1e-15));

        // check that a is unmodified
        auto a_correct = vector<double>{0.1, 1, 2, 3, 0.2, 0.2, 0.2, 0.2, 0.3, 0.3, 0.3, 0.3};
        CHECK(equal_vectors_tol(a, a_correct, 1e-15));
    }

    SUBCASE("dgemm 1: c = 0.5⋅a⋅b + 2⋅c")
    {
        int m = 4; // m = nrow(a) = a.M = nrow(c)
        int k = 5; // k = ncol(a) = a.N = nrow(b)
        int n = 3; // n = ncol(b) = b.N = ncol(c)

        auto transA = false;
        auto transB = false;
        double alpha = 0.5;
        double beta = 2.0;
        int lda = 4;
        int ldb = 5;
        int ldc = 4;
        dgemm(transA, transB, m, n, k, alpha, a_mat, lda, b_mat, ldb, beta, c_mat, ldc);

        auto c_correct = vecvec_to_colmaj(vector<vector<double>>{
            {2, -1, 4},
            {2, +1, 4},
            {2, -1, 5},
            {2, +1, 2},
        });
        CHECK(equal_vectors_tol(c_mat, c_correct, 1e-15));
    }

    SUBCASE("dgemm 2: 0.5⋅a⋅bᵀ + 2⋅c")
    {
        int m = 4; // m = nrow(a)        = a.M = nrow(c)
        int k = 5; // k = ncol(a)        = a.N = nrow(trans(b))
        int n = 3; // n = ncol(trans(b)) = b.M = ncol(c)

        auto transA = false;
        auto transB = true;
        double alpha = 0.5;
        double beta = 2.0;
        int lda = 4;
        int ldb = 3;
        int ldc = 4;
        dgemm(transA, transB, m, n, k, alpha, a_mat, lda, bt_mat, ldb, beta, c_mat, ldc);

        auto c_correct = vecvec_to_colmaj(vector<vector<double>>{
            {2, -1, 4},
            {2, +1, 4},
            {2, -1, 5},
            {2, +1, 2},
        });
        CHECK(equal_vectors_tol(c_mat, c_correct, 1e-15));
    }

    SUBCASE("dgemm 3: 0.5⋅aᵀ⋅b + 2⋅c")
    {
        int m = 4; // m = nrow(trans(a)) = a.N = nrow(c)
        int k = 5; // k = ncol(trans(a)) = a.M = nrow(trans(b))
        int n = 3; // n = ncol(b)        = b.N = ncol(c)

        auto transA = true;
        auto transB = false;
        double alpha = 0.5;
        double beta = 2.0;
        int lda = 5;
        int ldb = 5;
        int ldc = 4;
        dgemm(transA, transB, m, n, k, alpha, at_mat, lda, b_mat, ldb, beta, c_mat, ldc);

        auto c_correct = vecvec_to_colmaj(vector<vector<double>>{
            {2, -1, 4},
            {2, +1, 4},
            {2, -1, 5},
            {2, +1, 2},
        });
        CHECK(equal_vectors_tol(c_mat, c_correct, 1e-15));
    }

    SUBCASE("dgemm: 4: 0.5⋅aᵀ⋅bᵀ + 2⋅c")
    {
        int m = 4; // m = nrow(trans(a)) = a.N = nrow(c)
        int k = 5; // k = ncol(trans(a)) = a.M = nrow(trans(b))
        int n = 3; // n = ncol(trans(b)) = b.M = ncol(c)

        auto transA = true;
        auto transB = true;
        double alpha = 0.5;
        double beta = 2.0;
        int lda = 5;
        int ldb = 3;
        int ldc = 4;
        dgemm(transA, transB, m, n, k, alpha, at_mat, lda, bt_mat, ldb, beta, c_mat, ldc);

        auto c_correct = vecvec_to_colmaj(vector<vector<double>>{
            {2, -1, 4},
            {2, +1, 4},
            {2, -1, 5},
            {2, +1, 2},
        });
        CHECK(equal_vectors_tol(c_mat, c_correct, 1e-15));
    }

    SUBCASE("dgesv")
    {
        // matrix
        auto a = vecvec_to_colmaj(vector<vector<double>>{
            {2, +3, +0, 0, 0},
            {3, +0, +4, 0, 6},
            {0, -1, -3, 2, 0},
            {0, +0, +1, 0, 0},
            {0, +4, +2, 0, 1},
        });

        // right-hand-side
        auto b = vector<double>{8, 45, -3, 3, 19};

        // solution
        auto x_correct = vector<double>{1, 2, 3, 4, 5};

        // run test
        int n = 5;
        int nrhs = 1;
        int lda = n;
        int ldb = n;
        auto ipiv = vector<int>(n, 0);
        dgesv(n, nrhs, a, lda, ipiv, b, ldb);

        // check solution x = A⁻¹ b
        CHECK(equal_vectors_tol(b, x_correct, 1e-14));

        // check ipiv
        CHECK(equal_vectors(ipiv, vector<int>{2, 5, 5, 5, 5}));
    }

    SUBCASE("dgesvd 1")
    {
        auto a = vecvec_to_colmaj(vector<vector<double>>{
            {1, 0, 0, 0, 2},
            {0, 0, 3, 0, 0},
            {0, 0, 0, 0, 0},
            {0, 2, 0, 0, 0},
        });
        auto s_correct = vector<double>{3.0, sqrt(5.0), 2.0, 0.0};
        checksvd(4, 5, a, s_correct, 1e-15, 1e-15);
    }

    SUBCASE("dgesvd 2")
    {
        double s33 = sqrt(3.0) / 3.0;
        auto a = vecvec_to_colmaj(vector<vector<double>>{
            {-s33, -s33, 1},
            {+s33, -s33, 1},
            {-s33, +s33, 1},
            {+s33, +s33, 1},
        });
        auto s_correct = vector<double>{2, 2.0 / sqrt(3.0), 2.0 / sqrt(3.0)};
        checksvd(4, 3, a, s_correct, 1e-15, 1e-15);
    }

    SUBCASE("dgesvd 3")
    {
        auto a = vecvec_to_colmaj(vector<vector<double>>{
            {64, 2, 3, 61, 60, 6},
            {9, 55, 54, 12, 13, 51},
            {17, 47, 46, 20, 21, 43},
            {40, 26, 27, 37, 36, 30},
            {32, 34, 35, 29, 28, 38},
            {41, 23, 22, 44, 45, 19},
            {49, 15, 14, 52, 53, 11},
            {8, 58, 59, 5, 4, 62},
        });
        auto s_correct = vector<double>{+2.251695779937001e+02, +1.271865289052834e+02, +1.175789144211322e+01, +1.277237188369868e-14, +6.934703857768031e-15, +5.031833747507930e-15};
        checksvd(8, 6, a, s_correct, 1e-13, 1e-13);
    }
}