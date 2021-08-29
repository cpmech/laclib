#pragma once
#include <memory>
#include <string>

#include "sparse_triplet.h"

enum PartitionOption {
    PARTITION_BY_NNZ,
    PARTITION_BY_ROW,
    PARTITION_BY_COL,
};

// NOTE: use onebased = true for MUMPS
//       because MUMPS uses arrays (I; J) with one-based indices
std::unique_ptr<SparseTriplet> read_matrix_market(const std::string &filename,
                                                  bool onebased = false);
