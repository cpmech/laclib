#include <memory>
#include "dmumps_c.h"
#include "solver_mumps.h"

#define ICNTL(I) icntl[(I)-1] // macro s.t. indices match documentation

void MumpsSolver::init(MumpsOptions options)
{
    this->options = options;
    this->data.par = 1; // host also works
    this->data.sym = options.symmetry;
    this->data.job = MUMPS_JOB_INIT;
    dmumps_c(&this->data);
}

/*
    // define the problem on the host
    if (mpi_rank == 0)
    {
        this->data.n = make_mumps_int(trip.m);
        this->data.nnz = make_mumps_int8(trip.pos);
        this->data.irn = trip.I.data();
        this->data.jcn = trip.J.data();
        this->data.a = trip.X.data();
        // this->data.rhs = rhs;
    }
}
*/

void MumpsSolver::terminate()
{
    this->data.job = MUMPS_JOB_END;
    dmumps_c(&this->data);
}

#undef ICNTL
