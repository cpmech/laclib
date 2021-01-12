#pragma once
#include <memory>
#include "mpi.h"
#include "dmumps_c.h"
#include "sparse_triplet.h"
#include "solver_mumps_constants.h"
#include "solver_mumps_options.h"
#include "solver_mumps_wrapper.h"
#include "../mpiaux/mpiaux.h"

struct SolverMumps
{
    MpiAux mpi;
    DMUMPS_STRUC_C data;
    bool analyzed;
    bool factorized;

    inline static std::unique_ptr<SolverMumps> make_new(MpiAux mpi, MumpsSymmetry symmetry)
    {
        DMUMPS_STRUC_C data;
        data.comm_fortran = (MUMPS_INT)MPI_Comm_c2f(mpi.comm);
        data.par = 1; // the host is also involved in the parallel steps of the factorization and solve phases
        data.sym = symmetry;

        _call_dmumps(&data, MUMPS_JOB_INITIALIZE, false);

        return std::unique_ptr<SolverMumps>{
            new SolverMumps{
                mpi,
                data,
                false,
                false,
            }};
    };

    inline static std::unique_ptr<SolverMumps> make_new(MpiAux mpi, bool general_symmetry)
    {
        MumpsSymmetry sym = general_symmetry ? MUMPS_SYMMETRY_GENERAL : MUMPS_SYMMETRY_NONE;
        return SolverMumps::make_new(mpi, sym);
    }

    ~SolverMumps()
    {
        _call_dmumps(&this->data, MUMPS_JOB_TERMINATE, false);
    }

    void analyze(const std::unique_ptr<SparseTriplet> &trip,
                 const MumpsOptions &options,
                 bool verbose = false);

    void factorize(bool verbose = false);

    void analyze_and_factorize(const std::unique_ptr<SparseTriplet> &trip,
                               const MumpsOptions &options,
                               bool verbose = false);

    inline void analyze_and_factorize(const std::unique_ptr<SparseTriplet> &trip)
    {
        auto options = MumpsOptions::make_new();
        this->analyze_and_factorize(trip, options);
    }

    void solve(std::vector<double> &x,
               const std::vector<double> &rhs,
               bool rhs_is_distributed = false,
               bool verbose = false);
};
