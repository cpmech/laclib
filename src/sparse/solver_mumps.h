#pragma once

#include <memory>
#include <vector>

#include "dmumps_c.h"
#include "solver_mumps_constants.h"
#include "solver_mumps_options.h"
#include "solver_mumps_wrapper.h"
#include "sparse_triplet.h"

struct SolverMumps {
    const std::unique_ptr<MumpsOptions> &options; // options

    DMUMPS_STRUC_C data; // MUMPS data structure for C-code
    bool analyzed;       // analyze or analyze_and_factorize has been called
    bool factorized;     // analyze_and_factorize or factorize has been called

    std::vector<MUMPS_INT> indices_i;
    std::vector<MUMPS_INT> indices_j;

    inline static std::unique_ptr<SolverMumps> make_new(const std::unique_ptr<MumpsOptions> &options) {
        DMUMPS_STRUC_C data;
        data.comm_fortran = 0;
        data.par = MUMPS_PAR_HOST_ALSO_WORKS;
        data.sym = options->symmetry;

        _call_dmumps(&data, MUMPS_JOB_INITIALIZE, false);

        return std::unique_ptr<SolverMumps>{
            new SolverMumps{
                options,
                data,
                false,
                false,
                std::vector<MUMPS_INT>(),
                std::vector<MUMPS_INT>(),
            }};
    };

    ~SolverMumps() {
        _call_dmumps(&this->data, MUMPS_JOB_TERMINATE, false);
    }

    void analyze(const std::unique_ptr<SparseTriplet> &trip,
                 bool verbose = false);

    void factorize(bool verbose = false);

    void analyze_and_factorize(const std::unique_ptr<SparseTriplet> &trip,
                               bool verbose = false);

    void solve(std::vector<double> &x,
               const std::vector<double> &rhs,
               bool verbose = false);
};

// Page 29: Again, out-of-range entries are ignored and duplicate entries are summed.
