#pragma once
#include "dmumps_c.h"
#include <string>

const MUMPS_INT MUMPS_USE_COMM_WORLD = -987654;
const MUMPS_INT MUMPS_HOST_ALSO_WORKS = 1;
const MUMPS_INT MUMPS_USE_DISTRIBUTED_MATRIX = 3;
const MUMPS_INT MUMPS_NO_COL_PERM_FOR_DISTR_MATRIX = 0;
const MUMPS_INT MUMPS_DEFAULT_PCT_INC_WORKSPACE = 20;

enum MumpsSymmetry
{
    MUMPS_SYMMETRY_NONE = 0,
    MUMPS_SYMMETRY_POS_DEF = 1,
    MUMPS_SYMMETRY_GENERAL = 2,
};

enum MumpsOrdering
{
    MUMPS_ORDERING_AMD = 0,
    MUMPS_ORDERING_AMF = 2,
    MUMPS_ORDERING_SCOTCH = 3,
    MUMPS_ORDERING_PORD = 4,
    MUMPS_ORDERING_METIS = 5,
    MUMPS_ORDERING_QAMD = 6,
    MUMPS_ORDERING_AUTO = 7,
};

enum MumpsScaling
{
    MUMPS_SCALING_NONE = 0,
    MUMPS_SCALING_DIAGONAL = 1,
    MUMPS_SCALING_COLUMN = 3,
    MUMPS_SCALING_ROWCOL = 4,
    MUMPS_SCALING_RC_ITERATIVE = 7,
    MUMPS_SCALING_RC_RIGOROUS = 8,
    MUMPS_SCALING_AUTO = 77,
};

enum MumpsJob
{
    MUMPS_JOB_INITIALIZE = -1,
    MUMPS_JOB_TERMINATE = -2,
    MUMPS_JOB_ANALIZE = 1,
    MUMPS_JOB_FACTORIZE = 2,
    MUMPS_JOB_SOLVE = 3,
    MUMPS_JOB_ANALIZE_AND_FACTORIZE = 4,
};

inline std::string mumps_ordering_to_string(MumpsOrdering ordering)
{
    switch (ordering)
    {
    case MUMPS_ORDERING_AMD:
        return "amd";

    case MUMPS_ORDERING_AMF:
        return "amf";

    case MUMPS_ORDERING_SCOTCH:
        return "scotch";

    case MUMPS_ORDERING_PORD:
        return "pord";

    case MUMPS_ORDERING_METIS:
        return "metis";

    case MUMPS_ORDERING_QAMD:
        return "qamd";

    case MUMPS_ORDERING_AUTO:
        return "auto";

    default:
        throw "mumps_ordering_to_string: ordering is invalid";
    }
}

inline MumpsOrdering mumps_string_to_ordering(const std::string &ordering)
{
    if (ordering == "amd")
    {
        return MUMPS_ORDERING_AMD;
    }

    if (ordering == "amf")
    {
        return MUMPS_ORDERING_AMF;
    }

    if (ordering == "scotch")
    {
        return MUMPS_ORDERING_SCOTCH;
    }

    if (ordering == "pord")
    {
        return MUMPS_ORDERING_PORD;
    }

    if (ordering == "metis")
    {
        return MUMPS_ORDERING_METIS;
    }

    if (ordering == "qamd")
    {
        return MUMPS_ORDERING_QAMD;
    }

    if (ordering == "auto")
    {
        return MUMPS_ORDERING_AUTO;
    }

    throw "mumps_string_to_ordering: ordering is invalid";
}