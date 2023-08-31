#include <iostream>
#include <memory>

#include "mkl_dss.h"
#include "solver_dss.h"

void SolverDss::analyze(const std::unique_ptr<SparseTriplet> &trip,
                        bool verbose) {

    // create handle to COO (triplet) matrix
    INT m = static_cast<INT>(trip->dimension);
    INT nnz = static_cast<INT>(trip->pos);
    sparse_matrix_t coo;
    auto status = mkl_sparse_d_create_coo(&coo,
                                          SPARSE_INDEX_BASE_ZERO,
                                          m,
                                          m,
                                          nnz,
                                          trip->indices_i.data(),
                                          trip->indices_j.data(),
                                          trip->values_aij.data());
    if (status != SPARSE_STATUS_SUCCESS) {
        throw "Intel DSS failed to create COO matrix";
    }

    // convert COO (triplet) to CSR matrix
    // The 3-array variation (CSR3) of the CSR format has a restriction: all non-zero elements
    // are stored continuously, that is the set of non-zero elements in the row J goes
    // just after the set of non-zero elements in the row J-1.
    // https://www.intel.com/content/www/us/en/docs/onemkl/developer-reference-c/2023-2/sparse-blas-csr-matrix-storage-format.html
    sparse_matrix_t csr;
    status = mkl_sparse_convert_csr(coo, SPARSE_OPERATION_NON_TRANSPOSE, &csr);
    if (status != SPARSE_STATUS_SUCCESS) {
        throw "Intel DSS failed to convert COO to CSR matrix";
    }

    // allocate data to access the CRS matrix
    sparse_index_base_t indexing;
    MKL_INT *csr_pointer_b = NULL;
    MKL_INT *csr_pointer_e = NULL;
    MKL_INT *csr_columns = NULL;
    double *csr_values = NULL;
    MKL_INT n_rows;
    MKL_INT n_cols;
    status = mkl_sparse_d_export_csr(csr,
                                     &indexing,
                                     &n_rows,
                                     &n_cols,
                                     &csr_pointer_b,
                                     &csr_pointer_e,
                                     &csr_columns,
                                     &csr_values);
    if (status != SPARSE_STATUS_SUCCESS) {
        throw "Intel DSS failed to export CSR matrix";
    }

    // print CSR matrix
    if (verbose) {
        std::cout << "\nCSR MATRIX\n";
        std::cout << "==========\n";
        std::cout << "row : (value, column) (value, column) ... (value, column)\n";
        MKL_INT k = 0;
        for (INT i = 0; i < m; i++) {
            std::cout << i << " : ";
            for (INT j = csr_pointer_b[i]; j < csr_pointer_e[i]; j++) {
                std::cout << "(" << csr_values[k] << ", " << csr_columns[k] << ") ";
                k++;
            }
            std::cout << std::endl;
        }
        status = mkl_sparse_destroy(csr);
        if (status != SPARSE_STATUS_SUCCESS) {
            throw "Intel DSS failed to destroy CSR matrix";
        }
    }

    // define the non-zero structure of the matrix
    // auto info = dss_define_structure(this->handle,
    //                                  this->dss_opt,
    //                                  matrix_row_indices,
    //                                  m,
    //                                  m,
    //                                  matrix_columns,
    //                                  nnz);
    // if (info != MKL_DSS_SUCCESS) {
    //     throw "Intel DSS failed to define the non-zero structure of the matrix";
    // }

    // // reorder the matrix
    // error = dss_reorder(handle, opt, 0);
    // if (error != MKL_DSS_SUCCESS) {
    //     throw "Intel DSS failed to reorder the matrix";
    // }
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
