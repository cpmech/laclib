// mkl_wrapper implements lower-level linear algebra routines using MKL
// for maximum efficiency. This package uses column-major representation for matrices.
//
//   Example of col-major data:
//             _      _
//            |  0  3  |
//        A = |  1  4  |            ⇒     a = [0, 1, 2, 3, 4, 5]
//            |_ 2  5 _|(m x n)
//
//        a[i+j*m] = A[i][j]
//
//  NOTE: the functions here do not check for the limits of indices. Be careful.

#pragma once
#include "mkl.h"
#include <vector>

inline CBLAS_TRANSPOSE cTrans(bool trans)
{
    return trans ? CblasTrans : CblasNoTrans;
}

// set_num_threads sets the number of threads
void set_num_threads(int n)
{
    mkl_set_num_threads(n);
}

// ddot forms the dot product of two vectors. uses unrolled loops for increments equal to one.
//
//  See: http://www.netlib.org/lapack/explore-html/d5/df6/ddot_8f.html
//
double ddot(int n,
            const std::vector<double> &x,
            int incx,
            const std::vector<double> &y,
            int incy)
{
    return cblas_ddot(n,
                      x.data(),
                      incx,
                      y.data(),
                      incy);
}

// Dscal scales a vector by a constant. Uses unrolled loops for increment equal to 1.
//
//  See: http://www.netlib.org/lapack/explore-html/d4/dd0/dscal_8f.html
//
void dscal(int n,
           double alpha,
           std::vector<double> &x,
           int incx)
{
    cblas_dscal(n,
                alpha,
                x.data(),
                incx);
}

// Daxpy computes constant times a vector plus a vector.
//
//  See: http://www.netlib.org/lapack/explore-html/d9/dcd/daxpy_8f.html
//
//  See: https://software.intel.com/en-us/mkl-developer-reference-c-cblas-axpy
//
//  y += alpha*x + y
//
void daxpy(int n,
           double alpha,
           const std::vector<double> &x,
           int incx, std::vector<double> &y,
           int incy)
{
    cblas_daxpy(n,
                alpha,
                x.data(),
                incx,
                y.data(),
                incy);
}

// Dgemv performs one of the matrix-vector operations
//
//  See: http://www.netlib.org/lapack/explore-html/dc/da8/dgemv_8f.html
//
//  See: https://software.intel.com/en-us/mkl-developer-reference-c-cblas-gemv
//
//     y := alpha*A*x + beta*y,   or   y := alpha*A**T*x + beta*y,
//
//  where alpha and beta are scalars, x and y are vectors and A is an
//  m by n matrix.
//     trans=false     y := alpha*A*x + beta*y.
//
//     trans=true      y := alpha*A**T*x + beta*y.
//
void dgemv(bool trans,
           int m,
           int n,
           double alpha,
           const std::vector<double> &a,
           int lda,
           const std::vector<double> &x,
           int incx,
           double beta,
           std::vector<double> &y,
           int incy)
{
    cblas_dgemv(CblasColMajor,
                cTrans(trans),
                m,
                n,
                alpha,
                a.data(),
                lda,
                x.data(),
                incx,
                beta,
                y.data(),
                incy);
}

// Dgemm performs one of the matrix-matrix operations
//
//  false,false:  C_{m,n} := α ⋅ A_{m,k} ⋅ B_{k,n}  +  β ⋅ C_{m,n}
//  false,true:   C_{m,n} := α ⋅ A_{m,k} ⋅ B_{n,k}  +  β ⋅ C_{m,n}
//  true, false:  C_{m,n} := α ⋅ A_{k,m} ⋅ B_{k,n}  +  β ⋅ C_{m,n}
//  true, true:   C_{m,n} := α ⋅ A_{k,m} ⋅ B_{n,k}  +  β ⋅ C_{m,n}
//
//  see: http://www.netlib.org/lapack/explore-html/d7/d2b/dgemm_8f.html
//
//  see: https://software.intel.com/en-us/mkl-developer-reference-c-cblas-gemm
//
//     C := alpha*op( A )*op( B ) + beta*C,
//
//  where  op( X ) is one of
//
//     op( X ) = X   or   op( X ) = X**T,
//
//  alpha and beta are scalars, and A, B and C are matrices, with op( A )
//  an m by k matrix,  op( B )  a  k by n matrix and  C an m by n matrix.
//
void dgemm(bool transA,
           bool transB,
           int m,
           int n,
           int k,
           double alpha,
           const std::vector<double> &a,
           int lda,
           const std::vector<double> &b,
           int ldb,
           double beta,
           std::vector<double> &c,
           int ldc)
{
    cblas_dgemm(CblasColMajor,
                cTrans(transA),
                cTrans(transB),
                m,
                n,
                k,
                alpha,
                a.data(),
                lda,
                b.data(),
                ldb,
                beta,
                c.data(),
                ldc);
}

// Dgesv computes the solution to a real system of linear equations.
//
//  See: http://www.netlib.org/lapack/explore-html/d8/d72/dgesv_8f.html
//
//  See: https://software.intel.com/en-us/mkl-developer-reference-c-gesv
//
//  The system is:
//
//     A * X = B,
//
//  where A is an N-by-N matrix and X and B are N-by-NRHS matrices.
//
//  The LU decomposition with partial pivoting and row interchanges is
//  used to factor A as
//
//     A = P * L * U,
//
//  where P is a permutation matrix, L is unit lower triangular, and U is
//  upper triangular.  The factored form of A is then used to solve the
//  system of equations A * X = B.
//
//  NOTE: matrix 'a' will be modified
//
void dgesv(int n,
           int nrhs,
           std::vector<double> &a,
           int lda,
           std::vector<int> &ipiv,
           std::vector<double> &b,
           int ldb)
{
    if (ipiv.size() != n)
    {
        throw "ipiv.size must be equal to n.";
    }
    int info = LAPACKE_dgesv(
        LAPACK_COL_MAJOR,
        n,
        nrhs,
        a.data(),
        lda,
        ipiv.data(),
        b.data(),
        ldb);
    if (info != 0)
    {
        throw "LAPACK failed on dgesv";
    }
}