#include "stdio.h"
#include <vector>
#include <memory>
#include <iostream>
#include "dmumps_c.h"
#include "triplet_for_mumps.h"

std::unique_ptr<TripletForMumps> triplet_for_mumps_new(size_t m, size_t n, size_t max)
{
    make_mumps_int(m + 1);   // check if size_t fits MUMPS_INT
    make_mumps_int(n + 1);   // check if size_t fits MUMPS_INT
    make_mumps_int(max + 1); // check if size_t fits MUMPS_INT

    return std::unique_ptr<TripletForMumps>{new TripletForMumps{
        m,
        n,
        0,
        max,
        std::vector<MUMPS_INT>(max, 0),
        std::vector<MUMPS_INT>(max, 0),
        std::vector<double>(max, 0.0),
    }};
}

void TripletForMumps::put_zero_based(size_t i_zero_based, size_t j_zero_based, double x)
{
    if (i_zero_based < 0 || i_zero_based >= this->m)
    {
        throw "TripletForMumps::put_zero_based: index of row is outside range";
    }
    if (j_zero_based < 0 || j_zero_based >= this->n)
    {
        throw "TripletForMumps::put_zero_based: index of column is outside range";
    }
    if (this->pos >= this->max)
    {
        throw "TripletForMumps::put_zero_based: max number of items has been exceeded";
    }
    MUMPS_INT i = static_cast<MUMPS_INT>(i_zero_based + 1);
    MUMPS_INT j = static_cast<MUMPS_INT>(j_zero_based + 1);
    this->I[this->pos] = i;
    this->J[this->pos] = j;
    this->X[this->pos] = x;
    this->pos++;
}

void TripletForMumps::put_one_based(size_t i_one_based, size_t j_one_based, double x)
{
    if (i_one_based <= 0 || i_one_based > this->m)
    {
        throw "TripletForMumps::put_one_based: index of row is outside range";
    }
    if (j_one_based <= 0 || j_one_based > this->n)
    {
        throw "TripletForMumps::put_one_based: index of column is outside range";
    }
    if (this->pos >= this->max)
    {
        throw "TripletForMumps::put_one_based: max number of items has been exceeded";
    }
    MUMPS_INT i = static_cast<MUMPS_INT>(i_one_based);
    MUMPS_INT j = static_cast<MUMPS_INT>(j_one_based);
    this->I[this->pos] = i;
    this->J[this->pos] = j;
    this->X[this->pos] = x;
    this->pos++;
}

MUMPS_INT make_mumps_int(size_t a)
{
    MUMPS_INT n = static_cast<MUMPS_INT>(a);
    size_t temp = static_cast<size_t>(n);
    if (a != temp)
    {
        throw "make_mumps_int: integer overflow ocurred";
    }
    return n;
}

MUMPS_INT8 make_mumps_int8(size_t a)
{
    MUMPS_INT8 n = static_cast<MUMPS_INT8>(a);
    size_t temp = static_cast<size_t>(n);
    if (a != temp)
    {
        throw "make_mumps_int8: integer overflow ocurred";
    }
    return n;
}
