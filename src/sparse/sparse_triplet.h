#pragma once

#include <map>
#include <memory>
#include <tuple>
#include <vector>

typedef std::tuple<size_t, size_t> ij_pair_t;

struct SparseTriplet {
    bool lower_triangular;          // layout
    size_t dimension;               // number of rows == number of columns
    size_t pos;                     // current index => nnz in the end
    size_t max;                     // max allowed number of entries
    std::vector<size_t> indices_i;  // zero- or one-based indices stored here
    std::vector<size_t> indices_j;  // zero- or one-based indices stored here
    std::vector<double> values_aij; // the non-zero entries in the matrix

    /// @brief Maps a pair of indices (i,j) to pos and assists in summing duplicates up
    std::map<ij_pair_t, size_t> ij_to_pos;

    /// @brief Allocates a new structure
    /// @param lower_triangular Indicates that this triplet holds the lower triangular part of a matrix
    /// @param dimension number of rows (= number of columns)
    /// @param max Maximum number of entries ≥ nnz (number of non-zeros)
    /// @return Returns a new structure
    inline static std::unique_ptr<SparseTriplet> make_new(
        bool lower_triangular,
        size_t dimension,
        size_t max) {
        return std::unique_ptr<SparseTriplet>{new SparseTriplet{
            lower_triangular,
            dimension,
            0,
            max,
            std::vector<size_t>(max, 0),
            std::vector<size_t>(max, 0),
            std::vector<double>(max, 0.0),
            std::map<std::tuple<size_t, size_t>, size_t>(),
        }};
    }

    /// @brief Puts a new entry and updates pos (may be duplicate)
    /// @param i Row index (indices start at zero; zero-based)
    /// @param j Column index (indices start at zero; zero-based)
    /// @param aij The value A(i,j) (duplicate values will be summed up)
    void put(size_t i, size_t j, double aij);
};
