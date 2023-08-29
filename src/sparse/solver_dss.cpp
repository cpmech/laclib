#include <memory>

#include "mkl_dss.h"
#include "solver_dss.h"

void SolverDss::analyze(const std::unique_ptr<SparseTriplet> &trip,
                        bool verbose) {

    // initialize the solver
    MKL_INT opt = MKL_DSS_DEFAULTS;
    auto error = dss_create(handle, opt);
    if (error != MKL_DSS_SUCCESS) {
        throw "Intel DSS failed to initialize the solver";
    }

    // TEMPORARY
    MKL_INT n_rows = 5;
    MKL_INT n_cols = 5;
    MKL_INT n_non_zeros = 9;
    MKL_INT matrix_row_indices[6] = {1, 6, 7, 8, 9, 10};
    MKL_INT matrix_columns[9] = {1, 2, 3, 4, 5, 2, 3, 4, 5};

    // define the non-zero structure of the matrix
    error = dss_define_structure(handle, sym, matrix_row_indices, n_rows, n_cols, matrix_columns, n_non_zeros);
    if (error != MKL_DSS_SUCCESS) {
        throw "Intel DSS failed to define the non-zero structure of the matrix";
    }

    // reorder the matrix
    error = dss_reorder(handle, opt, 0);
    if (error != MKL_DSS_SUCCESS) {
        throw "Intel DSS failed to reorder the matrix";
    }
}

void SolverDss::factorize(bool verbose) {

    // TEMPORARY
    double matrix_values[9] = {9, 1.5, 6, .75, 3, 0.5, 12, .625, 16};

    // factorize the matrix
    auto error = dss_factor_real(handle, type, matrix_values);
    if (error != MKL_DSS_SUCCESS) {
        throw "Intel DSS failed to factorize the matrix";
    }
}

void SolverDss::analyze_and_factorize(const std::unique_ptr<SparseTriplet> &trip,
                                      bool verbose) {
    // todo
}

void SolverDss::solve(std::vector<double> &x,
                      const std::vector<double> &rhs,
                      bool verbose) {

    // solve the system
    MKL_INT opt = MKL_DSS_DEFAULTS;
    MKL_INT n_rhs = 1;
    auto error = dss_solve_real(handle, opt, rhs.data(), n_rhs, x.data());
    if (error != MKL_DSS_SUCCESS) {
        throw "Intel DSS failed to solve the system";
    }
}
