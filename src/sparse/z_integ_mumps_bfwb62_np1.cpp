#include <vector>
#include <iostream>
#include "solver_mumps.h"
#include "read_matrix_for_mumps.h"
#include "../check/check.h"
#include "../mpiaux/mpiaux.h"
#include "../util/doctest_mpi.h"
#include "../util/path_tools.h"
#include "../util/print_vector.h"
#include "../../data/sparse-matrix/bfwb62_x_correct.h"
using namespace std;

MPI_TEST_CASE("solve bfwb62 system", 1)
{
    auto data_path = path_get_current() + "/../../../data";
    auto mtx_path = data_path + "/sparse-matrix/bfwb62.mtx";
    auto data = read_matrix_for_mumps(mtx_path);

    MumpsSymmetry sym = data.symmetric ? MUMPS_SYMMETRY_GENERAL : MUMPS_SYMMETRY_NONE;

    auto mpi = MpiAux::make_new();
    auto solver = MumpsSolver::make_new(mpi, sym);
    auto options = MumpsOptions::make_new();
    auto rhs_is_distributed = false;
    auto verbose = true;

    solver->analize_and_factorize(data.trip.get(), options, verbose);
    CHECK(solver.get()->factorized == true);

    size_t n = data.trip->n;
    auto rhs = vector<double>(n, 1.0);
    auto x = vector<double>(n, 0.0);

    solver->solve(x, rhs, rhs_is_distributed, verbose);

    cout << "\n";
    print_vector("x", x);
    cout << "\n";
    print_vector("x_correct", bfwb62_x_correct);
    cout << "\n";

    CHECK(equal_vectors_tol(x, bfwb62_x_correct, 1e-10, true) == true);
}