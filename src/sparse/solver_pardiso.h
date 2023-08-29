#pragma once

#include <memory>

#include "solver_pardiso_constants.h"
#include "solver_pardiso_options.h"
#include "solver_pardiso_wrapper.h"
#include "sparse_triplet.h"

struct SolverPardiso {
    const std::unique_ptr<PardisoOptions> &options; // options

    DMUMPS_STRUC_C data; // MUMPS data structure for C-code
    bool analyzed;       // analyze or analyze_and_factorize has been called
    bool factorized;     // analyze_and_factorize or factorize has been called

    inline static std::unique_ptr<SolverPardiso> make_new(const std::unique_ptr<PardisoOptions> &options) {
        DMUMPS_STRUC_C data;
        data.comm_fortran = 0;
        data.par = MUMPS_PAR_HOST_ALSO_WORKS;
        data.sym = options->symmetry;

        _call_dmumps(&data, MUMPS_JOB_INITIALIZE, false);

        return std::unique_ptr<SolverPardiso>{
            new SolverPardiso{
                options,
                data,
                false,
                false,
            }};
    };

    ~SolverPardiso() {
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
