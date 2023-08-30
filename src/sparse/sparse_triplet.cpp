#include "sparse_triplet.h"

#include <iostream>
#include <memory>
#include <tuple>
#include <vector>

void SparseTriplet::put(size_t i, size_t j, double aij) {

    // check range
    if (i >= this->dimension) {
        throw "SparseTriplet::put: index of row is outside range";
    }
    if (j >= this->dimension) {
        throw "SparseTriplet::put: index of column is outside range";
    }
    if (this->pos >= this->max) {
        throw "SparseTriplet::put: max number of items has been exceeded";
    }
    if (this->lower_triangular) {
        if (j > i) {
            throw "SparseTriplet::put: j > i is incorrect for lower triangular layout";
        }
    }

    // find existent entry
    ij_pair_t ij = {i, j};
    auto result = this->ij_to_pos.find(ij);

    if (result != this->ij_to_pos.end()) {
        // sum duplicate entry
        auto p = result->second; // pos
        this->values_aij[p] += aij;

    } else {
        // insert a new entry
        this->indices_i[this->pos] = i;
        this->indices_j[this->pos] = j;
        this->ij_to_pos[ij] = this->pos;
        this->values_aij[this->pos] = aij;
        this->pos++;
    }
}
