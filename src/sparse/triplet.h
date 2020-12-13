#pragma once
#include <vector>
#include <memory>

struct Triplet
{
    size_t m;
    size_t n;
    size_t pos; // nnz in the end
    size_t max;
    std::vector<size_t> I; // zero-based indices
    std::vector<size_t> J; // zero-based indices
    std::vector<double> X;

    void put(size_t i, size_t j, double x);
};

std::unique_ptr<Triplet> triplet_new(size_t m, size_t n, size_t max);

void triplet_put(Triplet *const T, size_t i, size_t j, double x);
