#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../util/doctest.h"
#include "../util/print_vector.h"
#include "../check/check.h"
#include "auxiliary.h"
#include "conversions.h"
#include "mkl_double.h"
#include <cmath>
#include <complex>
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
    // 4 x 5 matrix
    auto a_mat = vecvec_to_colmaj(vector<vector<double>>{
        {1, 2, +0, 1, -1},
        {2, 3, -1, 1, +1},
        {1, 2, +0, 4, -1},
        {4, 0, +3, 1, +1},
    });

    // 5 x 4 matrix
    auto at_mat = vecvec_to_colmaj(vector<vector<double>>{
        {+1, +2, +1, +4},
        {+2, +3, +2, +0},
        {+0, -1, +0, +3},
        {+1, +1, +4, +1},
        {-1, +1, -1, +1},
    });

    // 5 x 3 matrix
    auto b_mat = vecvec_to_colmaj(vector<vector<double>>{
        {1, 0, 0},
        {0, 0, 3},
        {0, 0, 1},
        {1, 0, 1},
        {0, 2, 0},
    });

    // 4 x 3 matrix
    auto c_mat = vecvec_to_colmaj(vector<vector<double>>{
        {+0.50, 0, +0.25},
        {+0.25, 0, -0.25},
        {-0.25, 0, +0.00},
        {-0.25, 0, +0.00},
    });

    // 3 x 5 matrix
    auto bt_mat = vecvec_to_colmaj(vector<vector<double>>{
        {1, 0, 0, 1, 0},
        {0, 0, 0, 0, 2},
        {0, 3, 1, 1, 0},
    });

    // matrix for eigenvalues test
    auto a_ev = vecvec_to_colmaj(vector<vector<double>>{
        {+0.35, +0.45, -0.14, -0.17},
        {+0.09, +0.07, -0.54, +0.35},
        {-0.44, -0.33, -0.03, +0.17},
        {+0.25, -0.32, -0.13, +0.11},
    });

    // eigenvalues
    auto ww_correct = vector<complex<double>>{
        +7.994821225862098e-01,
        -9.941245329507467e-02 + 4.007924719897546e-01i,
        -9.941245329507467e-02 - 4.007924719897546e-01i,
        -1.006572159960587e-01,
    };

    // left eigenvectors
    auto vl0_correct = vector<complex<double>>{
        -6.244707486379453e-01,
        -5.994889025288728e-01,
        +4.999156725721429e-01,
        -2.708616172576073e-02,
    };
    auto vl1_correct = vector<complex<double>>{
        +5.330229831716200e-01,
        -2.666163325181558e-01 + 4.041362636762622e-01i,
        +3.455257668600027e-01 + 3.152853126680209e-01i,
        -2.540814367391268e-01 - 4.451133008385643e-01i,
    };
    auto vl2_correct = vector<complex<double>>{
        +5.330229831716200e-01,
        -2.666163325181558e-01 - 4.041362636762622e-01i,
        +3.455257668600027e-01 - 3.152853126680209e-01i,
        -2.540814367391268e-01 + 4.451133008385643e-01i,
    };
    auto vl3_correct = vector<complex<double>>{
        +6.641410231734539e-01,
        -1.068153340034493e-01,
        +7.293254091191846e-01,
        +1.248664621625170e-01,
    };

    // right eigenvectors
    auto vr0_correct = vector<complex<double>>{
        -6.550887675124076e-01,
        -5.236294609021240e-01,
        +5.362184613722345e-01,
        -9.560677820122976e-02,
    };
    auto vr1_correct = vector<complex<double>>{
        -1.933015482642217e-01 + 2.546315719275843e-01i,
        +2.518565317267399e-01 - 5.224047347116287e-01i,
        +9.718245844328152e-02 - 3.083837558972283e-01i,
        +6.759540542547480e-01,
    };
    auto vr2_correct = vector<complex<double>>{
        -1.933015482642217e-01 - 2.546315719275843e-01i,
        +2.518565317267399e-01 + 5.224047347116287e-01i,
        +9.718245844328152e-02 + 3.083837558972283e-01i,
        +6.759540542547480e-01,
    };
    auto vr3_correct = vector<complex<double>>{
        +1.253326972309026e-01,
        +3.320222155717508e-01,
        +5.938377595573312e-01,
        +7.220870298624550e-01,
    };

    SUBCASE("dcopy")
    {
        auto x = vector<double>{20, 10, 30, 123, 123};
        auto y = vector<double>(x.size(), 0.0);
        int n = 3;
        int incx = 1;
        int incy = 1;
        dcopy(n, x, incx, y, incy);
        auto y_correct = vector<double>{20, 10, 30, 0, 0};
        CHECK(equal_vectors_tol(y, y_correct, 1e-15));
    }

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

    SUBCASE("dnrm2")
    {
        auto x = vector<double>{1, 2, 3, 4, 123, 123};
        int n = 4;
        int incx = 1;
        auto res = dnrm2(n, x, incx);
        double correct = sqrt(30.0);
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

    SUBCASE("dgeev 1")
    {
        int n = 4;
        int lda = n;

        auto wr = vector<double>(n, 0.0);     // eigen values (real part)
        auto wi = vector<double>(n, 0.0);     // eigen values (imaginary part)
        auto vl = vector<double>(n * n, 0.0); // left eigenvectors
        auto vr = vector<double>(n * n, 0.0); // right eigenvectors

        int ldvl = n;
        int ldvr = n;

        bool calc_vl = true;
        bool calc_vr = true;

        dgeev(calc_vl, calc_vr, n, a_ev, lda, wr, wi, vl, ldvl, vr, ldvr);

        auto zero = complex<double>(0, 0);
        auto ww = vector<complex<double>>(n, zero);
        auto vvl = vector<complex<double>>(n * n, zero);
        auto vvr = vector<complex<double>>(n * n, zero);
        build_dgeev_complex_output(ww, vvl, vvr, wr, wi, vl, vr);

        // check eigenvalues
        CHECK(equal_complex_vectors_tol(ww, ww_correct, 1e-15, 1e-15));

        // check left eigenvectors
        CHECK(equal_complex_vectors_tol(colmaj_extract_col(0, n, n, vvl), vl0_correct, 1e-15, 1e-15));
        CHECK(equal_complex_vectors_tol(colmaj_extract_col(1, n, n, vvl), vl1_correct, 1e-15, 1e-15));
        CHECK(equal_complex_vectors_tol(colmaj_extract_col(2, n, n, vvl), vl2_correct, 1e-15, 1e-15));
        CHECK(equal_complex_vectors_tol(colmaj_extract_col(3, n, n, vvl), vl3_correct, 1e-15, 1e-15));

        // check right eigenvectors
        CHECK(equal_complex_vectors_tol(colmaj_extract_col(0, n, n, vvr), vr0_correct, 1e-15, 1e-15));
        CHECK(equal_complex_vectors_tol(colmaj_extract_col(1, n, n, vvr), vr1_correct, 1e-15, 1e-15));
        CHECK(equal_complex_vectors_tol(colmaj_extract_col(2, n, n, vvr), vr2_correct, 1e-15, 1e-15));
        CHECK(equal_complex_vectors_tol(colmaj_extract_col(3, n, n, vvr), vr3_correct, 1e-15, 1e-15));
    }

    SUBCASE("dgeev 2 (eigenvalues only)")
    {
        int n = 4;
        int lda = n;

        auto wr = vector<double>(n, 0.0); // eigen values (real part)
        auto wi = vector<double>(n, 0.0); // eigen values (imaginary part)
        auto dummy = vector<double>();

        const int DUMMY = 1;

        bool calc_vl = false;
        bool calc_vr = false;

        dgeev(calc_vl, calc_vr, n, a_ev, lda, wr, wi, dummy, DUMMY, dummy, DUMMY);

        auto zero = complex<double>(0, 0);
        auto ww = vector<complex<double>>(n, zero);
        for (size_t i = 0; i < n; i++)
        {
            ww[i] = std::complex<double>(wr[i], wi[i]);
        }

        CHECK(equal_complex_vectors_tol(ww, ww_correct, 1e-15, 1e-15));
    }

    SUBCASE("dger a = 100 + 0.5⋅u⋅vᵀ")
    {
        auto a = vecvec_to_colmaj(vector<vector<double>>{
            {100, 100, 100},
            {100, 100, 100},
            {100, 100, 100},
            {100, 100, 100},
        });
        auto u = vector<double>{1, 2, 3, 4};
        auto v = vector<double>{4, 3, 2};

        int m = 4; // m = nrow(a) = len(u)
        int n = 3; // n = ncol(a) = len(v)

        double alpha = 0.5;
        int lda = 4;
        dger(m, n, alpha, u, 1, v, 1, a, lda);

        auto a_correct = vecvec_to_colmaj(vector<vector<double>>{
            {102, 101.5, 101},
            {104, 103.0, 102},
            {106, 104.5, 103},
            {108, 106.0, 104},
        });
        CHECK(equal_vectors_tol(a, a_correct, 1e-15));
    }

    SUBCASE("dgetrf and dgetri")
    {
        auto a = vecvec_to_colmaj(vector<vector<double>>{
            {1, 2, +0, 1},
            {2, 3, -1, 1},
            {1, 2, +0, 4},
            {4, 0, +3, 1},
        });
        int m = 4;
        int n = 4;

        int lda = m;
        int min_mn = m < n ? m : n;
        auto ipiv = vector<int>(min_mn);
        dgetrf(m, n, a, lda, ipiv);

        auto ipiv_correct = vector<int>{4, 2, 3, 4};
        auto lu = vecvec_to_colmaj(vector<vector<double>>{
            {+4.0e+00, +0.000000000000000e+00, +3.000000000000000e+00, +1.000000000000000e+00},
            {+5.0e-01, +3.000000000000000e+00, -2.500000000000000e+00, +5.000000000000000e-01},
            {+2.5e-01, +6.666666666666666e-01, +9.166666666666665e-01, +3.416666666666667e+00},
            {+2.5e-01, +6.666666666666666e-01, +1.000000000000000e+00, -3.000000000000000e+00},
        });

        CHECK(equal_vectors(ipiv, ipiv_correct));
        CHECK(equal_vectors_tol(a, lu, 1e-15));

        dgetri(n, a, lda, ipiv);

        auto a_inverse = vecvec_to_colmaj(vector<vector<double>>{
            {-8.484848484848487e-01, +5.454545454545455e-01, +3.030303030303039e-02, +1.818181818181818e-01},
            {+1.090909090909091e+00, -2.727272727272728e-01, -1.818181818181817e-01, -9.090909090909091e-02},
            {+1.242424242424243e+00, -7.272727272727273e-01, -1.515151515151516e-01, +9.090909090909088e-02},
            {-3.333333333333333e-01, +0.000000000000000e+00, +3.333333333333333e-01, +0.000000000000000e+00},
        });

        CHECK(equal_vectors_tol(a, a_inverse, 1e-15));
    }

    SUBCASE("dpotrf")
    {
        auto a_up = vecvec_to_colmaj(vector<vector<double>>{
            {+3, +0, -3, +0},
            {+0, +3, +1, +2},
            {+0, +0, +4, +1},
            {+0, +0, +0, +3},
        });

        int n = 4;
        bool up = true;
        int lda = n;
        dpotrf(up, n, a_up, lda);

        auto a_up_correct = vecvec_to_colmaj(vector<vector<double>>{
            {+1.732050807568877e+00, +0.000000000000000e+00, -1.732050807568878e+00, +0.000000000000000e+00},
            {+0.000000000000000e+00, +1.732050807568877e+00, +5.773502691896258e-01, +1.154700538379252e+00},
            {+0.000000000000000e+00, +0.000000000000000e+00, +8.164965809277251e-01, +4.082482904638632e-01},
            {+0.000000000000000e+00, +0.000000000000000e+00, +0.000000000000000e+00, +1.224744871391589e+00},
        });

        CHECK(equal_vectors_tol(a_up, a_up_correct, 1e-15));

        auto a_lo = vecvec_to_colmaj(vector<vector<double>>{
            {+3, +0, +0, +0},
            {+0, +3, +0, +0},
            {-3, +1, +4, +0},
            {+0, +2, +1, +3},
        });

        up = false;
        dpotrf(up, n, a_lo, lda);

        auto a_lo_correct = vecvec_to_colmaj(vector<vector<double>>{
            {+1.732050807568877e+00, +0.000000000000000e+00, +0.000000000000000e+00, +0.000000000000000e+00},
            {+0.000000000000000e+00, +1.732050807568877e+00, +0.000000000000000e+00, +0.000000000000000e+00},
            {-1.732050807568878e+00, +5.773502691896258e-01, +8.164965809277251e-01, +0.000000000000000e+00},
            {+0.000000000000000e+00, +1.154700538379252e+00, +4.082482904638632e-01, +1.224744871391589e+00},
        });

        CHECK(equal_vectors_tol(a_lo, a_lo_correct, 1e-15));
    }
}