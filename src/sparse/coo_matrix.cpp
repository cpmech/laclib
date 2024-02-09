#include "coo_matrix.h"

void CooMatrix::put(INT i, INT j, double aij) {

    // check range
    if (i < 0 || i >= static_cast<INT>(this->dimension)) {
        throw "CooMatrix::put: index of row is outside range";
    }
    if (j < 0 || j >= static_cast<INT>(this->dimension)) {
        throw "CooMatrix::put: index of column is outside range";
    }
    if (this->pos >= this->max) {
        throw "CooMatrix::put: max number of items has been exceeded";
    }
    if (this->layout == LOWER_TRIANGULAR) {
        if (j > i) {
            throw "CooMatrix::put: j > i is incorrect for lower triangular layout";
        }
    } else if (this->layout == UPPER_TRIANGULAR) {
        if (j < i) {
            throw "CooMatrix::put: j < i is incorrect for upper triangular layout";
        }
    }

    // insert a new entry
    this->indices_i[this->pos] = i;
    this->indices_j[this->pos] = j;
    this->values_aij[this->pos] = aij;
    this->pos++;
}

void CooMatrix::to_matrix(std::unique_ptr<Matrix> &a) {
    auto m = a->nrow;
    auto n = a->ncol;
    if (m > this->dimension || n > this->dimension) {
        throw "wrong matrix dimensions";
    }
    auto m_int = make_int(m);
    auto n_int = make_int(n);
    a->fill(0.0);
    for (size_t p = 0; p < this->pos; p++) {
        if (this->indices_i[p] < m_int && this->indices_j[p] < n_int) {
            a->add(this->indices_i[p], this->indices_j[p], this->values_aij[p]);
        }
    }
}

#define DO_VALUES
#define EMPTY (-1)

// Tim Davis' UMFPACK::UMF_triplet_map_x (umf_triplet.c)
int coo_to_csc(
    int n_row,
    int n_col,
    int nz,
    int Ap[],         /* size n_col + 1 */
    int Ai[],         /* size nz */
    double Ax[],      /* size nz */
    const int Ti[],   /* size nz */
    const int Tj[],   /* size nz */
    const double Tx[] /* size nz */
) {

    int nn = n_row;
    if (n_col > nn) {
        nn = n_col;
    }

    auto Rp = std::vector<int>(n_row + 1);
    auto Rj = std::vector<int>(nz);
    auto Rx = std::vector<double>(nz);
    auto RowCount = std::vector<int>(n_row);
    auto W = std::vector<int>(nn);

    /* ---------------------------------------------------------------------- */
    /* local variables */
    /* ---------------------------------------------------------------------- */

    int i, j, k, p, cp, p1, p2, pdest, pj;

    /* ---------------------------------------------------------------------- */
    /* count the entries in each row (also counting duplicates) */
    /* ---------------------------------------------------------------------- */

    /* use W as workspace for row counts (including duplicates) */
    for (i = 0; i < n_row; i++) {
        W[i] = 0;
    }

    for (k = 0; k < nz; k++) {
        i = Ti[k];
        j = Tj[k];
        if (i < 0 || i >= n_row || j < 0 || j >= n_col) {
            return 666; // UMFPACK_ERROR_invalid_matrix
        }
        W[i] += 1;
    }

    /* ---------------------------------------------------------------------- */
    /* compute the row pointers */
    /* ---------------------------------------------------------------------- */

    Rp[0] = 0;
    for (i = 0; i < n_row; i++) {
        Rp[i + 1] = Rp[i] + W[i];
        W[i] = Rp[i];
    }

    /* W is now equal to the row pointers */

    /* ---------------------------------------------------------------------- */
    /* construct the row form */
    /* ---------------------------------------------------------------------- */

    for (k = 0; k < nz; k++) {
        i = Ti[k];
        p = W[i];
        Rj[p] = Tj[k];
        Rx[p] = Tx[k];
        W[i] += 1;
    }

    /* Rp stays the same, but W [i] is advanced to the start of row i+1 */

    /* ---------------------------------------------------------------------- */
    /* sum up duplicates */
    /* ---------------------------------------------------------------------- */

    /* use W [j] to hold position in Ri/Rx/Rz of a_ij, for row i [ */

    for (j = 0; j < n_col; j++) {
        W[j] = EMPTY;
    }

    for (i = 0; i < n_row; i++) {
        p1 = Rp[i];
        p2 = Rp[i + 1];
        pdest = p1;
        /* At this point, W [j] < p1 holds true for all columns j, */
        /* because Ri/Rx/Rz is stored in row oriented order. */
        for (p = p1; p < p2; p++) {
            j = Rj[p];
            // ASSERT(j >= 0 && j < n_col);
            pj = W[j];
            if (pj >= p1) {
                /* this column index, j, is already in row i, at position pj */
                // ASSERT(pj < p);
                // ASSERT(Rj[pj] == j);
                /* sum the entry */
                Rx[pj] += Rx[p];
            } else {
                /* keep the entry */
                /* also keep track in W[j] of position of a_ij for case above */
                W[j] = pdest;
                /* no need to move the entry if pdest is equal to p */
                if (pdest != p) {
                    Rj[pdest] = j;
                    Rx[pdest] = Rx[p];
                }
                pdest += 1;
            }
        }
        RowCount[i] = pdest - p1;
    }

    /* done using W for position of a_ij ] */

    /* ---------------------------------------------------------------------- */
    /* merge Map and Map2 into a single Map */
    /* ---------------------------------------------------------------------- */

    /* now the kth triplet maps to p = Map [k], and thus to Rj/Rx [p] */

    /* ---------------------------------------------------------------------- */
    /* count the entries in each column */
    /* ---------------------------------------------------------------------- */

    /* [ use W as work space for column counts of A */
    for (j = 0; j < n_col; j++) {
        W[j] = 0;
    }

    for (i = 0; i < n_row; i++) {
        for (p = Rp[i]; p < Rp[i] + RowCount[i]; p++) {
            j = Rj[p];
            // ASSERT(j >= 0 && j < n_col);
            W[j] += 1;
        }
    }

    /* ---------------------------------------------------------------------- */
    /* create the column pointers */
    /* ---------------------------------------------------------------------- */

    Ap[0] = 0;
    for (j = 0; j < n_col; j++) {
        Ap[j + 1] = Ap[j] + W[j];
    }
    /* done using W as workspace for column counts of A ] */

    for (j = 0; j < n_col; j++) {
        W[j] = Ap[j];
    }

    /* ---------------------------------------------------------------------- */
    /* construct the column form */
    /* ---------------------------------------------------------------------- */

    for (i = 0; i < n_row; i++) {
        for (p = Rp[i]; p < Rp[i] + RowCount[i]; p++) {
            cp = W[Rj[p]]++;
            Ai[cp] = i;
            Ax[cp] = Rx[p];
        }
    }

    // success
    return 0;
}
