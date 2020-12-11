#include <cmath>
#include <vector>

template <class T>
bool equal_int_vectors(const std::vector<T> &a, const std::vector<T> &b)
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

template <class T>
bool equal_flt_vectors(const std::vector<T> &a, const std::vector<T> &b, T tolerance)
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
