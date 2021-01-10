#include <vector>
#include "../check/check.h"
#include "../mpiaux/mpiaux.h"
#include "../util/doctest_mpi.h"
#include "../util/path_tools.h"
#include "read_matrix_market.h"
using namespace std;

MPI_TEST_CASE("read_matrix_market (NP2)", 2)
{
    auto data_path = path_get_current() + "/../../../data/sparse-matrix/";
    auto mtx = data_path + "ok1.mtx";

    auto mpi = MpiAux::make_new();
    auto trip = read_matrix_market(mtx);

    if (mpi.rank() == 0)
    {
        vector<MUMPS_INT> Icorrect = {0, 1, 0, 2, 4, 1, 2, 3, 4, 2, 1, 4};
        vector<MUMPS_INT> Jcorrect = {0, 0, 1, 1, 1, 2, 2, 2, 2, 3, 4, 4};
        vector<double> Xcorrect = {2, 3, 3, -1, 4, 4, -3, 1, 2, 2, 6, 1};

        CHECK(trip->symmetric == false);
        CHECK(equal_vectors(trip->I, Icorrect) == true);
        CHECK(equal_vectors(trip->J, Jcorrect) == true);
        CHECK(equal_vectors_tol(trip->X, Xcorrect, 1e-15) == true);
    }
    else
    {
        vector<MUMPS_INT> Icorrect = {0, 1, 0, 2, 4, 1, 2, 3, 4, 2, 1, 4};
        vector<MUMPS_INT> Jcorrect = {0, 0, 1, 1, 1, 2, 2, 2, 2, 3, 4, 4};
        vector<double> Xcorrect = {2, 3, 3, -1, 4, 4, -3, 1, 2, 2, 6, 1};

        CHECK(trip->symmetric == false);
        CHECK(equal_vectors(trip->I, Icorrect) == true);
        CHECK(equal_vectors(trip->J, Jcorrect) == true);
        CHECK(equal_vectors_tol(trip->X, Xcorrect, 1e-15) == true);
    }
}
