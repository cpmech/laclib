#pragma once
#include "../../src/laclib.h"
#include "../../data/sparse-matrix/bfwb62_x_correct.h"

void check(const std::string &name, const std::vector<double> &x, )
{
    if (name == "bfwb62")
    {
        if (equal_vectors_tol(x, bfwb62_x_correct, 1e-10, true))
        {
            mpi.pf("\n### OK ###\n\n");
        }
        else
        {
            mpi.pf("\nERROR\n\n");
        }
    }
}