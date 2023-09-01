#pragma once

#include <cmath>
#include <iostream>

template <typename T>
inline bool equal_arrays(size_t dim, const T a[], const T b[]) {
    for (size_t i = 0; i < dim; i++) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}

template <typename T>
inline bool equal_arrays_tol(size_t dim, const T a[], const T b[], T tolerance, bool verbose = false) {
    for (size_t i = 0; i < dim; i++) {
        if (fabs(double(a[i]) - double(b[i])) > tolerance) {
            if (verbose) {
                double diff = fabs(double(a[i]) - double(b[i]));
                std::cout << a[i] << " != " << b[i] << " diff = " << diff << std::endl;
            }
            return false;
        }
    }
    return true;
}
