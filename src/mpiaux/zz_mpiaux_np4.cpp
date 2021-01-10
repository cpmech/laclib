#include "../util/doctest_mpi.h"
#include "../check/check.h"
#include "mpi.h"
#include "mpiaux.h"
#include <vector>
#include <iostream>
using namespace std;

MPI_TEST_CASE("mpiaux (world)", 4)
{
    auto mpi = MpiAux::make_new();

    SUBCASE("make_new")
    {
        CHECK(mpi.comm == MPI_COMM_WORLD);
        CHECK(mpi.size() == 4);
    }

    SUBCASE("reduce_sum")
    {
        auto orig = vector<double>{1000, 1000, 1000, 1000};
        orig[mpi.rank()] += double(mpi.rank());

        auto dest = vector<double>{0, 0, 0, 0};
        auto dest_correct_root = vector<double>{4000, 4001, 4002, 4003};
        auto dest_correct_others = vector<double>{0, 0, 0, 0};

        mpi.reduce_sum(dest, orig);

        if (mpi.rank() == 0)
        {
            CHECK(equal_vectors_tol(dest, dest_correct_root, 1e-15) == true);
        }
        else
        {
            CHECK(equal_vectors_tol(dest, dest_correct_others, 1e-15) == true);
        }
    }

    SUBCASE("broadcast_from_root")
    {
        vector<double> x;
        if (mpi.rank() == 0)
        {
            x = vector<double>{1111, 2222, 3333};
        }
        else
        {
            x = vector<double>{0, 0, 0};
        }
        mpi.broadcast_from_root(x);
        auto x_correct = vector<double>{1111, 2222, 3333};
        CHECK(equal_vectors_tol(x, x_correct, 1e-15));
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

    SUBCASE("reduce_sum")
    {
        if (mpi.belong())
        {
            auto orig = vector<double>{1000, 1000};
            orig[mpi.rank()] += double(mpi.rank());

            auto dest = vector<double>{0, 0};
            auto dest_correct_root = vector<double>{2000, 2001};
            auto dest_correct_others = vector<double>{0, 0};

            mpi.reduce_sum(dest, orig);

            if (mpi.rank() == 0)
            {
                CHECK(equal_vectors_tol(dest, dest_correct_root, 1e-15) == true);
            }
            else
            {
                CHECK(equal_vectors_tol(dest, dest_correct_others, 1e-15) == true);
            }
        }
    }

    SUBCASE("broadcast_from_root")
    {
        if (mpi.belong())
        {
            vector<double> x;
            if (mpi.rank() == 0)
            {
                x = vector<double>{1111, 2222, 3333};
            }
            else
            {
                x = vector<double>{0, 0, 0};
            }
            mpi.broadcast_from_root(x);
            auto x_correct = vector<double>{1111, 2222, 3333};
            CHECK(equal_vectors_tol(x, x_correct, 1e-15));
        }
    }
}
