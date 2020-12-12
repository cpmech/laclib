#pragma once
#include <memory>
#include "dmumps_c.h"

struct SolverMumps
{
    DMUMPS_STRUC_C data;
};

std::unique_ptr<SolverMumps> solver_mumps_new();
