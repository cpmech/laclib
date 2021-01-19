#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../util/doctest.h"
#include "../check/check.h"
#include "mpiaux.h"
#include <vector>
#include <iostream>
using namespace std;

TEST_CASE("mpiaux no_mpi")
{
    auto mpi = MpiAux::make_new();

    SUBCASE("make_new")
    {
        CHECK(mpi->comm == 0);
        CHECK(mpi->group == 0);
        CHECK(mpi->rank() == 0);
        CHECK(mpi->size() == 1);
        CHECK(mpi->belong() == true);
    }

    SUBCASE("reduce_sum")
    {
        auto orig = vector<double>{1000, 1000, 1000, 1000};
        auto dest = vector<double>{0, 0, 0, 0};
        auto dest_correct = vector<double>{1000, 1000, 1000, 1000};

        mpi->reduce_sum(dest, orig);
        CHECK(equal_vectors_tol(dest, dest_correct, 1e-15) == true);
    }

    SUBCASE("broadcast_from_root")
    {
        vector<double> x;
        x = vector<double>{1111, 2222, 3333};
        mpi->broadcast_from_root(x);
        auto x_correct = vector<double>{1111, 2222, 3333};
        CHECK(equal_vectors_tol(x, x_correct, 1e-15));
    }
}
