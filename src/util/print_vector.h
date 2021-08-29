#pragma once
#include <iostream>
#include <string>
#include <vector>

template <typename T>
void print_vector(std::string name, const std::vector<T> &x) {
    std::cout << name << " = ";
    for (auto v : x) {
        std::cout << v << ", ";
    }
    std::cout << std::endl;
}
