#pragma once

#include <memory>

#include "mkl_dss.h"
#include "mkl_spblas.h"
#include "solver_dss_options.h"
#include "sparse_triplet.h"

/// @brief Wraps the Intel DSS solver
struct SolverDss {
    /// @brief Holds the Intel DSS handle
    _MKL_DSS_HANDLE_t handle;

    /// @brief Holds the Intel DSS options
    MKL_INT dss_opt;

    /// @brief Holds the Intel DSS sym option
    MKL_INT dss_sym;

    /// @brief Holds the Intel DSS type option
    MKL_INT dss_type;

    /// @brief Indicates if analyze or analyze_and_factorize were called
    bool analyzed;

    /// @brief Indicates if analyze_and_factorize or factorize were called
    bool factorized;

    /// @brief Holds the handle to COO (triplet) matrix
    sparse_matrix_t coo_matrix;

    /// @brief Allocates a new structure
    /// @param options Holds options
    /// @return A new structure
    inline static std::unique_ptr<SolverDss> make_new(const std::unique_ptr<DssOptions> &options) {
        _MKL_DSS_HANDLE_t handle;

        MKL_INT dss_opt = MKL_DSS_MSG_LVL_WARNING + MKL_DSS_TERM_LVL_ERROR + MKL_DSS_ZERO_BASED_INDEXING;

        MKL_INT dss_sym = MKL_DSS_NON_SYMMETRIC;
        if (options->symmetric) {
            dss_sym = MKL_DSS_SYMMETRIC;
        }

        MKL_INT dss_type = MKL_DSS_INDEFINITE;
        if (options->positive_definite) {
            dss_type = MKL_DSS_POSITIVE_DEFINITE;
        }

        auto error = dss_create(handle, dss_opt);
        if (error != MKL_DSS_SUCCESS) {
            throw "Intel DSS create failed";
        }

        return std::unique_ptr<SolverDss>{
            new SolverDss{
                handle,
                dss_opt,
                dss_sym,
                dss_type,
                false,
                false,
                NULL,
            }};
    };

    /// @brief Clears temporary data
    ~SolverDss() {
        if (coo_matrix != NULL) {
            mkl_sparse_destroy(coo_matrix);
        }
        MKL_INT opt = MKL_DSS_DEFAULTS;
        dss_delete(handle, opt);
    }

    /// @brief Performs the analyze step
    /// @param trip The matrix data in Triplet form (COO)
    /// @param verbose Show messages
    void analyze(const std::unique_ptr<SparseTriplet> &trip,
                 bool verbose = false);

    /// @brief Performs the factorization step
    /// @param verbose Show messages
    /// @note Must be called after analyze
    void factorize(bool verbose = false);

    /// @brief Calls analyze and factorize
    /// @param trip The matrix data in Triplet form (COO)
    /// @param verbose Show messages
    void analyze_and_factorize(const std::unique_ptr<SparseTriplet> &trip,
                               bool verbose = false);

    /// @brief Performs the solution step
    /// @param x The vector in A*x = rhs
    /// @param rhs The hand-side vector
    /// @param verbose Show messages
    /// @note Must be called after analyze and factorize
    void solve(std::vector<double> &x,
               const std::vector<double> &rhs,
               bool verbose = false);
};

// https://www.intel.com/content/www/us/en/docs/onemkl/developer-reference-c/2023-2/direct-sparse-solver-dss-interface-routines.html