#pragma once
#include "../../src/laclib.h"
#include "../../data/sparse-matrix/bfwb62_x_correct.h"
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
            std::cout << "\n### OK: x ###\n";
        }
        else
        {
            std::cout << "\nERROR: x\n";
        }
    }
}
