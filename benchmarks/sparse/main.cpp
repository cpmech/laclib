#include "mpi.h"
#include <string>
#include "../../src/laclib.h"
#include "../../data/sparse-matrix/bfwb62_x_correct.h"
using namespace std;

// NOTE: the code must be wrapped within "run"
//   because the destructor of MumpsSolver relies
//   on the MPI, so cannot be called before MPI_Finalize
//   Also, this makes it convenient for try/catch

void run(int argc, char **argv)
{
    auto mpi = MpiAux::make_new();
    auto sw = Stopwatch::make_new();
    auto name = extract_first_argument(argc, argv, "bfwb62");

    mpi.pf("reading matrix (%s)\n", name.c_str());

    auto path = path_get_current() + "/../../../data/sparse-matrix/";
    auto data = read_matrix_for_mumps(path + name + ".mtx");

    mpi.pf("... symmetric = %s\n", data.symmetric ? "true" : "false");
    mpi.pf("... number of rows (equal to columns) = %zd\n", data.trip->m);
    mpi.pf("... number of non-zeros (pattern entries) = %zd\n", data.trip->pos);
    sw.stop("... ", true);
    mpi.pf("... memory usage = %d kb\n", memory_usage());
    mpi.pf("initializing (mumps)\n");

    auto solver = MumpsSolver::make_new(mpi, data.symmetric);
    auto options = MumpsOptions::make_new();
    auto verbose = true;

    options.ordering = MUMPS_ORDERING_AMF;
    options.pct_inc_workspace = 100;
    options.max_work_memory = 30000;

    solver->analyze(data.trip.get(), options, verbose);

    sw.stop("... ", true);
    mpi.pf("... memory usage = %d kb\n", memory_usage());
    mpi.pf("factorizing (mumps)\n");

    solver->factorize(verbose);

    sw.stop("... ", true);
    mpi.pf("... memory usage = %d kb\n", memory_usage());
    mpi.pf("solving (mumps)\n");

    auto n = data.trip->n;
    auto rhs = vector<double>(n, 1.0);
    auto x = vector<double>(n, 0.0);
    auto rhs_is_distributed = false;

    solver->solve(x, rhs, rhs_is_distributed, verbose);

    sw.stop("... ", true);
    mpi.pf("... memory usage = %d kb\n", memory_usage());

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

int main(int argc, char **argv)
{
    MPI_Init(&argc, &argv);

    try
    {
        run(argc, argv);
    }
    CATCH_ALL

    MPI_Finalize();
    return 0;
}