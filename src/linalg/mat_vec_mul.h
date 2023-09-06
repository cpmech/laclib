#pragma once

#include "matrix.h"
#include <vector>

/// @brief Performs the matrix-vector multiplication resulting in a vector
/// @note This function throws errors if the arguments are incompatible
void mat_vec_mul(std::vector<double> &v,
                 double alpha,
                 const std::unique_ptr<Matrix> &a,
                 std::vector<double> &u);
