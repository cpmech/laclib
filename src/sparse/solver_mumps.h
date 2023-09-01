#pragma once

#include <memory>
#include <vector>

#include "coo_matrix.h"
#include "dmumps_c.h"
#include "solver_mumps_constants.h"
#include "solver_mumps_options.h"
#include "solver_mumps_wrapper.h"

/// @brief Wraps the MUMPS solver
struct SolverMumps {
    /// @brief Holds options
    const std::unique_ptr<MumpsOptions> &options;

    /// @brief MUMPS data structure for C-code
    DMUMPS_STRUC_C data;

    /// @brief Indicates if analyze or analyze_and_factorize were called
    bool analyzed;

    /// @brief Indicates if analyze_and_factorize or factorize were called
    bool factorized;

    /// @brief Row indices of the COO (triplet) matrix format
    std::vector<MUMPS_INT> indices_i;

    /// @brief Columns indices of the COO (triplet) matrix format
    std::vector<MUMPS_INT> indices_j;

    /// @brief Allocates a new structure
    /// @param options Holds options
    /// @return A new structure
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

    /// @brief Clears temporary data
    ~SolverMumps() {
        _call_dmumps(&this->data, MUMPS_JOB_TERMINATE, false);
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

// Page 29: Again, out-of-range entries are ignored and duplicate entries are summed.
