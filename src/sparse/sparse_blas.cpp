#include <memory>
#include <vector>
#include "triplet_for_mumps.h"

void sp_matvecmul(std::vector<double> &v,
                  double alpha,
                  const std::unique_ptr<TripletForMumps> &a,
                  const std::vector<double> &u,
                  bool check_sizes,
                  bool fill_zeros)
{
    if (check_sizes)
    {
        if (v.size() != a->m)
        {
            throw "size of v must be equal to the number of rows of a";
        }
        if (u.size() != a->n)
        {
            throw "size of u must be equal to the number of columns of a";
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
    }
}