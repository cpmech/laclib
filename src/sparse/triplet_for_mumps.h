#pragma once
#include <vector>
#include <memory>
#include "dmumps_c.h"

inline MUMPS_INT make_mumps_int(size_t a)
{
    MUMPS_INT n = static_cast<MUMPS_INT>(a);
    size_t temp = static_cast<size_t>(n);
    if (a != temp)
    {
        throw "make_mumps_int: integer overflow ocurred";
    }
    return n;
}

inline MUMPS_INT8 make_mumps_int8(size_t a)
{
    MUMPS_INT8 n = static_cast<MUMPS_INT8>(a);
    size_t temp = static_cast<size_t>(n);
    if (a != temp)
    {
        throw "make_mumps_int8: integer overflow ocurred";
    }
    return n;
}

struct TripletForMumps
{
    size_t m;                 // number of rows
    size_t n;                 // number of columns
    size_t pos;               // current index => nnz in the end
    size_t max;               // max allowed number of entries
    bool symmetric;           // symmetric matrix?, but WITHOUT both sides of the diagonal
    std::vector<MUMPS_INT> I; // one-based indices stored here, regardless the input
    std::vector<MUMPS_INT> J; // one-based indices stored here, regardless the input
    std::vector<double> X;    // all the values

    inline static std::unique_ptr<TripletForMumps> make_new(size_t m, size_t n, size_t max)
    {
        make_mumps_int(m);   // check if size_t fits MUMPS_INT
        make_mumps_int(n);   // check if size_t fits MUMPS_INT
        make_mumps_int(max); // check if size_t fits MUMPS_INT

        return std::unique_ptr<TripletForMumps>{new TripletForMumps{
            m,
            n,
            0,
            max,
            false,
            std::vector<MUMPS_INT>(max, 0),
            std::vector<MUMPS_INT>(max, 0),
            std::vector<double>(max, 0.0),
        }};
    }

    void put_zero_based(size_t i_zero_based, size_t j_zero_based, double x);
    void put_one_based(size_t i_one_based, size_t j_one_based, double x);
};