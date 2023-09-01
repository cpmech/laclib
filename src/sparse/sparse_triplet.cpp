#include "sparse_triplet.h"

#include <algorithm> // fill
#include <memory>
#include <vector>

using namespace std;

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
    } else if (this->layout == UPPER_TRIANGULAR) {
        if (j < i) {
            throw "SparseTriplet::put: j < i is incorrect for upper triangular layout";
        }
    }

    // insert a new entry
    this->indices_i[this->pos] = i;
    this->indices_j[this->pos] = j;
    this->values_aij[this->pos] = aij;
    this->pos++;
}

/// @brief Sums duplicate column entries in each row of a CSR matrix
/// @return The final number of non-zeros (nnz) after duplicates have been handled
size_t _csr_sum_duplicates(size_t dimension, INT ap[], INT aj[], double ax[]) {

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
    return static_cast<size_t>(nnz);
}

template <class T1, class T2>
bool kv_pair_less(const std::pair<T1, T2> &x, const std::pair<T1, T2> &y) {
    return x.first < y.first;
}

CompressedSparseRowData SparseTriplet::to_csr(bool sum_duplicates) {

    // Based on the SciPy code from here:
    //
    // https://github.com/scipy/scipy/blob/main/scipy/sparse/sparsetools/coo.h
    //
    // Notes:
    //
    // * The row and column indices may be unordered (NOT TRUE)
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
        nnz,
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

    // write aj and ax into bj and bx (will use bp as workspace)
    for (size_t k = 0; k < nnz; k++) {
        INT row = ai[k];
        INT dest = bp[row];
        bj[dest] = aj[k];
        bx[dest] = ax[k];
        bp[row]++;
    }

    // fix bp
    size_t last = 0;
    for (size_t i = 0; i <= n_row; i++) {
        INT temp = bp[i];
        bp[i] = last;
        last = temp;
    }

    // sort rows
    std::vector<std::pair<INT, double>> temp;
    for (size_t i = 0; i < n_row; i++) {
        INT row_start = bp[i];
        INT row_end = bp[i + 1];
        temp.resize(row_end - row_start);
        for (INT jj = row_start, n = 0; jj < row_end; jj++, n++) {
            temp[n].first = bj[jj];
            temp[n].second = bx[jj];
        }
        std::sort(temp.begin(), temp.end(), kv_pair_less<INT, double>);
        for (INT jj = row_start, n = 0; jj < row_end; jj++, n++) {
            bj[jj] = temp[n].first;
            bx[jj] = temp[n].second;
        }
    }

    // sum duplicates
    if (sum_duplicates) {
        auto final_nnz = _csr_sum_duplicates(n_row, bp, bj, bx);
        csr.nnz = final_nnz;
    }

    // results
    return csr;
}
