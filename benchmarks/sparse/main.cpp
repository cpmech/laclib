#include "mpi.h"
#include <string>
#include <iostream>
#include "../../src/laclib.h"
#include "../../data/sparse-matrix/bfwb62_x_correct.h"
using namespace std;

// NOTE: the code must be wrapped within "run"
//   because the destructor of MumpsSolver relies
//   on the MPI, so cannot be called before MPI_Finalize
//   Also, this makes it convenient for try/catch

void run(int argc, char **argv)
{
    auto sw = Stopwatch::make_new();

    auto name = extract_first_argument(argc, argv, "bfwb62");
    auto path = path_get_current() + "/../../../data/sparse-matrix/";

    cout << "##### matrix name = " << name << endl;

    auto data = read_matrix_for_mumps(path + name + ".mtx");

    sw.stop("##### read matrix # ");
    sw.reset();

    auto mpi = MpiAux::make_new();
    auto solver = MumpsSolver::make_new(mpi, data.symmetric);
    auto options = MumpsOptions::make_new();
    auto sw_afs = Stopwatch::make_new();

    auto verbose = false;

    options.ordering = MUMPS_ORDERING_AMF;
    options.pct_inc_workspace = 100;
    options.max_work_memory = 30000;

    solver->analize_and_factorize(data.trip.get(), options, verbose);

    sw.stop("##### analize and fact # ");
    sw.reset();

    auto n = data.trip->n;
    auto rhs = vector<double>(n, 1.0);
    auto x = vector<double>(n, 0.0);
    auto rhs_is_distributed = false;

    solver->solve(x, rhs, rhs_is_distributed, verbose);

    sw.stop("##### solve # ");
    sw_afs.stop("##### ana, fact, and solve # ");

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