#pragma once
#include <cmath>
#include <vector>

#include "cblas.h"

// set_num_threads sets the number of threads
inline void set_num_threads(int n) {
    openblas_set_num_threads(n);
}

// computes inf norm
inline double norm_inf(const std::vector<double> &x) {
    auto idx_max_abs = cblas_idamax(x.size(), x.data(), 1);
    return fabs(x[idx_max_abs]);
}

// performs y := alpha * x + y
inline void daxpy(int n,
                  double alpha,
                  const std::vector<double> &x,
                  int incx, std::vector<double> &y,
                  int incy) {
    cblas_daxpy(n, alpha, x.data(), incx, y.data(), incy);
}
