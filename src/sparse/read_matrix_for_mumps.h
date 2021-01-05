#pragma once
#include <string>
#include <memory>
#include "triplet_for_mumps.h"

struct ReadMatrixForMumpsResults
{
    std::unique_ptr<TripletForMumps> trip;
    bool symmetric;
};

ReadMatrixForMumpsResults read_matrix_for_mumps(const std::string &filename, bool use_nist_mmio = false);
