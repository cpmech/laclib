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

// check that a*x = rhs
void check_ax(MpiAux &mpi,
              const std::string &matrix_name,
              const std::unique_ptr<SparseTriplet> &a,
              const std::vector<double> &x,
              const std::vector<double> &rhs,
              double tolerance = 1e-6)
{
    if (matrix_name == "bfwb62")
    {
        tolerance = 1e-14;
    }

    auto m = a->m;
    std::vector<double> b(m, 0.0); // b := a*x

    if (mpi.size() > 1)
    {
        std::vector<double> b_local(m, 0.0);
        sp_matvecmul(b_local, 1.0, a, x, true, false);
        mpi.reduce_sum(b, b_local);
    }
    else
    {
        sp_matvecmul(b, 1.0, a, x, true, false);
    }

    if (mpi.rank() != 0)
    {
        return;
    }

    daxpy(m, -1.0, rhs, 1, b, 1); // b := -rhs + b
    auto idx = idamax(m, b, 1);
    auto linf_norm = fabs(b[idx]);

    std::cout << "\nlinf_norm(a*x-rhs) = " << linf_norm << "\n";

    if (linf_norm > tolerance)
    {
        std::cout << "\nERROR: a*x\n";
    }
    else
    {
        std::cout << "\n### OK: a*x ###\n";
    }
}