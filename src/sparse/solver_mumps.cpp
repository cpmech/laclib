#include <memory>
#include "dmumps_c.h"
#include "solver_mumps.h"

std::unique_ptr<SolverMumps> solver_mumps_new()
{
    DMUMPS_STRUC_C data;
    return std::unique_ptr<SolverMumps>{
        new SolverMumps{
            data,
        }};
}