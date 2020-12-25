#pragma once
#include <vector>
#include <iostream>

template <typename T>
inline void vecvec_print(const std::vector<std::vector<T>> &vecvec)
{
    for (std::vector<T> row : vecvec)
    {
        for (T val : row)
        {
            std::cout << val << ", ";
        }
        std::cout << '\n';
    }
}