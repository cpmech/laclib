#pragma once

#ifdef USE_MKL
#include "mkl.h"
#define INT_SIZE MKL_INT
#else
#define INT_SIZE int
#endif

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
