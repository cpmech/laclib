#include "solver_mumps.h"

#include <algorithm>
#include <memory>
#include <vector>

#include "dmumps_c.h"
#include "solver_mumps_constants.h"
#include "solver_mumps_options.h"

#define ICNTL(I) icntl[(I)-1] // macro to make indices match documentation

static inline void _set_data(DMUMPS_STRUC_C *data,
                             const std::unique_ptr<MumpsOptions> &options,
                             const std::unique_ptr<SparseTriplet> &trip) {
    data->ICNTL(5) = MUMPS_ICNTL5_ASSEMBLED_MATRIX;
    data->ICNTL(7) = options->ordering;
    data->ICNTL(8) = options->scaling;
    data->ICNTL(14) = options->pct_inc_workspace;
    data->ICNTL(23) = options->max_work_memory;
    data->ICNTL(16) = options->omp_num_threads;
    data->n = make_mumps_int(trip->m);

    data->ICNTL(18) = MUMPS_ICNTL18_CENTRALIZED;
    data->ICNTL(6) = MUMPS_ICNTL6_PERMUT_AUTO;
    data->nz = make_mumps_int8(trip->pos);
    data->irn = trip->I.data();
    data->jcn = trip->J.data();
    data->a = trip->X.data();

    data->ICNTL(28) = MUMPS_ICNTL28_SEQUENTIAL;
    data->ICNTL(29) = 0; // ignored
}

void SolverMumps::analyze(const std::unique_ptr<SparseTriplet> &trip,
                          bool verbose) {
    _set_data(&this->data, this->options, trip);

    this->analyzed = false;
    this->factorized = false;

    _call_dmumps(&this->data, MUMPS_JOB_ANALYZE, verbose);

    this->analyzed = true;
}

void SolverMumps::factorize(bool verbose) {
    if (!this->analyzed) {
        throw "SolverMumps::factorize: analysis must be completed first";
    }

    this->factorized = false;

    _call_dmumps(&this->data, MUMPS_JOB_FACTORIZE, verbose);

    this->factorized = true;
}

void SolverMumps::analyze_and_factorize(const std::unique_ptr<SparseTriplet> &trip,
                                        bool verbose) {
    _set_data(&this->data, this->options, trip);

    this->analyzed = false;
    this->factorized = false;

    _call_dmumps(&this->data, MUMPS_JOB_ANALYZE_AND_FACTORIZE, verbose);

    this->analyzed = true;
    this->factorized = true;
}

void SolverMumps::solve(std::vector<double> &x,
                        const std::vector<double> &rhs,
                        bool verbose) {
    if (!this->factorized) {
        throw "SolverMumps::solve: factorization must be completed first";
    }

    if (x.size() != rhs.size()) {
        throw "SolverMumps::solve: x and rhs vectors must have the same size";
    }

    x = rhs;
    this->data.rhs = x.data();

    _call_dmumps(&this->data, MUMPS_JOB_SOLVE, verbose);
}

#undef ICNTL
