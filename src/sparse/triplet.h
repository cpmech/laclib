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

    inline static std::unique_ptr<Triplet> make_new(size_t m, size_t n, size_t max)
    {
        return std::unique_ptr<Triplet>{new Triplet{
            m,
            n,
            0,
            max,
            std::vector<size_t>(max, 0),
            std::vector<size_t>(max, 0),
            std::vector<double>(max, 0.0),
        }};
    }

    void put(size_t i, size_t j, double x);
};