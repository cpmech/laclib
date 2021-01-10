#pragma once
#include <memory>
#include <vector>
#include "sparse_triplet.h"

// sp_matvecmul returns the (sparse) matrix-vector multiplication (scaled):
//  v := alpha * a * u  =>  vi = alpha * aij * uj
// INPUT:
//   v -- the output vector
//   alpha -- the multiplier
//   a -- the input matrix (in triplet format, may have only half-band)
//   u -- the input vector
//   check_sizes -- will check size(v)
//   fill_zeros -- fill the dense vector v with zeros
void sp_matvecmul(std::vector<double> &v,
                  double alpha,
                  const std::unique_ptr<SparseTriplet> &a,
                  const std::vector<double> &u,
                  bool check_sizes = true,
                  bool fill_zeros = true);
