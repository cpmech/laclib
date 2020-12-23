#pragma once
#include "mpi.h"
#include <vector>

struct MpiAux
{
    MPI_Comm comm;
    MPI_Group group;

    // make_new creates a new subcommunicator based on the given world ranks
    // or simply returns the World Communicator and its group.
    // Input:
    //   ranks -- is a list of processors to make a subcommunicator
    //            if ranks.size == 0, will use the World Communicator
    inline static MpiAux make_new(const std::vector<int> &ranks)
    {
        // grab world communicator and its group
        MPI_Comm world_comm = MPI_COMM_WORLD;
        MPI_Group world_group;
        MPI_Comm_group(world_comm, &world_group);

        // return world communicator
        if (ranks.size() == 0)
        {
            return {
                world_comm,
                world_group,
            };
        }

        // create subgroup
        MPI_Group group;
        MPI_Group_incl(world_group, ranks.size(), ranks.data(), &group);

        // create subcommunicator
        MPI_Comm comm;
        MPI_Comm_create(world_comm, group, &comm);

        // results
        return {
            comm,
            group,
        };
    };

    inline size_t rank()
    {
        int rank;
        MPI_Comm_rank(this->comm, &rank);
        return static_cast<size_t>(rank);
    }

    inline size_t size()
    {
        int size;
        MPI_Comm_size(this->comm, &size);
        return static_cast<size_t>(size);
    }

    inline void reduce_sum(std::vector<double> &dest, const std::vector<double> &orig)
    {
        MPI_Reduce(orig.data(), dest.data(), dest.size(), MPI_DOUBLE, MPI_SUM, 0, this->comm);
    }
};