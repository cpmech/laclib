#include "solver_mumps.h"

#include <algorithm>
#include <memory>
#include <vector>

#include "dmumps_c.h"
#include "solver_mumps_constants.h"
#include "solver_mumps_options.h"

#define ICNTL(I) icntl[(I)-1] // macro to make indices match documentation

inline MUMPS_INT8 make_mumps_int8(size_t a) {
    MUMPS_INT8 n = static_cast<MUMPS_INT8>(a);
    size_t temp = static_cast<size_t>(n);
    if (a != temp) {
        throw "make_mumps_int8: integer overflow ocurred";
    }
    return n;
}

void SolverMumps::analyze(const std::unique_ptr<CooMatrix> &coo,
                          bool verbose) {

    // convert indices
    this->indices_i.resize(coo->pos);
    this->indices_j.resize(coo->pos);
    for (size_t k = 0; k < coo->pos; k++) {
        this->indices_i[k] = coo->indices_i[k] + 1;
        this->indices_j[k] = coo->indices_j[k] + 1;
    }

    // set flags
    this->data.ICNTL(5) = MUMPS_ICNTL5_ASSEMBLED_MATRIX;
    this->data.ICNTL(7) = options->ordering;
    this->data.ICNTL(8) = options->scaling;
    this->data.ICNTL(14) = options->pct_inc_workspace;
    this->data.ICNTL(23) = options->max_work_memory;
    this->data.ICNTL(16) = options->omp_num_threads;
    this->data.n = static_cast<INT>(coo->dimension);

    // set more flags
    this->data.ICNTL(18) = MUMPS_ICNTL18_CENTRALIZED;
    this->data.ICNTL(6) = MUMPS_ICNTL6_PERMUT_AUTO;
    this->data.nz = make_mumps_int8(coo->pos);
    this->data.irn = this->indices_i.data();
    this->data.jcn = this->indices_j.data();
    this->data.a = coo->values_aij.data();

    // final flags
    this->data.ICNTL(28) = MUMPS_ICNTL28_SEQUENTIAL;
    this->data.ICNTL(29) = 0; // ignored

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

void SolverMumps::analyze_and_factorize(const std::unique_ptr<CooMatrix> &coo,
                                        bool verbose) {
    this->analyze(coo, verbose);
    this->factorize(verbose);
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
