#include "sparse_triplet.h"

#include <iostream>
#include <memory>
#include <vector>

#include "dmumps_c.h"
#include "stdio.h"

void SparseTriplet::put(size_t i_zero_based,
                        size_t j_zero_based,
                        double x,
                        bool check_overflow) {
    if (i_zero_based < 0 || i_zero_based >= this->m) {
        throw "SparseTriplet::put: index of row is outside range";
    }
    if (j_zero_based < 0 || j_zero_based >= this->n) {
        throw "SparseTriplet::put: index of column is outside range";
    }
    if (this->pos >= this->max) {
        throw "SparseTriplet::put: max number of items has been exceeded";
    }
    if (this->onebased) {
        if (check_overflow) {
            this->I[this->pos] = make_mumps_int(i_zero_based + 1);
            this->J[this->pos] = make_mumps_int(j_zero_based + 1);
        } else {
            this->I[this->pos] = static_cast<MUMPS_INT>(i_zero_based + 1);
            this->J[this->pos] = static_cast<MUMPS_INT>(j_zero_based + 1);
        }
    } else {
        if (check_overflow) {
            this->I[this->pos] = make_mumps_int(i_zero_based);
            this->J[this->pos] = make_mumps_int(j_zero_based);
        } else {
            this->I[this->pos] = static_cast<MUMPS_INT>(i_zero_based);
            this->J[this->pos] = static_cast<MUMPS_INT>(j_zero_based);
        }
    }
    this->X[this->pos] = x;
    this->pos++;
}
