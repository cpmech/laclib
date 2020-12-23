#pragma once
#include "dmumps_c.h"
#include "solver_mumps_constants.h"

struct MumpsOptions
{
    MumpsOrdering ordering;      // ICNTL(7)
    MumpsScaling scaling;        // ICNTL(8)
    MUMPS_INT pct_inc_workspace; // ICNTL(14)
    MUMPS_INT max_work_memory;   // ICNTL(23)
    bool rhs_is_distributed;

    inline static MumpsOptions make_new()
    {
        return {
            MUMPS_ORDERING_AUTO,
            MUMPS_SCALING_AUTO,
            MUMPS_DEFAULT_PCT_INC_WORKSPACE,
            0, // auto
            false,
        };
    };
};