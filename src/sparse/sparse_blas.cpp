#include <memory>
#include <vector>
#include "sparse_triplet.h"

void sp_matvecmul(std::vector<double> &v,
                  double alpha,
                  const std::unique_ptr<SparseTriplet> &a,
                  const std::vector<double> &u,
                  bool check_sizes,
                  bool fill_zeros)
{
    bool do_mirror = a->symmetric;
    if (check_sizes)
    {
        if (v.size() != a->m)
        {
            throw "sp_matvecmul: size of v must be equal to the number of rows of a";
        }
        if (u.size() != a->n)
        {
            throw "sp_matvecmul: size of u must be equal to the number of columns of a";
        }
        if (do_mirror)
        {
            if (a->m != a->n)
            {
                throw "sp_matvecmul: can only consider mirror values if a is square";
            }
        }
    }
    if (fill_zeros)
    {
        std::fill(v.begin(), v.end(), 0.0);
    }
    for (size_t k = 0; k < a->pos; k++)
    {
        auto i = a->I[k] - 1;
        auto j = a->J[k] - 1;
        auto aij = a->X[k];
        v[i] += alpha * aij * u[j];
        if (do_mirror)
        {
            if (i != j)
            {
                v[j] += alpha * aij * u[i];
            }
        }
    }
}
