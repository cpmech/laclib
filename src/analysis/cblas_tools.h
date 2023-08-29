#pragma once

#include <cmath>
#include <vector>

#ifdef USE_MKL
#include "mkl.h"
#else
#include "cblas.h"
#endif

// Sets the number of threads
inline void set_num_threads(int n) {
#ifdef USE_MKL
    mkl_set_num_threads(n);
#else
    openblas_set_num_threads(n);
#endif
}

// Finds the max absolute value
inline double max_abs_value(const std::vector<double> &x) {
    auto idx_max_abs = cblas_idamax(x.size(), x.data(), 1);
    return fabs(x[idx_max_abs]);
}

// Calculates y := alpha * x + y
inline void daxpy(int n,
                  double alpha,
                  const std::vector<double> &x,
                  std::vector<double> &y) {
    cblas_daxpy(n, alpha, x.data(), 1, y.data(), 1);
}
