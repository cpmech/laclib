#include "sparse_triplet.h"

#include <iostream>
#include <memory>
#include <tuple>
#include <vector>

void SparseTriplet::put(size_t i_zero_based,
                        size_t j_zero_based,
                        double x,
                        bool check_overflow) {

    // check range
    if (i_zero_based < 0 || i_zero_based >= this->m) {
        throw "SparseTriplet::put: index of row is outside range";
    }
    if (j_zero_based < 0 || j_zero_based >= this->n) {
        throw "SparseTriplet::put: index of column is outside range";
    }
    if (this->pos >= this->max) {
        throw "SparseTriplet::put: max number of items has been exceeded";
    }

    // find existent entry
    ij_pair_t ij = {i_zero_based, j_zero_based};
    auto result = this->ij_to_pos.find(ij);

    if (result != this->ij_to_pos.end()) {
        // sum duplicate entry
        auto p = result->second; // pos
        this->X[p] += x;

    } else {
        // assign new entry
        if (this->one_based) {
            if (check_overflow) {
                this->I[this->pos] = make_int(i_zero_based + 1);
                this->J[this->pos] = make_int(j_zero_based + 1);
            } else {
                this->I[this->pos] = static_cast<INT>(i_zero_based + 1);
                this->J[this->pos] = static_cast<INT>(j_zero_based + 1);
            }
        } else {
            if (check_overflow) {
                this->I[this->pos] = make_int(i_zero_based);
                this->J[this->pos] = make_int(j_zero_based);
            } else {
                this->I[this->pos] = static_cast<INT>(i_zero_based);
                this->J[this->pos] = static_cast<INT>(j_zero_based);
            }
        }
        this->ij_to_pos[ij] = this->pos;
        this->X[this->pos] = x;
        this->pos++;
    }
}
