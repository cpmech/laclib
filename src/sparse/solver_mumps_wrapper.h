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

inline void handle_options(DMUMPS_STRUC_C *data, const MumpsOptions &options)
{
    data->ICNTL(7) = options.ordering;
    data->ICNTL(8) = options.scaling;
    data->ICNTL(14) = options.pct_inc_workspace;
    data->ICNTL(23) = options.max_work_memory;
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
            return "ERROR: Matrix is singular in structure. The structural rank is equal to " + infog2;
        case -9:
            return "ERROR: The main internal real/complex workarray S is too small. INFOG(2) = " + infog2;
        case -10:
            return "ERROR: Numerically singular matrix. The number of eliminated pivots is equal to " + infog2;
        case -13:
            return "ERROR: Problem of workspace allocation of size " + infog2 + " during the factorization or solve step";
        case -19:
            auto infog23 = std::to_string(data->INFOG(23));
            return "ERROR: The maximum allowed size of working memory " + infog23 + " is too small to run the factorization phase";
        }
        return "ERROR: Some error occurred. INFOG(1) = " + infog1 + " and INFOG(2) = " + infog2;
    }

    if (data->INFOG(1) > 0)
    {
        auto infog1 = std::to_string(data->INFOG(1));
        return "WARNING: A warning has returned via INFOG(1) = " + infog1;
    }

    return ""; // OK
}

// returns:
//    0   -- success
//    < 0 -- error
//    > 0 -- warning
inline int call_dmumps(DMUMPS_STRUC_C *data, MumpsJob job, bool verbose)
{
    handle_verbose(data, verbose);

    data->job = job;
    dmumps_c(data);

    if (data->INFOG(1) != 0 && verbose)
    {
        std::cout << handle_infog(data) << std::endl;
    }

    handle_verbose(data, false);

    return data->INFOG(1);
}

#undef INFOG
#undef ICNTL