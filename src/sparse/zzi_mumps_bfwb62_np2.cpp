#include <vector>
#include <iostream>
#include "solver_mumps.h"
#include "read_matrix_market.h"
#include "../check/check.h"
#include "../mpiaux/mpiaux.h"
#include "../util/doctest_mpi.h"
#include "../util/path_tools.h"
#include "../util/print_vector.h"
#include "../../data/sparse-matrix/bfwb62_x_correct.h"
using namespace std;

MPI_TEST_CASE("solve bfwb62 system", 2)
{
    auto data_path = path_get_current() + "/../../../data";
    auto mtx_path = data_path + "/sparse-matrix/bfwb62.mtx";
    bool onebased = true;
    auto trip_full = read_matrix_market(mtx_path, onebased);
    auto symmetric = trip_full->symmetric;
    auto n = trip_full->n;
    auto rhs = vector<double>(n, 1.0);
    auto x = vector<double>(n, 0.0);
    auto mpi = MpiAux::make_new();

    SUBCASE("centralized matrix")
    {
        auto options = MumpsOptions::make_new(symmetric);
        auto solver = SolverMumps::make_new(mpi, options);

        solver->analyze_and_factorize(trip_full);
        CHECK(solver.get()->analyzed == true);
        CHECK(solver.get()->factorized == true);

        solver->solve(x, rhs);
        CHECK(equal_vectors_tol(x, bfwb62_x_correct, 1e-10, true) == true);
    }

    SUBCASE("distributed matrix")
    {
        auto trip = trip_full->partition_by_row(mpi->rank(), mpi->size());

        auto options = MumpsOptions::make_new(symmetric);
        options->distributed_matrix = true;

        auto solver = SolverMumps::make_new(mpi, options);

        solver->analyze_and_factorize(trip);
        CHECK(solver.get()->analyzed == true);
        CHECK(solver.get()->factorized == true);

        solver->solve(x, rhs);
        CHECK(equal_vectors_tol(x, bfwb62_x_correct, 1e-10, true) == true);
    }
}
