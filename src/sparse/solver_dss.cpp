#include <iostream>
#include <memory>

#include "csr_matrix.h"
#include "mkl_dss.h"
#include "solver_dss.h"

void SolverDss::analyze(const std::unique_ptr<CsrMatrixMkl> &csr, bool verbose) {
    this->analyzed = false;
    this->factorized = false;

    if (csr->layout == LOWER_TRIANGULAR) {
        throw "DSS requires upper triangular or general matrices";
    }

    // initialize the solver
    auto error = dss_create(this->handle, this->dss_opt);
    if (error != MKL_DSS_SUCCESS) {
        throw "DSS failed when creating the solver handle";
    }

    // define the non-zero structure of the matrix
    error = dss_define_structure(this->handle,
                                 this->dss_sym,
                                 csr->row_pointers,
                                 csr->dimension,
                                 csr->dimension,
                                 csr->column_indices,
                                 csr->nnz);
    if (error != MKL_DSS_SUCCESS) {
        throw "DSS failed when defining the non-zero structure of the matrix";
    }

    // reorder the matrix
    error = dss_reorder(this->handle, this->dss_opt, 0);
    if (error != MKL_DSS_SUCCESS) {
        throw "DSS failed when reordering the matrix";
    }

    this->analyzed = true;
}

void SolverDss::factorize(const std::unique_ptr<CsrMatrixMkl> &csr, bool verbose) {
    if (!this->analyzed) {
        throw "DSS factorize requires that the analysis be completed first";
    }

    this->factorized = false;

    // factor the matrix
    auto error = dss_factor_real(this->handle, this->dss_type, csr->values);
    if (error != MKL_DSS_SUCCESS) {
        throw "DSS failed when factorizing the matrix";
    }

    // Important: dss_statistics must be called after dss_factor_real
    if (verbose) {
        // get the determinant (not for a diagonal matrix)
        if (csr->dimension < csr->nnz) {
            _CHARACTER_t stat_in[] = "determinant";
            _DOUBLE_PRECISION_t stat_out[5];
            auto error = dss_statistics(this->handle, this->dss_opt, stat_in, stat_out);
            if (error != MKL_DSS_SUCCESS) {
                throw "DSS statistics failed";
            }
            // print the determinant
            std::cout << "the determinant power is " << stat_out[0] << std::endl;
            std::cout << "the determinant base is " << stat_out[1] << std::endl;
        }
    }

    this->factorized = true;
}

void SolverDss::analyze_and_factorize(const std::unique_ptr<CsrMatrixMkl> &csr, bool verbose) {
    if (csr->layout == LOWER_TRIANGULAR) {
        throw "DSS requires upper triangular or general matrices";
    }
    this->analyze(csr);
    this->factorize(csr, verbose);
}

void SolverDss::solve(std::vector<double> &x,
                      const std::vector<double> &rhs,
                      bool verbose) {
    if (!this->factorized) {
        throw "DSS solve requires that the factorization be completed first";
    }

    // get the solution vector
    MKL_INT n_rhs = 1;
    auto error = dss_solve_real(this->handle,
                                this->dss_opt,
                                rhs.data(),
                                n_rhs,
                                x.data());
    if (error != MKL_DSS_SUCCESS) {
        throw "DSS failed when solving the system";
    }
}
