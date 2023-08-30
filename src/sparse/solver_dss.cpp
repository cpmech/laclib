#include <memory>

#include "mkl_dss.h"
#include "solver_dss.h"
#include "stdio.h"

void SolverDss::analyze(const std::unique_ptr<SparseTriplet> &trip,
                        bool verbose) {

    /*
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
        */
}

void SolverDss::factorize(bool verbose) {
    /*

    // TEMPORARY
    double matrix_values[9] = {9, 1.5, 6, .75, 3, 0.5, 12, .625, 16};

    // factorize the matrix
    auto error = dss_factor_real(handle, type, matrix_values);
    if (error != MKL_DSS_SUCCESS) {
        throw "Intel DSS failed to factorize the matrix";
    }
    */
}

void SolverDss::analyze_and_factorize(const std::unique_ptr<SparseTriplet> &trip,
                                      bool verbose) {
    // todo
}

void SolverDss::solve(std::vector<double> &xx,
                      const std::vector<double> &rhss,
                      bool verbose) {

    MKL_INT nRows = 5;
    MKL_INT nCols = 5;
    MKL_INT nNonZeros = 9;
    MKL_INT nRhs = 1;
    MKL_INT rowIndex[6] = {1, 6, 7, 8, 9, 10};
    MKL_INT columns[9] = {1, 2, 3, 4, 5, 2, 3, 4, 5};
    double values[9] = {9, 1.5, 6, .75, 3, 0.5, 12, .625, 16};
    double rhs[5] = {1, 2, 3, 4, 5};

    for (size_t i = 0; i < 5; i++) {
        rowIndex[i] -= 1;
    }
    rowIndex[5] -= 1;
    for (size_t i = 0; i < 9; i++) {
        columns[i] -= 1;
    }

    // No diagonal element can be omitted from the values array.
    // If there is a zero value on the diagonal, for example,
    // that element nonetheless must be explicitly represented.

    // MKL_INT opt = MKL_DSS_DEFAULTS;
    MKL_INT opt = MKL_DSS_MSG_LVL_WARNING + MKL_DSS_TERM_LVL_ERROR + MKL_DSS_ZERO_BASED_INDEXING;
    MKL_INT sym = MKL_DSS_SYMMETRIC;
    MKL_INT type = MKL_DSS_POSITIVE_DEFINITE;

    double solValues[5];

    dss_create(handle, opt);
    dss_define_structure(handle, sym, rowIndex, nRows, nCols, columns, nNonZeros);
    dss_reorder(handle, opt, 0);
    dss_factor_real(handle, type, values);
    dss_solve_real(handle, opt, rhss.data(), nRhs, solValues);

    for (size_t i = 0; i < 5; i++) {
        printf("%g ", solValues[i]);
    }

    // solve the system
    // MKL_INT opt = MKL_DSS_DEFAULTS;
    // MKL_INT n_rhs = 1;
    // // auto error = dss_solve_real(handle, opt, rhs.data(), n_rhs, x.data());
    // auto error = dss_solve_real(handle, opt, theRhs, n_rhs, solValues);
    // if (error != MKL_DSS_SUCCESS) {
    //     throw "Intel DSS failed to solve the system";
    // }
}
