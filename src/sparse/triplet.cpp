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

void triplet_put(Triplet *const self, size_t i, size_t j, double x)
{
    if (i >= self->m)
    {
        throw "triplet_put: index of row is outside range";
    }
    if (j >= self->n)
    {
        throw "triplet_put: index of column is outside range";
    }
    if (self->pos >= self->max)
    {
        throw "triplet_put: max number of items has been exceeded";
    }
    self->I[self->pos] = i;
    self->J[self->pos] = j;
    self->X[self->pos] = x;
    self->pos++;
}

void triplet_print(const Triplet *const T)
{
    printf("m=%lu, n=%lu, nnz=%lu, max=%lu\n", T->m, T->n, T->pos, T->max);
    printf("I:\n");
    for (size_t i : T->I)
    {
        std::cout << i << " ";
    }
    printf("\nJ:\n");
    for (size_t j : T->J)
    {
        std::cout << j << " ";
    }
    printf("\nX:\n");
    for (double x : T->X)
    {
        std::cout << x << " ";
    }
    printf("\n");
}
