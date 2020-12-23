#include "../util/doctest_mpi.h"
#include "mpi.h"
#include "mpiaux.h"
#include <vector>
using namespace std;

MPI_TEST_CASE("mpiaux with np=1", 1)
{
    SUBCASE("make_new")
    {
        auto ranks = vector<int>{};
        auto mpi = MpiAux::make_new(ranks);

        CHECK(mpi.comm == MPI_COMM_WORLD);
    }
}