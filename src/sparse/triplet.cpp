#include "stdio.h"
#include <vector>
#include <memory>
#include <iostream>
#include <stdexcept>
#include "triplet.h"

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