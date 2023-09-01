#pragma once

#include <memory>

#include "coo_matrix.h"
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

    /// @brief Handle to CSR matrix (delete only this one)
    sparse_matrix_t csr_handle;

    /// @brief Holds the row indices according to the CSR3 format
    MKL_INT *csr_row_indices;

    /// @brief Holds the first row indices according to the CSR format
    MKL_INT *csr_pointer_b;

    /// @brief Holds the last row indices according to the CSR format
    MKL_INT *csr_pointer_e;

    /// @brief Holds the columns according to the CSR or CSR3 format
    MKL_INT *csr_columns;

    /// @brief Holds the values according to the CSR or CSR3 format
    double *csr_values;

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
                sparse_matrix_t(),
                NULL,
                NULL,
                NULL,
                NULL,
                NULL,
            }};
    };

    /// @brief Clears the memory allocated by analyze
    /// @note This is an internal function that must not be called by the user
    void _clear_memory_allocated_by_analyze() {
        if (this->csr_row_indices != NULL) {
            free(this->csr_row_indices);
        }
        mkl_sparse_destroy(this->csr_handle);
    }

    /// @brief Clears temporary data
    ~SolverDss() {
        _clear_memory_allocated_by_analyze();
        dss_delete(this->handle, this->dss_opt);
    }

    /// @brief Performs the analyze step
    /// @param coo The matrix data in Triplet form (COO)
    /// @param verbose Show messages
    void analyze(const std::unique_ptr<CooMatrix> &coo,
                 bool verbose = false);

    /// @brief Performs the factorization step
    /// @param verbose Show messages
    /// @note Must be called after analyze
    void factorize(bool verbose = false);

    /// @brief Calls analyze and factorize
    /// @param coo The matrix data in Triplet form (COO)
    /// @param verbose Show messages
    void analyze_and_factorize(const std::unique_ptr<CooMatrix> &coo,
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
