#include <memory>
#include "dmumps_c.h"
#include "solver_mumps.h"

std::unique_ptr<SolverMumps> solver_mumps_new()
{
    MUMPS_INT USE_COMM_WORLD = -987654;

    DMUMPS_STRUC_C data;

    data.comm_fortran = USE_COMM_WORLD;

    return std::unique_ptr<SolverMumps>{
        new SolverMumps{
            data,
        }};
}

void SolverMumps::init(const TripletForMumps &trip)
{
}
