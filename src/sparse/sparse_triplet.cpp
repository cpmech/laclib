#include "sparse_triplet.h"

#include <algorithm> // fill
#include <iostream>
#include <memory>
#include <vector>

void SparseTriplet::put(INT i, INT j, double aij) {

    // check range
    if (i < 0 || i >= static_cast<INT>(this->dimension)) {
        throw "SparseTriplet::put: index of row is outside range";
    }
    if (j < 0 || j >= static_cast<INT>(this->dimension)) {
        throw "SparseTriplet::put: index of column is outside range";
    }
    if (this->pos >= this->max) {
        throw "SparseTriplet::put: max number of items has been exceeded";
    }
    if (this->layout == LOWER_TRIANGULAR) {
        if (j > i) {
            throw "SparseTriplet::put: j > i is incorrect for lower triangular layout";
        }
    }

    // insert a new entry
    this->indices_i[this->pos] = i;
    this->indices_j[this->pos] = j;
    this->values_aij[this->pos] = aij;
    this->pos++;
}

/// @brief Sums duplicate column entries in each row of a CSR matrix
void _csr_sum_duplicates(size_t dimension, INT ap[], INT aj[], double ax[]) {

    // Based on the SciPy code from here:
    //
    // https://github.com/scipy/scipy/blob/main/scipy/sparse/sparsetools/csr.h
    //
    // * ap[n_row+1] -- row pointer
    // * aj[nnz(A)]  -- column indices
    // * ax[nnz(A)]  -- non-zeros
    // * The column indices within each row must be sorted
    // * Explicit zeros are retained
    // * ap, aj, and ax will be modified inplace

    INT n_row = make_int(dimension);
    INT nnz = 0;
    INT row_end = 0;
    for (INT i = 0; i < n_row; i++) {
        INT jj = row_end;
        row_end = ap[i + 1];
        while (jj < row_end) {
            INT j = aj[jj];
            double x = ax[jj];
            jj++;
            while (jj < row_end && aj[jj] == j) {
                x += ax[jj];
                jj++;
            }
            aj[nnz] = j;
            ax[nnz] = x;
            nnz++;
        }
        ap[i + 1] = nnz;
    }
}

CompressedSparseRowData SparseTriplet::to_csr(bool sum_duplicates) {

    // Based on the SciPy code from here:
    //
    // https://github.com/scipy/scipy/blob/main/scipy/sparse/sparsetools/coo.h
    //
    // Notes:
    //
    // * The row and column indices may be unordered
    // * Linear complexity: O(nnz(A) + max(n_row,n_col))

    // access triplet data
    auto ai = this->indices_i.data();
    auto aj = this->indices_j.data();
    auto ax = this->values_aij.data();

    // allocate vectors
    auto n_row = this->dimension;
    auto nnz = this->pos;
    auto csr = CompressedSparseRowData{
        std::vector<INT>(n_row + 1, 0), // row_pointers
        std::vector<INT>(nnz, 0),       // column_indices
        std::vector<double>(nnz, 0.0),  // values
    };
    auto bp = csr.row_pointers.data();
    auto bj = csr.column_indices.data();
    auto bx = csr.values.data();

    // compute number of non-zero entries per row of A
    std::fill(bp, bp + n_row, 0);
    for (size_t k = 0; k < nnz; k++) {
        bp[ai[k]]++;
    }

    // perform the cumulative sum of the nnz per row to get bp[]
    INT cum_sum = 0;
    for (size_t i = 0; i < n_row; i++) {
        INT temp = bp[i];
        bp[i] = cum_sum;
        cum_sum += temp;
    }
    bp[n_row] = nnz;

    // write aj and ax into bj and bx
    for (size_t n = 0; n < nnz; n++) {
        INT row = ai[n];
        INT dest = bp[row];
        bj[dest] = aj[n];
        bx[dest] = ax[n];
        bp[row]++;
    }
    for (size_t i = 0, last = 0; i <= n_row; i++) {
        INT temp = bp[i];
        bp[i] = last;
        last = temp;
    }

    // sum duplicates
    if (sum_duplicates) {
        _csr_sum_duplicates(n_row, bp, bj, bx);
    }

    // results
    return csr;
}
