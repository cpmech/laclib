#pragma once
#include <vector>
#include "double.h"

inline double norm_inf(const std::vector<double> &x)
{
    auto idx_max_abs = idamax(x.size(), x, 1);
    return x[idx_max_abs];
}
