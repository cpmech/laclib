#include "stdio.h"
#include <vector>
#include <memory>
#include <iostream>
#include "dmumps_c.h"
#include "triplet_for_mumps.h"

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