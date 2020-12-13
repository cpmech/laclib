#pragma once
#include <vector>
#include <memory>
#include "dmumps_c.h"

struct TripletForMumps
{
    size_t m;
    size_t n;
    size_t pos; // nnz in the end
    size_t max;
    std::vector<MUMPS_INT> I; // one-based indices stored here, regardless the input
    std::vector<MUMPS_INT> J; // one-based indices stored here, regardless the input
    std::vector<double> X;

    void put_zero_based(size_t i_zero_based, size_t j_zero_based, double x);
    void put_one_based(size_t i_one_based, size_t j_one_based, double x);
};

std::unique_ptr<TripletForMumps> triplet_for_mumps_new(size_t m, size_t n, size_t max);

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
