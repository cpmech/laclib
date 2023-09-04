#pragma once

#include <memory>

#include "csr_matrix.h"
#include "mkl_dss.h"
#include "mkl_spblas.h"
#include "solver_dss_options.h"

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
            }};
    };

    /// @brief Clears temporary data
    ~SolverDss() {
        dss_delete(this->handle, this->dss_opt);
    }

    /// @brief Performs the analyze step
    /// @param csr The matrix data in compressed sparse row form (CSR)
    /// @param verbose Show messages
    /// @note The matrix, if symmetric, must be given in UPPER_TRIANGULAR layout
    void analyze(const std::unique_ptr<CsrMatrixMkl> &csr,
                 bool verbose = false);

    /// @brief Performs the factorization step
    /// @param csr The same matrix passed to analyze
    /// @param verbose Show messages
    /// @note Must be called after analyze
    void factorize(const std::unique_ptr<CsrMatrixMkl> &csr,
                   bool verbose = false);

    /// @brief Calls analyze and factorize
    /// @param csr The matrix data in compressed sparse row form (CSR)
    /// @param verbose Show messages
    /// @note The matrix, if symmetric, must be given in UPPER_TRIANGULAR layout
    void analyze_and_factorize(const std::unique_ptr<CsrMatrixMkl> &csr,
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

// Reference:
// https://www.intel.com/content/www/us/en/docs/onemkl/developer-reference-c/2023-2/direct-sparse-solver-dss-interface-routines.html
