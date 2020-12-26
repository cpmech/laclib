#pragma once
#include <vector>
#include <string>
#include <cmath>
#include <cstdio>
#include <complex>

template <typename T>
inline void print_colmaj(std::string name,
                         std::string fmt,
                         size_t m,
                         size_t n,
                         const std::vector<T> &a,
                         double tol_zero_ignore = 1e-17)
{
    if (name != "")
    {
        printf("%s =\n", name.c_str());
    }
    for (size_t i = 0; i < m; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            if (fabs(a[i + j * m]) < tol_zero_ignore)
            {
                printf(fmt.c_str(), 0);
            }
            else
            {
                printf(fmt.c_str(), a[i + j * m]);
            }
        }
        printf("\n");
    }
}