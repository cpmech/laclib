#pragma once
#include "../../src/laclib.h"
#include "../../data/sparse-matrix/bfwb62_x_correct.h"
#include <memory>
#include <vector>
#include <iostream>

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
            std::cout << "\n### OK ###\n\n";
        }
        else
        {
            std::cout << "\nERROR\n\n";
        }
    }
}

// check that |a*x - rhs| <= tol
void check_solution(MpiAux &mpi,
                    const std::unique_ptr<TripletForMumps> &a,
                    const std::vector<double> &x,
                    const std::vector<double> &rhs,
                    double tolerance = 1e-15)
{
    std::vector<double> a_x(a->m, 0.0);
    sp_matvecmul(a_x, 1.0, a, x, true, false);
    // TODO
}