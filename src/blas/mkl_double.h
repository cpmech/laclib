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
inline void set_num_threads(int n)
{
    mkl_set_num_threads(n);
}

// dcopy copies a vector, x, to a vector, y. uses unrolled loops for increments equal to 1.
//
//  See: http://www.netlib.org/lapack/explore-html/da/d6c/dcopy_8f.html
//
inline void dcopy(int n,
                  const std::vector<double> &x,
                  int incx,
                  std::vector<double> &y,
                  int incy)
{
    cblas_dcopy(n,
                x.data(),
                incx,
                y.data(),
                incy);
}

// ddot forms the dot product of two vectors. uses unrolled loops for increments equal to one.
//
//  See: http://www.netlib.org/lapack/explore-html/d5/df6/ddot_8f.html
//
inline double ddot(int n,
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

// dnrm2 returns the euclidean norm of a vector via the function name, so that
//
//   dnrm2 := sqrt( x'*x )
//
//   See http://www.netlib.org/lapack/explore-html/da/d7f/dnrm2_8f.html
//
inline double dnrm2(int n,
                    const std::vector<double> &x,
                    int incx)
{
    return cblas_dnrm2(n,
                       x.data(),
                       incx);
}

// dscal scales a vector by a constant. Uses unrolled loops for increment equal to 1.
//
//  See: http://www.netlib.org/lapack/explore-html/d4/dd0/dscal_8f.html
//
inline void dscal(int n,
                  double alpha,
                  std::vector<double> &x,
                  int incx)
{
    cblas_dscal(n,
                alpha,
                x.data(),
                incx);
}

// daxpy computes constant times a vector plus a vector.
//
//  See: http://www.netlib.org/lapack/explore-html/d9/dcd/daxpy_8f.html
//
//  See: https://software.intel.com/en-us/mkl-developer-reference-c-cblas-axpy
//
//  y += alpha*x + y
//
inline void daxpy(int n,
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

// dgemv performs one of the matrix-vector operations
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
inline void dgemv(bool trans,
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

// dgemm performs one of the matrix-matrix operations
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
inline void dgemm(bool transA,
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

// dgesv computes the solution to a real system of linear equations.
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
inline void dgesv(int n,
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

// dgesvd computes the singular value decomposition (SVD) of a real M-by-N matrix A, optionally computing the left and/or right singular vectors.
//
//  See: http://www.netlib.org/lapack/explore-html/d8/d2d/dgesvd_8f.html
//
//  See: https://software.intel.com/en-us/mkl-developer-reference-c-gesvd
//
//  The SVD is written
//
//       A = U * SIGMA * transpose(V)
//
//  where SIGMA is an M-by-N matrix which is zero except for its
//  min(m,n) diagonal elements, U is an M-by-M orthogonal matrix, and
//  V is an N-by-N orthogonal matrix.  The diagonal elements of SIGMA
//  are the singular values of A; they are real and non-negative, and
//  are returned in descending order.  The first min(m,n) columns of
//  U and V are the left and right singular vectors of A.
//
//  Note that the routine returns V**T, not V.
//
//  NOTE: matrix 'a' will be modified
//
//  jobu
//    CHARACTER*1. Must be 'A', 'S', 'O', or 'N'.
//    Specifies options for computing all or part of the matrix U.
//    If jobu = 'A', all m columns of U are returned in the array u;
//    if jobu = 'S', the first min(m, n) columns of U (the left singular vectors) are returned in the array u;
//    if jobu = 'O', the first min(m, n) columns of U (the left singular vectors) are overwritten on the array a;
//    if jobu = 'N', no columns of U (no left singular vectors) are computed.
//  jobvt
//    CHARACTER*1. Must be 'A', 'S', 'O', or 'N'.
//    Specifies options for computing all or part of the matrix VT/VH.
//    If jobvt = 'A', all n rows of VT/VH are returned in the array vt;
//    if jobvt = 'S', the first min(m,n) rows of VT/VH (the right singular vectors) are returned in the array vt;
//    if jobvt = 'O', the first min(m,n) rows of VT/VH) (the right singular vectors) are overwritten on the array a;
//    if jobvt = 'N', no rows of VT/VH (no right singular vectors) are computed.
//  jobvt and jobu cannot both be 'O'.
//
inline void dgesvd(char jobu,
                   char jobvt,
                   int m,
                   int n,
                   std::vector<double> &a,
                   int lda,
                   std::vector<double> &s,
                   std::vector<double> &u,
                   int ldu,
                   std::vector<double> &vt,
                   int ldvt,
                   std::vector<double> &superb)
{
    int info = LAPACKE_dgesvd(
        LAPACK_COL_MAJOR,
        jobu,
        jobvt,
        m,
        n,
        a.data(),
        lda,
        s.data(),
        u.data(),
        ldu,
        vt.data(),
        ldvt,
        superb.data());
    if (info != 0)
    {
        throw "LAPACK failed on dgesvd";
    }
}

// dgeev computes for an N-by-N real nonsymmetric matrix A, the
// eigenvalues and, optionally, the left and/or right eigenvectors.
//
//  See: http://www.netlib.org/lapack/explore-html/d9/d28/dgeev_8f.html
//
//  See: https://software.intel.com/en-us/mkl-developer-reference-c-geev
//
//  See: https://www.nag.co.uk/numeric/fl/nagdoc_fl26/html/f08/f08naf.html
//
//  The right eigenvector v(j) of A satisfies
//
//                   A * v(j) = lambda(j) * v(j)
//
//  where lambda(j) is its eigenvalue.
//
//  The left eigenvector u(j) of A satisfies
//
//                u(j)**H * A = lambda(j) * u(j)**H
//
//  where u(j)**H denotes the conjugate-transpose of u(j).
//
//  The computed eigenvectors are normalized to have Euclidean norm
//  equal to 1 and largest component real.
//
//  jobvl
//    CHARACTER*1. Must be 'N' or 'V'.
//    If jobvl = 'N', then left eigenvectors of A are not computed.
//    If jobvl = 'V', then left eigenvectors of A are computed.
//  jobvr
//    CHARACTER*1. Must be 'N' or 'V'.
//    If jobvr = 'N', then right eigenvectors of A are not computed.
//    If jobvr = 'V', then right eigenvectors of A are computed.
//
void dgeev(bool calc_vl,
           bool calc_vr,
           int n,
           std::vector<double> &a,
           int lda,
           std::vector<double> &wr,
           std::vector<double> &wi,
           std::vector<double> &vl,
           int ldvl,
           std::vector<double> &vr,
           int ldvr)
{
    char jobvl = 'N';
    char jobvr = 'N';
    double *vl_effective = NULL;
    double *vr_effective = NULL;
    int ldvl_effective = 1;
    int ldvr_effective = 1;
    if (calc_vl)
    {
        jobvl = 'V';
        vl_effective = vl.data();
        ldvl_effective = ldvl;
    }
    if (calc_vr)
    {
        jobvr = 'V';
        vr_effective = vr.data();
        ldvr_effective = ldvr;
    }
    int info = LAPACKE_dgeev(
        LAPACK_COL_MAJOR,
        jobvl,
        jobvr,
        n,
        a.data(),
        lda,
        wr.data(),
        wi.data(),
        vl_effective,
        ldvl_effective,
        vr_effective,
        ldvr_effective);
    if (info != 0)
    {
        throw "LAPACK failed on dgesvd on dgeev";
    }
}

// build_dgeev_complex_output builds the complex left and right
// eigenvectors resulting from the dgeev function
//
//  INPUT:
//   wr, wi -- real and imag parts of eigenvalues
//   vl, vr -- left and right eigenvectors from dgeev
//
//  OUTPUT:
//   ww -- complex eigenvalues
//   vvl, vvr -- complex version of left and right eigenvectors [pre-allocated]
//
//  NOTE (no checks made)
//   n = wr.size() = wi.size() = vl.size() = vr.size()
//   n*n = vvl.size() = vvr.size()
//
void build_dgeev_complex_output(std::vector<std::complex<double>> &ww,
                                std::vector<std::complex<double>> &vvl,
                                std::vector<std::complex<double>> &vvr,
                                const std::vector<double> &wr,
                                const std::vector<double> &wi,
                                const std::vector<double> &vl,
                                const std::vector<double> &vr)
{
    // eigenvalues
    size_t n = wr.size();
    for (size_t i = 0; i < n; i++)
    {
        ww[i] = std::complex<double>(wr[i], wi[i]);
    }

    // loop over columns == eigenvalues
    int dj = 1; // increment for next conjugate pair
    for (size_t j = 0; j < n; j += dj)
    {
        // eigenvalue is complex
        if (fabs(wi[j]) > 0.0)
        {
            // check
            if (j > n - 2)
            {
                throw "dgeev_complex_output: last eigenvalue cannot be complex";
            }

            // loop over rows
            for (size_t i = 0; i < n; i++)
            {
                size_t p = i + j * n;
                size_t q = i + (j + 1) * n;
                vvl[p] = std::complex<double>(vl[p], vl[q]);
                vvr[p] = std::complex<double>(vr[p], vr[q]);
                vvl[q] = std::complex<double>(vl[p], -vl[q]);
                vvr[q] = std::complex<double>(vr[p], -vr[q]);
            }
            dj = 2;
        }

        // eigenvalue is real only
        else
        {
            // loop over rows
            for (size_t i = 0; i < n; i++)
            {
                size_t p = i + j * n;
                vvl[p] = std::complex<double>(vl[p], 0.0);
                vvr[p] = std::complex<double>(vr[p], 0.0);
            }
            dj = 1;
        }
    }
}