#pragma once
#include <string>
#include <memory>
#include "triplet.h"

struct ReadMatrixResults
{
    std::unique_ptr<Triplet> trip;
    bool symmetric;
};

ReadMatrixResults read_matrix(std::string filename, bool mirrorIfSym);
