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

#include "mkl.h"
#include <vector>

// set_num_threads sets the number of threads
inline void set_num_threads(int n)
{
    mkl_set_num_threads(n);
}

// ddot forms the dot product of two vectors. uses unrolled loops for increments equal to one.
//
//  See: http://www.netlib.org/lapack/explore-html/d5/df6/ddot_8f.html
//
inline double ddot(int n, const std::vector<double> &x, int incx, const std::vector<double> &y, int incy)
{
    return cblas_ddot(n, x.data(), incx, y.data(), incy);
}