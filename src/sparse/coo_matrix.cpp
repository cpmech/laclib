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
