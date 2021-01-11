#include "stdio.h"
#include <vector>
#include <memory>
#include <iostream>
#include "dmumps_c.h"
#include "sparse_triplet.h"

void SparseTriplet::put(size_t i_zero_based,
                        size_t j_zero_based,
                        double x,
                        bool check_overflow)
{
    if (i_zero_based < 0 || i_zero_based >= this->m)
    {
        throw "SparseTriplet::put: index of row is outside range";
    }
    if (j_zero_based < 0 || j_zero_based >= this->n)
    {
        throw "SparseTriplet::put: index of column is outside range";
    }
    if (this->pos >= this->max)
    {
        throw "SparseTriplet::put: max number of items has been exceeded";
    }
    if (this->onebased)
    {
        if (check_overflow)
        {
            this->I[this->pos] = make_mumps_int(i_zero_based + 1);
            this->J[this->pos] = make_mumps_int(j_zero_based + 1);
        }
        else
        {
            this->I[this->pos] = static_cast<MUMPS_INT>(i_zero_based + 1);
            this->J[this->pos] = static_cast<MUMPS_INT>(j_zero_based + 1);
        }
    }
    else
    {
        if (check_overflow)
        {
            this->I[this->pos] = make_mumps_int(i_zero_based);
            this->J[this->pos] = make_mumps_int(j_zero_based);
        }
        else
        {
            this->I[this->pos] = static_cast<MUMPS_INT>(i_zero_based);
            this->J[this->pos] = static_cast<MUMPS_INT>(j_zero_based);
        }
    }
    this->X[this->pos] = x;
    this->pos++;
}

std::unique_ptr<SparseTriplet> SparseTriplet::partition_by_nnz(int mpi_rank, int mpi_size)
{
    if (mpi_rank < 0)
    {
        throw "SparseTriplet::partition_by_nnz: mpi_rank must be greater than or equal to 0";
    }
    if (mpi_size < 1)
    {
        throw "SparseTriplet::partition_by_nnz: mpi_size must be greater than or equal to 1";
    }
    if (mpi_rank >= mpi_size)
    {
        throw "SparseTriplet::partition_by_nnz: mpi_rank must be smaller than mpi_size";
    }

    size_t nnz = this->pos;
    size_t rank = static_cast<size_t>(mpi_rank);
    size_t size = static_cast<size_t>(mpi_size);
    size_t start = (rank * nnz) / size;
    size_t endp1 = ((rank + 1) * nnz) / size;

    size_t nnz_new = endp1 - start;
    auto trip_new = SparseTriplet::make_new(this->m, this->n, nnz_new, this->onebased, this->symmetric);

    size_t d = this->onebased ? 1 : 0;
    bool check_overflow = false;
    for (size_t k = start; k < endp1; k++)
    {
        trip_new->put(this->I[k] - d, this->J[k] - d, this->X[k], check_overflow);
    }

    return trip_new;
}
