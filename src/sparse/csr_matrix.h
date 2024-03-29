#pragma once

#include <iostream>
#include <memory>
#include <vector>

#include "mkl.h"

#include "../util/print_vector.h"
#include "coo_matrix.h"

/// @brief Holds the arrays needed for a CSR (compressed sparse row) matrix
struct CsrMatrix {
    /// @brief layout
    StoredLayout layout;

    /// @brief Equals the number of rows and number of columns
    size_t dimension;

    /// @brief Is the resulting number of non-zeros after duplicates have been handled
    size_t nnz;

    /// @brief Is the row pointers array with size = n_row + 1
    std::vector<INT> row_pointers;

    /// @brief Is the column indices array with size = nnz (number of non-zeros)
    /// @note The size of this vector may be greater than nnz because some duplicates have been summed up
    std::vector<INT> column_indices;

    /// @brief Is the values array with size = nnz (number of non-zeros)
    /// @note The size of this vector may be greater than nnz because some duplicates have been summed up
    std::vector<double> values;

    /// @brief Allocates a new structure
    static std::unique_ptr<CsrMatrix> from(std::unique_ptr<CooMatrix> &coo);

    /// @brief Prints the matrix
    /// @param name A label
    void print(const std::string &name) {
        std::cout << name << std::endl;
        print_vector("p", this->row_pointers);
        print_vector("j", this->column_indices);
        print_vector("x", this->values);
    }
};

/// @brief Holds the arrays needed for a CSR (compressed sparse row) matrix (MKL version)
/// @note The DSS uses a row-major UPPER triangular storage format.
/// @note The matrix is compressed row-by-row.
/// @note For symmetric matrices only non-zero elements in the UPPER triangular half of the matrix are stored.
/// @note For symmetric matrices, the zero diagonal entries must be stored as well.
struct CsrMatrixMkl {
    /// @brief layout
    StoredLayout layout;

    /// @brief Equals the number of rows and number of columns
    MKL_INT dimension;

    /// @brief Is the resulting number of non-zeros after duplicates have been handled
    MKL_INT nnz;

    /// @brief Is the row pointers array with size = n_row + 1
    MKL_INT *row_pointers = NULL;

    /// @brief Is the column indices array with size = nnz (number of non-zeros)
    /// @note The size of this vector may be greater than nnz because some duplicates have been summed up
    MKL_INT *column_indices = NULL;

    /// @brief Is the values array with size = nnz (number of non-zeros)
    /// @note The size of this vector may be greater than nnz because some duplicates have been summed up
    double *values = NULL;

    /// @brief Holds a handle to the CSR data (use this with mkl_sparse_destroy)
    sparse_matrix_t handle = NULL;

    /// @brief Allocates a new structure
    /// @todo See if const can be used here
    static std::unique_ptr<CsrMatrixMkl> from(std::unique_ptr<CooMatrix> &coo);

    /// @brief Deallocates memory
    ~CsrMatrixMkl() {
        if (this->row_pointers != NULL) {
            free(this->row_pointers);
        }
        if (this->handle != NULL) {
            mkl_sparse_destroy(this->handle);
        }
    }

    /// @brief Prints the matrix
    /// @param name A label
    void print(const std::string &name) {
        std::cout << name << std::endl;
        std::cout << "p = ";
        for (MKL_INT i = 0; i < this->dimension + 1; i++) {
            std::cout << this->row_pointers[i] << ", ";
        }
        std::cout << "\nj = ";
        for (MKL_INT i = 0; i < this->nnz; i++) {
            std::cout << this->column_indices[i] << ", ";
        }
        std::cout << "\nx = ";
        for (MKL_INT i = 0; i < this->nnz; i++) {
            std::cout << this->values[i] << ", ";
        }
        std::cout << std::endl;
    }

    /// @brief Check if the matrix is OK for Intel DSS
    bool ok_for_dss(bool verbose = false);
};

// Reference regarding symmetric matrix storage
// https://www.intel.com/content/www/us/en/docs/onemkl/developer-reference-c/2023-2/dss-symmetric-matrix-storage.html
