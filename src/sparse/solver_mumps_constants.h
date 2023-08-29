#pragma once
#include <string>

#include "dmumps_c.h"

const MUMPS_INT MUMPS_PAR_HOST_ALSO_WORKS = 1;     // section 5.1.4, page 26
const MUMPS_INT MUMPS_ICNTL5_ASSEMBLED_MATRIX = 0; // section 5.2.2, page 27
const MUMPS_INT MUMPS_ICNTL18_CENTRALIZED = 0;     // section 5.2.2, page 27
const MUMPS_INT MUMPS_ICNTL18_DISTRIBUTED = 3;     // section 5.2.2, page 28
const MUMPS_INT MUMPS_ICNTL6_PERMUT_NONE = 0;      // section 5.3, page 31
const MUMPS_INT MUMPS_ICNTL6_PERMUT_AUTO = 7;      // section 5.3, page 32
const MUMPS_INT MUMPS_ICNTL28_SEQUENTIAL = 1;      // section 5.4, page 33
const MUMPS_INT MUMPS_ICNTL28_PARALLEL = 2;        // section 5.4, page 34

enum MumpsSymmetry {
    MUMPS_SYMMETRY_NONE = 0,
    MUMPS_SYMMETRY_POS_DEF = 1,
    MUMPS_SYMMETRY_GENERAL = 2,
};

enum MumpsOrdering {
    MUMPS_ORDERING_AMD = 0,
    MUMPS_ORDERING_AMF = 2,
    MUMPS_ORDERING_SCOTCH = 3,
    MUMPS_ORDERING_PORD = 4,
    MUMPS_ORDERING_METIS = 5,
    MUMPS_ORDERING_QAMD = 6,
    MUMPS_ORDERING_AUTO = 7,
};

enum MumpsParallelOrdering {
    MUMPS_PARALLEL_ORDERING_AUTO = 0,
    MUMPS_PARALLEL_ORDERING_PTSCOTCH = 1,
    MUMPS_PARALLEL_ORDERING_PARMETIS = 2,
};

enum MumpsScaling {
    MUMPS_SCALING_NONE = 0,
    MUMPS_SCALING_DIAGONAL = 1,
    MUMPS_SCALING_COLUMN = 3,
    MUMPS_SCALING_ROWCOL = 4,
    MUMPS_SCALING_RC_ITERATIVE = 7,
    MUMPS_SCALING_RC_RIGOROUS = 8,
    MUMPS_SCALING_AUTO = 77,
};

enum MumpsJob {
    MUMPS_JOB_INITIALIZE = -1,
    MUMPS_JOB_TERMINATE = -2,
    MUMPS_JOB_ANALYZE = 1,
    MUMPS_JOB_FACTORIZE = 2,
    MUMPS_JOB_SOLVE = 3,
    MUMPS_JOB_ANALYZE_AND_FACTORIZE = 4,
};

inline std::string mumps_ordering_to_string(MumpsOrdering ordering) {
    switch (ordering) {
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

inline MumpsOrdering mumps_string_to_ordering(const std::string &ordering) {
    if (ordering == "amd") {
        return MUMPS_ORDERING_AMD;
    }

    if (ordering == "amf") {
        return MUMPS_ORDERING_AMF;
    }

    if (ordering == "scotch") {
        return MUMPS_ORDERING_SCOTCH;
    }

    if (ordering == "pord") {
        return MUMPS_ORDERING_PORD;
    }

    if (ordering == "metis") {
        return MUMPS_ORDERING_METIS;
    }

    if (ordering == "qamd") {
        return MUMPS_ORDERING_QAMD;
    }

    if (ordering == "auto") {
        return MUMPS_ORDERING_AUTO;
    }

    throw "mumps_string_to_ordering: ordering is invalid";
}

inline MumpsParallelOrdering mumps_ordering_to_parallel(MumpsOrdering ordering) {
    if (ordering == MUMPS_ORDERING_SCOTCH) {
        return MUMPS_PARALLEL_ORDERING_PTSCOTCH;
    }
    if (ordering == MUMPS_ORDERING_AUTO) {
        return MUMPS_PARALLEL_ORDERING_AUTO;
    }
    return MUMPS_PARALLEL_ORDERING_PARMETIS;
}
