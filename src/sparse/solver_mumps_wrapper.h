#pragma once
#include <string>
#include "dmumps_c.h"

#define ICNTL(I) icntl[(I)-1] // macro to make indices match documentation
#define INFOG(I) infog[(I)-1] // macro to make indices match documentation

static inline void _handle_verbose(DMUMPS_STRUC_C *data, bool verbose)
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

static inline std::string _handle_infog(DMUMPS_STRUC_C *data)
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

static inline void _call_dmumps(DMUMPS_STRUC_C *data, MumpsJob job, bool verbose)
{
    _handle_verbose(data, verbose);

    data->job = job;
    dmumps_c(data);

    if (data->INFOG(1) != 0)
    {
        throw _handle_infog(data);
    }

    _handle_verbose(data, false);
}

#undef INFOG
#undef ICNTL