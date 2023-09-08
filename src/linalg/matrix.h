#pragma once

#include <cassert>
#include <iostream>
#include <memory>
#include <vector>

/// @brief Implements a matrix with numeric components for linear algebra
/// @note Internally, the data is stored in the **col-major** order.
struct Matrix {
    //     ┌     ┐  row_major = {0, 3,
    //     │ 0 3 │               1, 4,
    // A = │ 1 4 │               2, 5};
    //     │ 2 5 │
    //     └     ┘  col_major = {0, 1, 2,
    //     (m × n)               3, 4, 5}
    //
    // Aᵢⱼ = col_major[i + j·m] = row_major[i·n + j]
    //         ↑
    // COL-MAJOR IS ADOPTED HERE
    //
    // The main reason to use the **col-major** representation is to make the code work
    // better with BLAS/LAPACK written in Fortran. Although those libraries have functions
    // to handle row-major data, they usually add an overhead due to temporary memory
    // allocation and copies, including transposing matrices. Moreover, the row-major
    // versions of some BLAS/LAPACK libraries produce incorrect results (notably the DSYEV).

    /// @brief Holds the number of rows
    size_t nrow;

    /// @brief Holds the number of columns
    size_t ncol;

    /// @brief Holds the values organized in column-major ordering (to use with Fortran)
    std::vector<double> data;

    /// @brief Creates new (nrow x ncol) Matrix filled with zeros
    inline static std::unique_ptr<Matrix> make_new(size_t nrow, size_t ncol) {
        return std::unique_ptr<Matrix>{new Matrix{
            nrow,
            ncol,
            std::vector<double>(nrow * ncol, 0.0),
        }};
    }

    /// @brief Creates new identity (square) matrix
    inline static std::unique_ptr<Matrix> identity(size_t dimension) {
        auto matrix = Matrix::make_new(dimension, dimension);
        for (size_t i = 0; i < dimension; i++) {
            matrix->data[i + i * dimension] = 1.0;
        }
        return matrix;
    }

    /// @brief Creates new matrix completely filled with the same value
    inline static std::unique_ptr<Matrix> filled(size_t nrow, size_t ncol, double value) {
        return std::unique_ptr<Matrix>{new Matrix{
            nrow,
            ncol,
            std::vector<double>(nrow * ncol, value),
        }};
    }

    /// @brief Creates a new diagonal matrix with given diagonal values
    inline static std::unique_ptr<Matrix> diagonal(std::vector<double> values) {
        auto nrow = values.size();
        auto ncol = nrow;
        auto matrix = Matrix::make_new(nrow, ncol);
        for (size_t i = 0; i < nrow; i++) {
            matrix->data[i + i * nrow] = values[i];
        }
        return matrix;
    }

    /// @brief Creates a new matrix from a row-major array
    inline static std::unique_ptr<Matrix> from_row_major(size_t nrow, size_t ncol, std::vector<double> values) {
        if (nrow * ncol != values.size()) {
            throw "there is not enough values to create the matrix";
        }
        auto matrix = Matrix::make_new(nrow, ncol);
        for (size_t i = 0; i < nrow; i++) {
            for (size_t j = 0; j < ncol; j++) {
                matrix->data[i + j * nrow] = values[j + i * ncol];
            }
        }
        return matrix;
    }

    /// @brief Fills this matrix with a given value
    inline void fill(double value) {
        for (size_t i = 0; i < this->nrow; i++) {
            for (size_t j = 0; j < this->ncol; j++) {
                this->data[i + j * this->nrow] = value;
            }
        }
    }

    /// @brief Returns the (i,j) component
    /// @note This function throws errors if the indices are out-of-range
    inline double get(size_t i, size_t j) {
        assert(i < this->nrow);
        assert(j < this->ncol);
        return this->data[i + j * this->nrow];
    }

    /// @brief Change the (i,j) component
    /// @note This function throws errors if the indices are out-of-range
    inline void set(size_t i, size_t j, double value) {
        assert(i < this->nrow);
        assert(j < this->ncol);
        this->data[i + j * this->nrow] = value;
    }

    /// @brief Adds a value to the (i,j) component
    /// @note This function throws errors if the indices are out-of-range
    inline void add(size_t i, size_t j, double value) {
        assert(i < this->nrow);
        assert(j < this->ncol);
        this->data[i + j * this->nrow] += value;
    }

    /// @brief Multiply a value to the (i,j) component
    /// @note This function throws errors if the indices are out-of-range
    inline void mul(size_t i, size_t j, double value) {
        assert(i < this->nrow);
        assert(j < this->ncol);
        this->data[i + j * this->nrow] *= value;
    }

    /// @brief Prints the matrix
    void print() {
        for (size_t i = 0; i < this->nrow; i++) {
            for (size_t j = 0; j < this->ncol; j++) {
                std::cout << this->data[i + j * this->nrow] << ", ";
            }
            std::cout << std::endl;
        }
    }
};
