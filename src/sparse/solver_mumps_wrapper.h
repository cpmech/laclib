#pragma once
#include "dmumps_c.h"
#include "solver_mumps_constants.h"
#include "solver_mumps_options.h"
#include <iostream>
#include <string>

#define ICNTL(I) icntl[(I)-1] // macro to make indices match documentation
#define INFOG(I) infog[(I)-1] // macro to make indices match documentation

inline void handle_verbose(DMUMPS_STRUC_C *data, bool verbose)
{
    if (verbose)
    {
        data->ICNTL(1) = 6; // standard output stream
        data->ICNTL(2) = 0; // output stream
        data->ICNTL(3) = 6; // standard output stream
        data->ICNTL(4) = 2; // errors, warnings, and main statistics printed
    }
    else
    {
        data->ICNTL(1) = -1; // no output messages
        data->ICNTL(2) = -1; // no warnings
        data->ICNTL(3) = -1; // no global information
        data->ICNTL(4) = -1; // message level
    }
}

inline void handle_options_and_set_distributed(DMUMPS_STRUC_C *data, const MumpsOptions &options)
{
    data->ICNTL(7) = options.ordering;
    data->ICNTL(8) = options.scaling;
    data->ICNTL(14) = options.pct_inc_workspace;
    data->ICNTL(23) = options.max_work_memory;

    data->ICNTL(18) = MUMPS_USE_DISTRIBUTED_MATRIX;
    data->ICNTL(6) = MUMPS_NO_COL_PERM_FOR_DISTR_MATRIX; // set this to remove warning
}

inline std::string handle_infog(DMUMPS_STRUC_C *data)
{
    if (data->INFOG(1) < 0)
    {
        auto infog1 = std::to_string(data->INFOG(1));
        auto infog2 = std::to_string(data->INFOG(2));
        switch (data->INFOG(1))
        {
        case -6:
            return "ERROR: (-6) Matrix is singular in structure. The structural rank is equal to " + infog2;
        case -9:
            return "ERROR: (-9) The main internal real/complex workarray S is too small. INFOG(2) = " + infog2;
        case -10:
            return "ERROR: (-10) Numerically singular matrix. The number of eliminated pivots is equal to " + infog2;
        case -13:
            return "ERROR: (-13) Problem of workspace allocation of size " + infog2 + " during the factorization or solve step";
        case -19:
            auto infog23 = std::to_string(data->INFOG(23));
            return "ERROR: (-19) The maximum allowed size of working memory " + infog23 + " is too small to run the factorization phase";
        }
        return "ERROR: (" + infog1 + ") Some error occurred. INFOG(2) = " + infog2;
    }

    if (data->INFOG(1) > 0)
    {
        auto infog1 = std::to_string(data->INFOG(1));
        return "WARNING: A warning has returned via INFOG(1) = " + infog1;
    }

    return ""; // OK
}

inline void call_dmumps(DMUMPS_STRUC_C *data, MumpsJob job, bool verbose)
{
    handle_verbose(data, verbose);

    data->job = job;
    dmumps_c(data);

    if (data->INFOG(1) != 0)
    {
        throw handle_infog(data);
    }

    handle_verbose(data, false);
}

#undef INFOG
#undef ICNTL