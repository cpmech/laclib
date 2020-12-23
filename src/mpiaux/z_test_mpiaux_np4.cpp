#include "../util/doctest_mpi.h"
#include "mpi.h"
#include "mpiaux.h"
#include <vector>
#include <iostream>
using namespace std;

MPI_TEST_CASE("mpiaux (world)", 4)
{
    auto ranks = vector<int>{};
    auto mpi = MpiAux::make_new(ranks);

    SUBCASE("make_new")
    {
        CHECK(mpi.comm == MPI_COMM_WORLD);
        CHECK(mpi.size() == 4);
    }
}

MPI_TEST_CASE("mpiaux (subgroup)", 4)
{
    auto ranks = vector<int>{1, 3};
    auto mpi = MpiAux::make_new(ranks);

    SUBCASE("make_new")
    {
        if (mpi.belong())
        {
            int rank = mpi.rank();
            CHECK((rank == 0 || rank == 1));
            CHECK(mpi.size() == 2);
        }
        else
        {
            CHECK(mpi.rank() == -1);
            CHECK(mpi.size() == -1);
            CHECK(mpi.comm == MPI_COMM_NULL);
        }
    }
}