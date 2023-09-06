#pragma once

#include <cmath>
#include <vector>

#ifdef USE_MKL
#include "mkl.h"
#define INT_SIZE MKL_INT
#else
#include "cblas.h"
#define INT_SIZE int
#endif

#include "matrix.h"

/// @brief Casts a size_t integer to INT and checks if it worked
/// @param a is the size_t integer
/// @return the MKL_INT integer
inline INT_SIZE int_from_size_t(size_t a) {
    INT_SIZE n = static_cast<INT_SIZE>(a);
    size_t temp = static_cast<size_t>(n);
    if (a != temp) {
        throw "int_from_size_t failed with integer overflow";
    }
    return n;
}

/// @brief Sets the number of threads
inline void set_num_threads(int n) {
#ifdef USE_MKL
    mkl_set_num_threads(n);
#else
    openblas_set_num_threads(n);
#endif
}

/// @brief Finds the max absolute value
inline double max_abs_value(const std::vector<double> &x) {
    auto idx_max_abs = cblas_idamax(x.size(), x.data(), 1);
    return fabs(x[idx_max_abs]);
}

/// @brief Calculates y := alpha * x + y
/// @note This function throws errors if the arguments are incompatible
inline void daxpy(int n,
                  double alpha,
                  const std::vector<double> &x,
                  std::vector<double> &y) {
    cblas_daxpy(n, alpha, x.data(), 1, y.data(), 1);
}

/// @brief Performs the matrix-vector multiplication resulting in a vector
/// @note This function throws errors if the arguments are incompatible
void mat_vec_mul(std::vector<double> &v,
                 double alpha,
                 const std::unique_ptr<Matrix> &a,
                 std::vector<double> &u) {
    auto m = v.size();
    auto n = u.size();
    if (m != a->nrow || n != a->ncol) {
        throw "matrix and vectors are incompatible";
    }
    if (m == 0 || n == 0) {
        return;
    }
    INT_SIZE m_mkl = int_from_size_t(m);
    INT_SIZE n_mkl = int_from_size_t(n);
    cblas_dgemv(
        CblasColMajor,
        CblasNoTrans,
        m_mkl,
        n_mkl,
        alpha,
        a->data.data(),
        m,
        u.data(),
        1,
        0.0,
        v.data(),
        1);
}
