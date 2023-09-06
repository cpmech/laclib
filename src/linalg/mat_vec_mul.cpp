#include <vector>

#ifdef USE_MKL
#include "mkl_cblas.h"
#else
#include "cblas.h"
#endif

#include "auxiliary.h"
#include "mat_vec_mul.h"
#include "matrix.h"

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
