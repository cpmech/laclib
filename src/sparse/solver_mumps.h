#pragma once
#include <memory>
#include "mpi.h"
#include "dmumps_c.h"
#include "triplet_for_mumps.h"
#include "solver_mumps_constants.h"
#include "solver_mumps_options.h"
#include "solver_mumps_wrapper.h"
#include "../mpiaux/mpiaux.h"

struct MumpsSolver
{
    MpiAux mpi;
    DMUMPS_STRUC_C data;
    bool factorized;

    inline static std::unique_ptr<MumpsSolver> make_new(MpiAux mpi, MumpsSymmetry symmetry)
    {
        DMUMPS_STRUC_C data;
        data.comm_fortran = (MUMPS_INT)MPI_Comm_c2f(mpi.comm);
        data.par = MUMPS_HOST_ALSO_WORKS;
        data.sym = symmetry;

        call_dmumps(&data, MUMPS_JOB_INITIALIZE, false);

        auto solver = std::unique_ptr<MumpsSolver>{
            new MumpsSolver{
                mpi,
                data,
                false,
            }};

        return solver;
    };

    ~MumpsSolver()
    {
        call_dmumps(&this->data, MUMPS_JOB_TERMINATE, false);
    }

    void analize_and_factorize(TripletForMumps *trip, const MumpsOptions &options, bool verbose);
    void solve(std::vector<double> &x, const std::vector<double> &rhs, bool rhs_is_distributed, bool verbose);
};