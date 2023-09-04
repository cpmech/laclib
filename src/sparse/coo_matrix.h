#pragma once

#include <memory>
#include <vector>

#ifdef USE_MKL
#include "mkl.h"
#define INT MKL_INT
#else
#include "dmumps_c.h"
#define INT MUMPS_INT
#endif

/// @brief Casts a size_t integer to INT and checks if it worked
/// @param a is the size_t integer
/// @return the INT integer
inline INT make_int(size_t a) {
    INT n = static_cast<INT>(a);
    size_t temp = static_cast<size_t>(n);
    if (a != temp) {
        throw "make_int failed with integer overflow";
    }
    return n;
}

/// @brief Defines how the CooMatrix (triplet) represents a matrix
enum StoredLayout {
    LOWER_TRIANGULAR, // e.g., for MUMPS
    UPPER_TRIANGULAR, // e.g., for DSS
    FULL_MATRIX,      // e.g., for UMFPACK
};

/// @brief Checks if layout is symmetric or not (e.g., with lower or upper triangular)
/// @param layout is the layout
/// @return true if certainly symmetric, or false if general matrix (which could be symmetric)
inline bool is_symmetric(StoredLayout layout) {
    if (layout == FULL_MATRIX) {
        return false;
    }
    return true;
}

/// @brief Holds the row index, col index, and values of a matrix (also known as Triplet)
struct CooMatrix {
    /// @brief layout
    StoredLayout layout;

    /// @brief number of rows == number of columns
    size_t dimension;

    /// @brief current index => nnz in the end
    size_t pos;

    /// @brief max allowed number of entries
    size_t max;

    /// @brief row indices (zero-based)
    std::vector<INT> indices_i;

    /// @brief column indices (zero-based)
    std::vector<INT> indices_j;

    /// @brief the non-zero entries in the matrix
    /// @note if lower triangular, the diagonal entry must be included, even if it's zero
    std::vector<double> values_aij;

    /// @brief Allocates a new structure
    /// @param lower_triangular Indicates that this triplet holds the lower triangular part of a matrix
    /// @param dimension number of rows (= number of columns)
    /// @param max Maximum number of entries ≥ nnz (number of non-zeros)
    /// @return Returns a new structure
    inline static std::unique_ptr<CooMatrix> make_new(
        StoredLayout layout,
        size_t dimension,
        size_t max) {
        return std::unique_ptr<CooMatrix>{new CooMatrix{
            layout,
            dimension,
            0,
            max,
            std::vector<INT>(max, 0),
            std::vector<INT>(max, 0),
            std::vector<double>(max, 0.0),
        }};
    }

    /// @brief Puts a new entry and updates pos (may be duplicate)
    /// @param i Row index (indices start at zero; zero-based)
    /// @param j Column index (indices start at zero; zero-based)
    /// @param aij The value A(i,j) (duplicate values will be summed up)
    void put(INT i, INT j, double aij);
};