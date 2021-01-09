#pragma once
#include <memory>
#include <vector>
#include "triplet_for_mumps.h"

// sp_matvecmul returns the (sparse) matrix-vector multiplication (scaled):
//  v := alpha * a * u  =>  vi = alpha * aij * uj
//  NOTE: the dense vector v will be first initialised with zeros
void sp_matvecmul(std::vector<double> &v,
                  double alpha,
                  const std::unique_ptr<TripletForMumps> &a,
                  const std::vector<double> &u);