#include <vector>
#include "../check/check.h"
#include "../mpiaux/mpiaux.h"
#include "../util/doctest_mpi.h"
#include "../util/path_tools.h"
#include "read_matrix_for_mumps.h"
using namespace std;

MPI_TEST_CASE("read_matrix_for_mumps (NP2)", 2)
{
    auto data_path = path_get_current() + "/../../../data/sparse-matrix/";
    auto mtx = data_path + "ok1.mtx";

    auto mpi = MpiAux::make_new();
    auto trip = read_matrix_for_mumps(mtx, mpi.rank(), mpi.size());

    if (mpi.rank() == 0)
    {
        vector<MUMPS_INT> Icorrect = {1, 2, 1, 3, 5, 2};
        vector<MUMPS_INT> Jcorrect = {1, 1, 2, 2, 2, 3};
        vector<double> Xcorrect = {2, 3, 3, -1, 4, 4};

        CHECK(trip->symmetric == false);
        CHECK(equal_vectors(trip->I, Icorrect) == true);
        CHECK(equal_vectors(trip->J, Jcorrect) == true);
        CHECK(equal_vectors_tol(trip->X, Xcorrect, 1e-15) == true);
    }
    else
    {
        vector<MUMPS_INT> Icorrect = {3, 4, 5, 3, 2, 5};
        vector<MUMPS_INT> Jcorrect = {3, 3, 3, 4, 5, 5};
        vector<double> Xcorrect = {-3, 1, 2, 2, 6, 1};

        CHECK(trip->symmetric == false);
        CHECK(equal_vectors(trip->I, Icorrect) == true);
        CHECK(equal_vectors(trip->J, Jcorrect) == true);
        CHECK(equal_vectors_tol(trip->X, Xcorrect, 1e-15) == true);
    }
}