#include <memory>
#include "dmumps_c.h"
#include "solver_mumps.h"

#define ICNTL(I) icntl[(I)-1] // macro s.t. indices match documentation

void MumpsSolver::initialize(MumpsOptions options)
{
    this->data.comm_fortran = MUMPS_USE_COMM_WORLD;
    this->options = options;
    this->data.par = 1; // host also works
    this->data.sym = options.symmetry;
    this->data.job = MUMPS_JOB_INIT;
    dmumps_c(&this->data);
    this->called_initialize = true;
}

void MumpsSolver::analize_and_factorize(TripletForMumps *trip)
{
    if (!this->called_initialize)
    {
        throw "MumpsSolver::analize_and_factorize: must call initialize first";
    }

    this->data.n = make_mumps_int(trip->m);
    this->data.nnz = make_mumps_int8(trip->pos);
    this->data.irn = trip->I.data();
    this->data.jcn = trip->J.data();
    this->data.a = trip->X.data();
}

/*
    // define the problem on the host
    if (mpi_rank == 0)
    {
        // this->data.rhs = rhs;
    }
}
*/

void MumpsSolver::terminate()
{
    if (!this->called_initialize)
    {
        throw "MumpsSolver::terminate: must call initialize first";
    }

    this->data.job = MUMPS_JOB_END;
    dmumps_c(&this->data);
}

#undef ICNTL
