#pragma once
#include <cmath>
#include <vector>
#include "double.h"

inline double norm_inf(const std::vector<double> &x)
{
    auto idx_max_abs = idamax(x.size(), x, 1);
    return fabs(x[idx_max_abs]);
}
