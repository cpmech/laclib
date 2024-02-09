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
    int nrow,
    int ncol,
    int nz,
    int bp[],         /* size ncol + 1 */
    int bi[],         /* size nz */
    double bx[],      /* size nz */
    const int ai[],   /* size nz */
    const int aj[],   /* size nz */
    const double ax[] /* size nz */
) {

    int nn = nrow;
    if (ncol > nn) {
        nn = ncol;
    }

    auto rp = std::vector<int>(nrow + 1);
    auto rj = std::vector<int>(nz);
    auto rx = std::vector<double>(nz);
    auto rc = std::vector<int>(nrow);
    auto w = std::vector<int>(nn);

    /* ---------------------------------------------------------------------- */
    /* count the entries in each row (also counting duplicates) */
    /* ---------------------------------------------------------------------- */

    /* use W as workspace for row counts (including duplicates) */
    for (int i = 0; i < nrow; i++) {
        w[i] = 0;
    }

    for (int k = 0; k < nz; k++) {
        int i = ai[k];
        int j = aj[k];
        if (i < 0 || i >= nrow || j < 0 || j >= ncol) {
            return 666; // UMFPACK_ERROR_invalid_matrix
        }
        w[i] += 1;
    }

    /* ---------------------------------------------------------------------- */
    /* compute the row pointers */
    /* ---------------------------------------------------------------------- */

    rp[0] = 0;
    for (int i = 0; i < nrow; i++) {
        rp[i + 1] = rp[i] + w[i];
        w[i] = rp[i];
    }

    /* W is now equal to the row pointers */

    /* ---------------------------------------------------------------------- */
    /* construct the row form */
    /* ---------------------------------------------------------------------- */

    for (int k = 0; k < nz; k++) {
        int i = ai[k];
        int p = w[i];
        rj[p] = aj[k];
        rx[p] = ax[k];
        w[i] += 1;
    }

    /* Rp stays the same, but W [i] is advanced to the start of row i+1 */

    /* ---------------------------------------------------------------------- */
    /* sum up duplicates */
    /* ---------------------------------------------------------------------- */

    /* use W [j] to hold position in Ri/Rx/Rz of a_ij, for row i [ */

    for (int j = 0; j < ncol; j++) {
        w[j] = EMPTY;
    }

    for (int i = 0; i < nrow; i++) {
        int p1 = rp[i];
        int p2 = rp[i + 1];
        int pdest = p1;
        /* At this point, W [j] < p1 holds true for all columns j, */
        /* because Ri/Rx/Rz is stored in row oriented order. */
        for (int p = p1; p < p2; p++) {
            int j = rj[p];
            // ASSERT(j >= 0 && j < n_col);
            int pj = w[j];
            if (pj >= p1) {
                /* this column index, j, is already in row i, at position pj */
                // ASSERT(pj < p);
                // ASSERT(Rj[pj] == j);
                /* sum the entry */
                rx[pj] += rx[p];
            } else {
                /* keep the entry */
                /* also keep track in W[j] of position of a_ij for case above */
                w[j] = pdest;
                /* no need to move the entry if pdest is equal to p */
                if (pdest != p) {
                    rj[pdest] = j;
                    rx[pdest] = rx[p];
                }
                pdest += 1;
            }
        }
        rc[i] = pdest - p1;
    }

    /* done using W for position of a_ij ] */

    /* ---------------------------------------------------------------------- */
    /* count the entries in each column */
    /* ---------------------------------------------------------------------- */

    /* [ use W as work space for column counts of A */
    for (int j = 0; j < ncol; j++) {
        w[j] = 0;
    }

    for (int i = 0; i < nrow; i++) {
        for (int p = rp[i]; p < rp[i] + rc[i]; p++) {
            int j = rj[p];
            // ASSERT(j >= 0 && j < n_col);
            w[j] += 1;
        }
    }

    /* ---------------------------------------------------------------------- */
    /* create the column pointers */
    /* ---------------------------------------------------------------------- */

    bp[0] = 0;
    for (int j = 0; j < ncol; j++) {
        bp[j + 1] = bp[j] + w[j];
    }
    /* done using W as workspace for column counts of A ] */

    for (int j = 0; j < ncol; j++) {
        w[j] = bp[j];
    }

    /* ---------------------------------------------------------------------- */
    /* construct the column form */
    /* ---------------------------------------------------------------------- */

    for (int i = 0; i < nrow; i++) {
        for (int p = rp[i]; p < rp[i] + rc[i]; p++) {
            int cp = w[rj[p]]++;
            bi[cp] = i;
            bx[cp] = rx[p];
        }
    }

    // success
    return 0;
}
