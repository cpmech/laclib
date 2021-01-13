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
    const std::unique_ptr<MpiAux> &mpi; // MPI wrapper
    DMUMPS_STRUC_C data;                // MUMPS data structure for C-code
    bool distributed_matrix;            // matrix is distributed; not centralized on the host with rank == 0
    bool analyzed;                      // analyze or analyze_and_factorize has been called
    bool factorized;                    // analyze_and_factorize or factorize has been called

    inline static std::unique_ptr<SolverMumps> make_new(const std::unique_ptr<MpiAux> &mpi,
                                                        MumpsSymmetry symmetry,
                                                        bool distributed_matrix = false)
    {
        DMUMPS_STRUC_C data;
        data.comm_fortran = (MUMPS_INT)MPI_Comm_c2f(mpi->comm);
        data.par = MUMPS_PAR_HOST_ALSO_WORKS;
        data.sym = symmetry;

        _call_dmumps(&data, MUMPS_JOB_INITIALIZE, false);

        return std::unique_ptr<SolverMumps>{
            new SolverMumps{
                mpi,
                data,
                distributed_matrix,
                false,
                false,
            }};
    };

    inline static std::unique_ptr<SolverMumps> make_new(const std::unique_ptr<MpiAux> &mpi,
                                                        bool general_symmetry,
                                                        bool distributed_matrix = false)
    {
        MumpsSymmetry sym = general_symmetry ? MUMPS_SYMMETRY_GENERAL : MUMPS_SYMMETRY_NONE;
        return SolverMumps::make_new(mpi, sym, distributed_matrix);
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

// Page 29: Again, out-of-range entries are ignored and duplicate entries are summed.
