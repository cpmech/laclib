#pragma once
#include "../../src/laclib.h"
#include "../../data/sparse-matrix/bfwb62_x_correct.h"
#include <memory>
#include <vector>
#include <iostream>
#include <cmath>

void check_x(MpiAux &mpi,
             const std::string &matrix_name,
             const std::vector<double> &x)
{
    if (mpi.rank() != 0)
    {
        return;
    }
    if (matrix_name == "bfwb62")
    {
        if (equal_vectors_tol(x, bfwb62_x_correct, 1e-10, true))
        {
            std::cout << "\n### OK: x ###\n";
        }
        else
        {
            std::cout << "\nERROR: x\n";
        }
    }
}

struct ErrorReport
{
    double linf_norm_ax;   // inf norm of a*x
    double linf_norm_diff; // inf norm of a*x - rhs
    double relative_error; // linf_norm_diff / (linf_norm_ax + 1)
};

// check that a*x = rhs
ErrorReport check_ax(MpiAux &mpi,
                     const std::string &matrix_name,
                     const std::unique_ptr<SparseTriplet> &a,
                     const std::vector<double> &x,
                     const std::vector<double> &rhs,
                     double tolerance = 1e-5)
{
    if (matrix_name == "bfwb62")
    {
        tolerance = 1e-14;
    }

    auto m = a->m;
    std::vector<double> ax(m, 0.0); // a*x

    if (mpi.size() > 1)
    {
        std::vector<double> ax_local(m, 0.0);
        sp_matvecmul(ax_local, 1.0, a, x, true, false);
        mpi.reduce_sum(ax, ax_local);
    }
    else
    {
        sp_matvecmul(ax, 1.0, a, x, true, false);
    }

    if (mpi.rank() != 0)
    {
        return ErrorReport{0, 0, 0};
    }

    auto idx_max_ax = idamax(m, ax, 1);
    auto linf_norm_ax = fabs(ax[idx_max_ax]);

    daxpy(m, -1.0, rhs, 1, ax, 1); // ax := -rhs + ax => diff

    auto idx_max_diff = idamax(m, ax, 1);
    auto linf_norm_diff = fabs(ax[idx_max_diff]);
    auto relative_error = linf_norm_diff / (linf_norm_ax + 1.0);

    std::cout << std::endl;
    std::cout << "linf_norm(a*x)     = " << linf_norm_ax << "\n";
    std::cout << "linf_norm(a*x-rhs) = " << linf_norm_diff << "\n";
    std::cout << "relative_error     = " << relative_error << "\n";

    if (relative_error > tolerance)
    {
        std::cout << "\nERROR: a*x\n";
    }
    else
    {
        std::cout << "\n### OK: a*x ###\n";
    }

    return ErrorReport{
        linf_norm_ax,
        linf_norm_diff,
        relative_error,
    };
}