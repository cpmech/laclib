#include "mpi.h"
#include <iostream>
#include "../../src/mpiaux/mpiaux.h"
#include "../../src/check/check.h"
#include "../../src/util/path_tools.h"
#include "../../src/sparse/read_matrix_for_mumps.h"
#include "../../src/sparse/solver_mumps.h"
#include "../../data/sparse-matrix/bfwb62_x_correct.h"
using namespace std;

int main(int argc, char **argv)
{
    MPI_Init(&argc, &argv);

    auto data_path = path_get_current() + "/../../../data";
    auto mtx_path = data_path + "/sparse-matrix/bfwb62.mtx";
    auto data = read_matrix_for_mumps(mtx_path);

    auto mpi = MpiAux::make_new();
    auto solver = MumpsSolver::make_new(mpi, data.symmetric);
    auto options = MumpsOptions::make_new();
    auto rhs_is_distributed = false;
    auto verbose = true;

    solver->analize_and_factorize(data.trip.get(), options, verbose);

    size_t n = data.trip->n;
    auto rhs = vector<double>(n, 1.0);
    auto x = vector<double>(n, 0.0);

    solver->solve(x, rhs, rhs_is_distributed, verbose);

    if (equal_vectors_tol(x, bfwb62_x_correct, 1e-10, true))
    {
        cout << "\n### OK ###\n\n";
    }

    MPI_Finalize();
    return 0;
}