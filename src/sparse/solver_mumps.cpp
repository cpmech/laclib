#include <memory>
#include <vector>
#include <algorithm>
#include "dmumps_c.h"
#include "solver_mumps.h"

int MumpsSolver::analize_and_factorize(TripletForMumps *trip, const MumpsOptions &options, bool verbose)
{
    if (!mpi.belong())
    {
        throw "MumpsSolver::analize_and_factorize: must only be called by processors in the group";
    }

    handle_options_and_set_distributed(&this->data, options);

    this->data.n = make_mumps_int(trip->m);
    this->data.nz_loc = make_mumps_int8(trip->pos);
    this->data.irn_loc = trip->I.data();
    this->data.jcn_loc = trip->J.data();
    this->data.a_loc = trip->X.data();

    this->factorized = false;

    auto status = call_dmumps(&this->data, MUMPS_JOB_ANALIZE_AND_FACTORIZE, verbose);

    if (status == 0)
    {
        this->factorized = true;
    }

    return status;
}

int MumpsSolver::solve(std::vector<double> &x, const std::vector<double> &rhs, bool rhs_is_distributed, bool verbose)
{
    if (!mpi.belong())
    {
        throw "MumpsSolver::analize_and_factorize: must only be called by processors in the group";
    }

    if (!this->factorized)
    {
        throw "MumpsSolver::solve: factorization must be completed first";
    }

    if (x.size() != rhs.size())
    {
        throw "MumpsSolver::solve: x and rhs vectors must have the same size";
    }

    if (rhs_is_distributed)
    {
        std::fill(x.begin(), x.end(), 0.0);
        this->mpi.reduce_sum(x, rhs);
    }
    else
    {
        if (this->mpi.rank() == 0)
        {
            x = rhs;
        }
    }

    if (this->mpi.rank() == 0)
    {
        this->data.rhs = x.data();
    }

    auto status = call_dmumps(&this->data, MUMPS_JOB_SOLVE, verbose);

    return status;
}

void MumpsSolver::terminate()
{
    auto status = call_dmumps(&this->data, MUMPS_JOB_TERMINATE, false);

    if (status != 0)
    {
        throw "MumpsSolver::terminate: cannot terminate MUMPS";
    }

    this->factorized = false;
}