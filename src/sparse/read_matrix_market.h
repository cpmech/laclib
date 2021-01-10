#pragma once
#include <string>
#include <memory>
#include "sparse_triplet.h"

// NOTE: use onebased = true for MUMPS
//       because MUMPS uses arrays (I; J) with one-based indices
std::unique_ptr<SparseTriplet> read_matrix_market(const std::string &filename,
                                                  bool onebased = false,
                                                  int mpi_rank = 0,
                                                  int mpi_size = 1);
