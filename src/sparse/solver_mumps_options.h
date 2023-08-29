#pragma once
#include <memory>

#include "dmumps_c.h"
#include "solver_mumps_constants.h"

struct MumpsOptions {
    MumpsSymmetry symmetry;      // kind of symmetry (or not)
    MumpsOrdering ordering;      // ICNTL(7)
    MumpsScaling scaling;        // ICNTL(8)
    MUMPS_INT pct_inc_workspace; // ICNTL(14)
    MUMPS_INT max_work_memory;   // ICNTL(23)
    MUMPS_INT omp_num_threads;   // ICNTL(16)
    bool distributed_matrix;     // matrix is distributed; not centralized on the host with rank == 0
    bool rhs_is_distributed;     // right-hand-side is distributed

    inline static std::unique_ptr<MumpsOptions> make_new(bool general_symmetry = false) {
        return std::unique_ptr<MumpsOptions>{new MumpsOptions{
            general_symmetry ? MUMPS_SYMMETRY_GENERAL : MUMPS_SYMMETRY_NONE,
            MUMPS_ORDERING_METIS,
            MUMPS_SCALING_AUTO,
            120,   // pct_inc_workspace
            0,     // auto
            1,     // omp_num_threads
            false, // distributed mat
            false, // distributed rhs
        }};
    };
};
