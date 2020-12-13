#pragma once
#include <memory>
#include "dmumps_c.h"
#include "triplet_for_mumps.h"

const MUMPS_INT MUMPS_USE_COMM_WORLD = -987654;
const MUMPS_INT MUMPS_JOB_INIT = -1;

enum MumpsSymmetry
{
    SYMMETRY_NONE = 0,
    SYMMETRY_POS_DEF = 1,
    SYMMETRY_GENERAL = 2,
};

enum MumpsOrdering
{
    ORDERING_AMD = 0,
    ORDERING_AMF = 2,
    ORDERING_SCOTCH = 3,
    ORDERING_PORD = 4,
    ORDERING_METIS = 5,
    ORDERING_QAMD = 6,
    ORDERING_AUTO = 7,
};

enum MumpsScaling
{
    SCALING_NONE = 0,
    SCALING_DIAGONAL = 1,
    SCALING_COLUMN = 3,
    SCALING_ROWCOL = 4,
    SCALING_RC_ITERATIVE = 7,
    SCALING_RC_RIGOROUS = 8,
    SCALING_AUTO = 77,
};

struct MumpsOptions
{
    bool verbose;
    MumpsSymmetry symmetry;
    MumpsOrdering ordering;
    MumpsScaling scaling;

    inline static MumpsOptions make_new()
    {
        return {
            false,
            SYMMETRY_NONE,
            ORDERING_AUTO,
            SCALING_AUTO,
        };
    };
};

struct MumpsSolver
{
    DMUMPS_STRUC_C data;

    inline static std::unique_ptr<MumpsSolver> make_new()
    {
        DMUMPS_STRUC_C data;

        data.comm_fortran = MUMPS_USE_COMM_WORLD;

        return std::unique_ptr<MumpsSolver>{
            new MumpsSolver{
                data,
            }};
    };

    void init(TripletForMumps &trip, MumpsOptions &options);
};
