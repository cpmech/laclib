#include <memory>
#include <vector>
#include "dmumps_c.h"
#include "solver_mumps.h"

#define ICNTL(I) icntl[(I)-1] // macro to make indices match documentation

void icntl_set_verbose(DMUMPS_STRUC_C &data, bool verbose)
{
    if (verbose)
    {
        data.ICNTL(1) = 6; // standard output stream
        data.ICNTL(2) = 0; // output stream
        data.ICNTL(3) = 6; // standard output stream
        data.ICNTL(4) = 2; // errors, warnings, and main statistics printed
    }
    else
    {
        data.ICNTL(1) = -1; // no output messages
        data.ICNTL(2) = -1; // no warnings
        data.ICNTL(3) = -1; // no global information
        data.ICNTL(4) = -1; // message level
    }
}

void MumpsSolver::initialize(MumpsOptions options)
{
    this->options = options;
    this->data.comm_fortran = MUMPS_USE_COMM_WORLD;
    this->data.par = 1; // host also works
    this->data.sym = options.symmetry;

    this->data.job = MUMPS_JOB_INITIALIZE;
    dmumps_c(&this->data);

    icntl_set_verbose(this->data, options.verbose);
    this->called_initialize = true;
    this->called_analize_and_factorize = false;
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

    this->data.job = MUMPS_JOB_ANALIZE_AND_FACTORIZE;
    dmumps_c(&this->data);

    this->called_analize_and_factorize = true;
}

void MumpsSolver::solve(std::vector<double> &input_rhs_output_x, bool iam_root_proc)
{
    if (!this->called_analize_and_factorize)
    {
        throw "MumpsSolver::solve: must call analize_and_factorize first";
    }

    if (iam_root_proc)
    {
        this->data.rhs = &input_rhs_output_x[0];
    }

    this->data.job = MUMPS_JOB_SOLVE;
    dmumps_c(&this->data);
}

void MumpsSolver::terminate()
{
    if (!this->called_initialize)
    {
        throw "MumpsSolver::terminate: must call initialize first";
    }

    this->data.job = MUMPS_JOB_TERMINATE;
    dmumps_c(&this->data);

    this->called_initialize = false;
    this->called_analize_and_factorize = false;
}

#undef ICNTL
