#pragma once
#include <string>
#include <memory>
#include "sparse_triplet.h"

std::unique_ptr<SparseTriplet> read_matrix_market(const std::string &filename,
                                                  int mpi_rank = 0,
                                                  int mpi_size = 1);
