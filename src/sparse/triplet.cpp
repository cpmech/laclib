#include "stdio.h"
#include <vector>
#include <memory>
#include <iostream>
#include <stdexcept>
#include "triplet.h"

std::unique_ptr<Triplet> triplet_new(size_t m, size_t n, size_t max)
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

void Triplet::put(size_t i, size_t j, double x)
{
    if (i < 0 || i >= this->m)
    {
        throw "triplet_put: index of row is outside range";
    }
    if (j < 0 || j >= this->n)
    {
        throw "triplet_put: index of column is outside range";
    }
    if (this->pos >= this->max)
    {
        throw "triplet_put: max number of items has been exceeded";
    }
    this->I[this->pos] = i;
    this->J[this->pos] = j;
    this->X[this->pos] = x;
    this->pos++;
}
