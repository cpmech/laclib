#pragma once
#include <memory>
#include <string>

#include "coo_matrix.h"

/// @brief Holds options to handle the data when the matrix is symmetric
/// @note This is ignored if not symmetric
enum SymmetricHandling {
    /// @brief Leave the layout as lower triangular (if symmetric)
    /// @note Lower triangular is the standard MatrixMarket format
    /// @note Thus, do nothing
    LEAVE_AS_LOWER,

    /// @brief Convert the layout to upper triangular (if symmetric)
    /// @note Thus, swap the lower triangle to the upper triangle
    SWAP_TO_UPPER,

    /// @brief Make the matrix full (if symmetric)
    /// @note Mirror the lower triangle to the upper triangle (duplicate data)
    /// @note The number of non-zeros will be slightly larger than just duplicating the lower triangle
    MAKE_IT_FULL,
};

/// @brief Reads a MatrixMarket file into a CooMatrix
/// @param symmetric_handling Options to handle symmetric matrices
/// @note This function works only with square matrices.
std::unique_ptr<CooMatrix> read_matrix_market(const std::string &filename,
                                              SymmetricHandling symmetric_handling = LEAVE_AS_LOWER);

// If the matrix is symmetric, only entries in the **lower triangular** portion
// are present in the MatrixMarket file (see reference).
//
// # Example of MatrixMarket file
//
// ```text
// %%MatrixMarket matrix coordinate real general
// %=================================================================================
// %
// % This ASCII file represents a sparse MxN matrix with L
// % non-zeros in the following Matrix Market format:
// %
// % Reference: https://math.nist.gov/MatrixMarket/formats.html
// %
// % +----------------------------------------------+
// % |%%MatrixMarket matrix coordinate real general | <--- header line
// % |%                                             | <--+
// % |% comments                                    |    |-- 0 or more comment lines
// % |%                                             | <--+
// % |    M  N  L                                   | <--- rows, columns, entries
// % |    I1  J1  A(I1, J1)                         | <--+
// % |    I2  J2  A(I2, J2)                         |    |
// % |    I3  J3  A(I3, J3)                         |    |-- L lines
// % |        . . .                                 |    |
// % |    IL JL  A(IL, JL)                          | <--+
// % +----------------------------------------------+
// %
// % Indices are 1-based, i.e. A(1,1) is the first element.
// %
// %=================================================================================
//   5  5  8
//     1     1   1.000e+00
//     2     2   1.050e+01
//     3     3   1.500e-02
//     1     4   6.000e+00
//     4     2   2.505e+02
//     4     4  -2.800e+02
//     4     5   3.332e+01
//     5     5   1.200e+01
// ```
//
// ## Remarks
//
// * The first line is the **header line**
// * The header must contain `%%MatrixMarket matrix coordinate real` followed by `general` or `symmetric` (separated by spaces)
// * Thus, this function can only read the `coordinate` and `real` combination for now
// * After the header line, the percentage character marks a comment line
// * After the header line, a line with dimensions `m n nnz` must follow
// * `m`, `n`, and `nnz` are the number of columns, rows, and non-zero values
// * After the dimensions line, `nnz` data lines containing the triples (i,j,aij) must follow
// * The indices start at one (1-based indices)
//
// # Reference
//
// <https://math.nist.gov/MatrixMarket/formats.html>
