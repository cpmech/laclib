#pragma once
#include <memory>
#include "dmumps_c.h"
#include "triplet_for_mumps.h"

struct SolverMumps
{
    DMUMPS_STRUC_C data;

    void init(const TripletForMumps &trip);
};

std::unique_ptr<SolverMumps> solver_mumps_new();
