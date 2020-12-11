#include <vector>
#include <memory>

struct Triplet
{
    size_t m;
    size_t n;
    size_t pos;
    size_t max;
    std::vector<size_t> I;
    std::vector<size_t> J;
    std::vector<double> X;
};

std::unique_ptr<Triplet> triplet_new(size_t m, size_t n, size_t max);

void triplet_put(Triplet *const T, size_t i, size_t j, double x);

void triplet_print(const Triplet *const T);
