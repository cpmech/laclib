#include <memory>
#include <vector>
#include "dmumps_c.h"
#include "solver_mumps.h"

int MumpsSolver::analize_and_factorize(TripletForMumps *trip, MumpsOrdering ordering, MumpsScaling scaling, bool verbose)
{
    this->data.n = make_mumps_int(trip->m);
    this->data.nnz = make_mumps_int8(trip->pos);
    this->data.irn = trip->I.data();
    this->data.jcn = trip->J.data();
    this->data.a = trip->X.data();

    handle_ordering_and_scaling(&this->data, ordering, scaling);

    // if (job == MUMPS_JOB_INITIALIZE)
    // {
    //     data->INFOG(18) = 3; // distributed matrix
    // }

    this->factorized = false;

    auto status = call_dmumps(&this->data, MUMPS_JOB_ANALIZE_AND_FACTORIZE, verbose);

    if (status == 0)
    {
        this->factorized = true;
    }

    return status;
}

int MumpsSolver::solve(std::vector<double> &input_rhs_output_x, bool iam_root_proc, bool verbose)
{
    if (!this->factorized)
    {
        throw "MumpsSolver::solve: factorization must be completed first";
    }

    if (iam_root_proc)
    {
        this->data.rhs = input_rhs_output_x.data();
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