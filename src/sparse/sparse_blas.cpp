#include <memory>
#include <vector>
#include "triplet_for_mumps.h"

void sp_matvecmul(std::vector<double> &v,
                  double alpha,
                  const std::unique_ptr<TripletForMumps> &a,
                  const std::vector<double> &u)
{
    if (v.size() != a->m)
    {
        throw "v.size must be equal to a.m";
    }
    std::fill(v.begin(), v.end(), 0.0);
    for (size_t k = 0; k < a->pos; k++)
    {
        auto i = a->I[k] - 1;
        auto j = a->J[k] - 1;
        auto aij = a->X[k];
        v[i] += alpha * aij * u[j];
    }
}