#include "mpi.h"
#include <string>
#include <iostream>
#include "../../src/mpiaux/mpiaux.h"
#include "../../src/check/check.h"
#include "../../src/util/catch_all.h"
#include "../../src/util/extract_arguments.h"
#include "../../src/util/path_tools.h"
#include "../../src/sparse/read_matrix_for_mumps.h"
#include "../../src/sparse/solver_mumps.h"
#include "../../data/sparse-matrix/bfwb62_x_correct.h"
using namespace std;

int main(int argc, char **argv)
try
{
    MPI_Init(&argc, &argv);

    auto name = extract_first_argument(argc, argv, "bfwb62");
    auto path = path_get_current() + "/../../../data/sparse-matrix/";
    auto data = read_matrix_for_mumps(path + name + ".mtx");

    cout << "matrix name = " << name << endl;

    auto mpi = MpiAux::make_new();
    auto solver = MumpsSolver::make_new(mpi, data.symmetric);
    auto options = MumpsOptions::make_new();
    auto verbose = true;

    solver->analize_and_factorize(data.trip.get(), options, verbose);

    auto n = data.trip->n;
    auto rhs = vector<double>(n, 1.0);
    auto x = vector<double>(n, 0.0);
    auto rhs_is_distributed = false;

    solver->solve(x, rhs, rhs_is_distributed, verbose);

    if (name == "bfwb62")
    {
        if (equal_vectors_tol(x, bfwb62_x_correct, 1e-10, true))
        {
            cout << "\n### OK ###\n\n";
        }
        else
        {
            cout << "\nERROR\n\n";
        }
    }

    MPI_Finalize();
    return 0;
}
CATCH_ALL