#pragma once
#include <cmath>
#include <vector>

template <typename T>
inline bool equal_vectors(const std::vector<T> &a, const std::vector<T> &b)
{
    if (a.size() != b.size())
    {
        return false;
    }
    for (size_t i = 0; i < a.size(); i++)
    {
        if (a[i] != b[i])
        {
            return false;
        }
    }
    return true;
}

template <typename T>
inline bool equal_vectors_tol(const std::vector<T> &a, const std::vector<T> &b, T tolerance)
{
    if (a.size() != b.size())
    {
        return false;
    }
    for (size_t i = 0; i < a.size(); i++)
    {
        if (fabs(double(a[i]) - double(b[i])) > tolerance)
        {
            return false;
        }
    }
    return true;
}

template <typename T>
inline bool equal_scalars_tol(T a, T b, T tolerance)
{
    if (fabs(double(a) - double(b)) > tolerance)
    {
        return false;
    }
    return true;
}