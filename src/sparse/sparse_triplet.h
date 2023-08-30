#pragma once

#include <map>
#include <memory>
#include <tuple>
#include <vector>

#ifdef USE_MKL
#include "mkl.h"
#define INT MKL_INT
#else
#include "dmumps_c.h"
#undef I // some crazy cupcake defined this somewhere else
#define INT MUMPS_INT
#endif

inline INT make_int(size_t a) {
    INT n = static_cast<INT>(a);
    size_t temp = static_cast<size_t>(n);
    if (a != temp) {
        throw "make_mumps_int: integer overflow ocurred";
    }
    return n;
}

typedef std::tuple<INT, INT> ij_pair_t;

struct SparseTriplet {
    size_t m;              // number of rows
    size_t n;              // number of columns
    size_t pos;            // current index => nnz in the end
    size_t max;            // max allowed number of entries
    bool one_based;        // indices (i; j) start with 1 instead of 0 (e.g. for MUMPS)
    bool symmetric;        // symmetric matrix?, but WITHOUT one side of the diagonal
    std::vector<INT> I;    // zero- or one-based indices stored here
    std::vector<INT> J;    // zero- or one-based indices stored here
    std::vector<double> X; // the non-zero entries in the matrix

    // maps a pair of indices (i,j) to pos and assists in summing duplicates up
    std::map<ij_pair_t, size_t> ij_to_pos;

    inline static std::unique_ptr<SparseTriplet> make_new(size_t m,
                                                          size_t n,
                                                          size_t max,
                                                          bool one_based = false,
                                                          bool symmetric = false) {
        make_int(m);   // check if size_t fits INT
        make_int(n);   // check if size_t fits INT
        make_int(max); // check if size_t fits INT

        return std::unique_ptr<SparseTriplet>{new SparseTriplet{
            m,
            n,
            0,
            max,
            one_based,
            symmetric,
            std::vector<INT>(max, 0),
            std::vector<INT>(max, 0),
            std::vector<double>(max, 0.0),
            std::map<std::tuple<INT, INT>, size_t>(),
        }};
    }

    void put(size_t i_zero_based,
             size_t j_zero_based,
             double x,
             bool check_overflow = true);
};
