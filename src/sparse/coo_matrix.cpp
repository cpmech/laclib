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
