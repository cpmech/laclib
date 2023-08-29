#pragma once

#include <memory>

#include "mkl_dss.h"
#include "solver_dss_options.h"
#include "sparse_triplet.h"

/// @brief Wraps the Intel DSS solver
///
/// https://www.intel.com/content/www/us/en/docs/onemkl/developer-reference-c/2023-2/direct-sparse-solver-dss-interface-routines.html
struct SolverDss {
    const std::unique_ptr<DssOptions> &options; // options

    _MKL_DSS_HANDLE_t handle; // handle for Intel DSS data
    bool analyzed;            // analyze or analyze_and_factorize has been called
    bool factorized;          // analyze_and_factorize or factorize has been called

    inline static std::unique_ptr<SolverDss> make_new(const std::unique_ptr<DssOptions> &options) {
        _MKL_DSS_HANDLE_t handle;

        MKL_INT opt = MKL_DSS_DEFAULTS;

        auto error = dss_create(handle, opt);
        if (error != MKL_DSS_SUCCESS) {
            throw "Intel DSS create failed";
        }

        return std::unique_ptr<SolverDss>{
            new SolverDss{
                options,
                handle,
                false,
                false,
            }};
    };

    ~SolverDss() {
        MKL_INT opt = MKL_DSS_DEFAULTS;
        dss_delete(handle, opt);
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
