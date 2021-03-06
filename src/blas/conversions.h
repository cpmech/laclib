#pragma once
#include <vector>

// vecvec_to_colmaj converts nested vector into an array representing a col-major matrix
//
//   Example:
//             _      _
//            |  0  3  |
//        a = |  1  4  |            ⇒     data = [0, 1, 2, 3, 4, 5]
//            |_ 2  5 _|(m x n)
//
//        data[i+j*m] = a[i][j]
//
//   NOTE: make sure to have at least 1x1 item
//
template <typename T>
inline std::vector<T> vecvec_to_colmaj(const std::vector<std::vector<T>> &a)
{
    if (a.size() < 1)
    {
        throw "vecvec_to_col_major: a.size() must be greater than zero";
    }
    auto m = a.size();
    auto n = a[0].size();
    auto data = std::vector<T>(m * n, 0.0);
    size_t k = 0;
    for (size_t j = 0; j < n; j++)
    {
        for (size_t i = 0; i < m; i++)
        {
            data[k] = a[i][j];
            k++;
        }
    }
    return data;
}

// colmaj_to_vecvec converts col-major matrix to nested vector
// see vecvec_to_col_major()
template <typename T>
inline std::vector<std::vector<T>> colmaj_to_vecvec(size_t m, size_t n, const std::vector<T> &data)
{
    auto a = std::vector<std::vector<T>>(m, std::vector<T>(n, 0));
    for (size_t i = 0; i < m; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            a[i][j] = data[i + j * m];
        }
    }
    return a;
}

// extract_row extracts i row from (m,n) col-major matrix
template <typename T>
inline std::vector<T> colmaj_extract_row(size_t i, size_t m, size_t n, const std::vector<T> &a)
{
    auto rowi = std::vector<T>(n, 0.0);
    for (size_t j = 0; j < n; j++)
    {
        rowi[j] = a[i + j * m];
    }
    return rowi;
}

// extract_col extracts j column from (m,n) col-major matrix
template <typename T>
inline std::vector<T> colmaj_extract_col(size_t j, size_t m, size_t n, const std::vector<T> &a)
{
    auto colj = std::vector<T>(m, 0.0);
    for (size_t i = 0; i < m; i++)
    {
        colj[i] = a[i + j * m];
    }
    return colj;
}