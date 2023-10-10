#pragma once

#include <cmath>
#include <vector>

#include "mkl.h"
#define INT_SIZE MKL_INT

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
    mkl_set_num_threads(n);
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

/// @brief Performs the matrix-vector multiplication
/// @note This function throws errors if the arguments are incompatible
inline void mat_vec_mul(std::vector<double> &v,
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
    INT_SIZE m_int = int_from_size_t(m);
    INT_SIZE n_int = int_from_size_t(n);
    cblas_dgemv(
        CblasColMajor,
        CblasNoTrans,
        m_int,
        n_int,
        alpha,
        a->data.data(),
        m,
        u.data(),
        1,
        0.0,
        v.data(),
        1);
}

/// @brief Performs the matrix-matrix multiplication
/// @note This function throws errors if the arguments are incompatible
inline void mat_mat_mul(const std::unique_ptr<Matrix> &c,
                        double alpha,
                        const std::unique_ptr<Matrix> &a,
                        const std::unique_ptr<Matrix> &b) {
    // trans_a = false, trans_b = false:
    //
    //   c  := α ⋅  a  ⋅  b  +  β ⋅  c
    // (m,n)      (m,k) (k,n)     (m,n)
    //
    auto m = c->nrow;
    auto n = c->ncol;
    auto k = a->ncol;
    if (a->nrow != m || b->nrow != k || b->ncol != n) {
        throw "matrices are incompatible";
    }
    if (m == 0 || n == 0) {
        return;
    }
    auto m_int = int_from_size_t(m);
    auto n_int = int_from_size_t(n);
    auto k_int = int_from_size_t(k);
    auto lda = m_int;
    auto ldb = k_int;
    cblas_dgemm(
        CblasColMajor,
        CblasNoTrans,
        CblasNoTrans,
        m_int,
        n_int,
        k_int,
        alpha,
        a->data.data(),
        lda,
        b->data.data(),
        ldb,
        0.0,
        c->data.data(),
        m);
}

/// @brief Performs the transpose(matrix)-matrix multiplication
/// @note This function throws errors if the arguments are incompatible
inline void mat_t_mat_mul(const std::unique_ptr<Matrix> &c,
                          double alpha,
                          const std::unique_ptr<Matrix> &a,
                          const std::unique_ptr<Matrix> &b) {
    // trans_a = true, trans_b = false:
    //
    //   c  := α ⋅  aᵀ  ⋅  b  +  β ⋅  c
    // (m,n)      (m,k) (k,n)      (m,n)
    //          a:(k,m)
    //
    auto m = c->nrow;
    auto n = c->ncol;
    auto k = a->nrow;
    if (a->ncol != m || b->nrow != k || b->ncol != n) {
        throw "matrices are incompatible";
    }
    if (m == 0 || n == 0) {
        return;
    }
    auto m_int = int_from_size_t(m);
    auto n_int = int_from_size_t(n);
    auto k_int = int_from_size_t(k);
    auto lda = k_int;
    auto ldb = k_int;
    cblas_dgemm(
        CblasColMajor,
        CblasTrans,
        CblasNoTrans,
        m_int,
        n_int,
        k_int,
        alpha,
        a->data.data(),
        lda,
        b->data.data(),
        ldb,
        0.0,
        c->data.data(),
        m);
}
