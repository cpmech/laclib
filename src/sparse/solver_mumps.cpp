#include <algorithm>
#include <memory>
#include <vector>
#include "dmumps_c.h"
#include "solver_mumps.h"
#include "solver_mumps_constants.h"
#include "solver_mumps_options.h"

#define ICNTL(I) icntl[(I)-1] // macro to make indices match documentation

static inline void _set_data(DMUMPS_STRUC_C *data,
                             const MumpsOptions &options,
                             const std::unique_ptr<SparseTriplet> &trip,
                             int mpi_size)
{
    data->ICNTL(5) = 0; // assembled matrix (not elemental)
    data->ICNTL(7) = options.ordering;
    data->ICNTL(8) = options.scaling;
    data->ICNTL(14) = options.pct_inc_workspace;
    data->ICNTL(23) = options.max_work_memory;

    if (mpi_size > 1)
    {
        MUMPS_INT ord = options.ordering == MUMPS_ORDERING_SCOTCH ? 1 : 2; // pt-scotch or ParMetis

        data->ICNTL(6) = 0;    // no col perm for distr matrix => set this to remove warning
        data->ICNTL(18) = 3;   // use distributed matrix
        data->ICNTL(28) = 2;   // parallel computation
        data->ICNTL(29) = ord; // parallel ordering tool

        data->n = make_mumps_int(trip->m);
        data->nz_loc = make_mumps_int8(trip->pos);
        data->irn_loc = trip->I.data();
        data->jcn_loc = trip->J.data();
        data->a_loc = trip->X.data();
    }
    else
    {
        data->ICNTL(6) = 7;  // automatic col perm
        data->ICNTL(18) = 0; // matrix is centralized on the host
        data->ICNTL(28) = 1; // sequential computation
        data->ICNTL(29) = 0; // auto => ignored

        data->n = make_mumps_int(trip->m);
        data->nz = make_mumps_int8(trip->pos);
        data->irn = trip->I.data();
        data->jcn = trip->J.data();
        data->a = trip->X.data();
    }
}

void SolverMumps::analyze(const std::unique_ptr<SparseTriplet> &trip,
                          const MumpsOptions &options,
                          bool verbose)
{
    if (!this->mpi->belong())
    {
        throw "SolverMumps::analyze: must only be called by processors in the group";
    }

    _set_data(&this->data, options, trip, this->mpi->size());

    this->analyzed = false;
    this->factorized = false;

    _call_dmumps(&this->data, MUMPS_JOB_ANALIZE, verbose);

    this->analyzed = true;
}

void SolverMumps::factorize(bool verbose)
{
    if (!mpi->belong())
    {
        throw "SolverMumps::factorize: must only be called by processors in the group";
    }

    if (!this->analyzed)
    {
        throw "SolverMumps::factorize: analysis must be completed first";
    }

    this->factorized = false;

    _call_dmumps(&this->data, MUMPS_JOB_FACTORIZE, verbose);

    this->factorized = true;
}

void SolverMumps::analyze_and_factorize(const std::unique_ptr<SparseTriplet> &trip,
                                        const MumpsOptions &options,
                                        bool verbose)
{
    if (!this->mpi->belong())
    {
        throw "SolverMumps::analize_and_factorize: must only be called by processors in the group";
    }

    _set_data(&this->data, options, trip, this->mpi->size());

    this->factorized = false;

    _call_dmumps(&this->data, MUMPS_JOB_ANALIZE_AND_FACTORIZE, verbose);

    this->factorized = true;
}

void SolverMumps::solve(std::vector<double> &x,
                        const std::vector<double> &rhs,
                        bool rhs_is_distributed,
                        bool verbose)
{
    if (!this->mpi->belong())
    {
        throw "SolverMumps::analize_and_factorize: must only be called by processors in the group";
    }

    if (!this->factorized)
    {
        throw "SolverMumps::solve: factorization must be completed first";
    }

    if (x.size() != rhs.size())
    {
        throw "SolverMumps::solve: x and rhs vectors must have the same size";
    }

    int mpi_rank = this->mpi->rank();
    int mpi_size = this->mpi->size();

    if (rhs_is_distributed)
    {
        std::fill(x.begin(), x.end(), 0.0);
        this->mpi->reduce_sum(x, rhs);
    }
    else
    {
        if (this->mpi->rank() == 0)
        {
            x = rhs;
        }
    }

    if (mpi_rank == 0)
    {
        this->data.rhs = x.data();
    }

    _call_dmumps(&this->data, MUMPS_JOB_SOLVE, verbose);

    if (mpi_size > 1)
    {
        this->mpi->broadcast_from_root(x);
    }
}

#undef ICNTL
