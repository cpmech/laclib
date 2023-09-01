#include "csr_matrix.h"

#include <algorithm> // fill
#include <memory>

/// @brief Sums duplicate column entries in each row of a CSR matrix
/// @return The final number of non-zeros (nnz) after duplicates have been handled
/// @note INTERNAL FUNCTION
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

/// @brief Compares two values (for sorting)
/// @note INTERNAL FUNCTION
template <class T1, class T2>
bool _kv_pair_less(const std::pair<T1, T2> &x, const std::pair<T1, T2> &y) {
    return x.first < y.first;
}

std::unique_ptr<CsrMatrix> CsrMatrix::from(std::unique_ptr<SparseTriplet> &coo) {

    // Based on the SciPy code from here:
    //
    // https://github.com/scipy/scipy/blob/main/scipy/sparse/sparsetools/coo.h
    //
    // Notes:
    //
    // * The row and column indices may be unordered (NOT TRUE)
    // * Linear complexity: O(nnz(A) + max(n_row,n_col))

    // access triplet data
    auto ai = coo->indices_i.data();
    auto aj = coo->indices_j.data();
    auto ax = coo->values_aij.data();

    // allocate vectors
    auto n_row = coo->dimension;
    auto nnz = coo->pos;
    auto csr = std::unique_ptr<CsrMatrix>{new CsrMatrix{
        coo->dimension,
        nnz,
        std::vector<INT>(n_row + 1, 0), // row_pointers
        std::vector<INT>(nnz, 0),       // column_indices
        std::vector<double>(nnz, 0.0),  // values
    }};
    auto bp = csr->row_pointers.data();
    auto bj = csr->column_indices.data();
    auto bx = csr->values.data();

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
        std::sort(temp.begin(), temp.end(), _kv_pair_less<INT, double>);
        for (INT jj = row_start, n = 0; jj < row_end; jj++, n++) {
            bj[jj] = temp[n].first;
            bx[jj] = temp[n].second;
        }
    }

    // sum duplicates
    auto final_nnz = _csr_sum_duplicates(n_row, bp, bj, bx);
    csr->nnz = final_nnz;

    // results
    return csr;
}

#ifdef USE_MKL
std::unique_ptr<CsrMatrixMkl> CsrMatrixMkl::from(std::unique_ptr<SparseTriplet> &coo) {
    // access triplet data
    auto ai = coo->indices_i.data();
    auto aj = coo->indices_j.data();
    auto ax = coo->values_aij.data();

    // create COO MKL matrix
    auto m = make_int(coo->dimension);
    auto nnz = make_int(coo->pos);
    sparse_matrix_t coo_mkl;
    auto status = mkl_sparse_d_create_coo(&coo_mkl, SPARSE_INDEX_BASE_ZERO, m, m, nnz, ai, aj, ax);
    if (status != SPARSE_STATUS_SUCCESS) {
        throw "Intel MKL failed to create COO matrix";
    }

    // convert COO to CSR
    sparse_matrix_t csr;
    status = mkl_sparse_convert_csr(coo_mkl, SPARSE_OPERATION_NON_TRANSPOSE, &csr);
    if (status != SPARSE_STATUS_SUCCESS) {
        throw "Intel MKL failed to convert COO matrix to CSR matrix";
    }

    // get access to internal arrays
    sparse_index_base_t indexing;
    MKL_INT *pointer_b = NULL; // size = dimension
    MKL_INT *pointer_e = NULL; // size = dimension, last entry == nnz (when zero-based)
    MKL_INT *columns = NULL;   // size = nnz
    double *values = NULL;     // size = nnz

    // NOTE about mkl_sparse_d_export_csr
    // The routine returns pointers to the internal representation
    // and DOES NOT ALLOCATE additional memory.
    // https://www.intel.com/content/www/us/en/docs/onemkl/developer-reference-c/2023-2/mkl-sparse-export-csr.html

    status = mkl_sparse_d_export_csr(csr, &indexing, &m, &m, &pointer_b, &pointer_e, &columns, &values);
    if (status != SPARSE_STATUS_SUCCESS) {
        throw "Intel MKL failed to export csr matrix";
    }

    // compute the row indices vector because we need a CSR3 matrix
    MKL_INT *row_pointers = (MKL_INT *)malloc((m + 1) * sizeof(MKL_INT));
    if (row_pointers == NULL) {
        throw "cannot allocate row_indices";
    }
    for (MKL_INT i = 0; i < m; i++) {
        row_pointers[i] = pointer_b[i];
    }
    row_pointers[m] = pointer_e[m - 1];

    // final number of non-zero values
    MKL_INT final_nnz = row_pointers[m];

    // results
    return std::unique_ptr<CsrMatrixMkl>{new CsrMatrixMkl{
        m,
        final_nnz,
        row_pointers,
        columns,
        values,
    }};
}
#endif // USE_MKL
