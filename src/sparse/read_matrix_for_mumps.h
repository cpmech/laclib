#pragma once
#include <string>
#include <memory>
#include "triplet_for_mumps.h"

struct ReadMatrixForMumpsResults
{
    std::unique_ptr<TripletForMumps> trip;
    bool symmetric;
};

ReadMatrixForMumpsResults read_matrix_for_mumps(std::string filename);
