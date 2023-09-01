#pragma once

#include <memory>
#include <vector>

#include "coo_matrix.h"

/// @brief Returns the (sparse) matrix-vector multiplication (scaled):
/// @param v Is the output vector
/// @param alpha Is the multiplier
/// @param a Is the input matrix (in triplet format, may have only half-band)
/// @param u Is the input vector
/// @param check_sizes Will check size(v)
/// @param fill_zeros Fill the dense vector v with zeros
/// @note v := alpha * a * u  =>  vi = alpha * aij * uj
void sp_mat_vec_mul(std::vector<double> &v,
                    double alpha,
                    const std::unique_ptr<SparseTriplet> &a,
                    const std::vector<double> &u,
                    bool check_sizes = true,
                    bool fill_zeros = true);
