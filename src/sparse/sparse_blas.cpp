#include <memory>
#include <vector>

#include "coo_matrix.h"

void sp_mat_vec_mul(std::vector<double> &v,
                    double alpha,
                    const std::unique_ptr<CooMatrix> &a,
                    const std::vector<double> &u,
                    bool check_sizes,
                    bool fill_zeros) {
    if (check_sizes) {
        if (v.size() != a->dimension) {
            throw "sp_mat_vec_mul: size of v must be equal to the dimension of a";
        }
        if (u.size() != a->dimension) {
            throw "sp_mat_vec_mul: size of u must be equal to the dimension of a";
        }
    }
    if (fill_zeros) {
        std::fill(v.begin(), v.end(), 0.0);
    }
    for (size_t k = 0; k < a->pos; k++) {
        auto i = a->indices_i[k];
        auto j = a->indices_j[k];
        auto aij = a->values_aij[k];
        v[i] += alpha * aij * u[j];
        if (is_symmetric(a->layout)) {
            if (i != j) {
                v[j] += alpha * aij * u[i];
            }
        }
    }
}
