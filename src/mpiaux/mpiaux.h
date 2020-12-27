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
        // reference:
        // https://mpitutorial.com/tutorials/introduction-to-groups-and-communicators/

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

    // clean-up
    ~MpiAux()
    {
        if (this->comm != MPI_COMM_NULL && this->comm != MPI_COMM_WORLD)
        {
            MPI_Group_free(&this->group);
            MPI_Comm_free(&this->comm);
        }
    }

    // belong returns whether this processor belongs to group or not
    inline bool belong()
    {
        return this->comm != MPI_COMM_NULL;
    }

    // returns the rank of this processor or -1 if it's outside the group
    inline int rank()
    {
        if (this->comm == MPI_COMM_NULL)
        {
            return -1;
        }

        int rank;
        MPI_Comm_rank(this->comm, &rank);
        return static_cast<size_t>(rank);
    }

    // returns the size of this group or -1 if it's outside the group
    inline int size()
    {
        if (this->comm == MPI_COMM_NULL)
        {
            return -1;
        }

        int size;
        MPI_Comm_size(this->comm, &size);
        return static_cast<size_t>(size);
    }

    // reduce_sum combines orig from all processors into the processor with rank == 0
    // This function also sums the values at repeated locations.
    // NOTE: the smallest size between dest and orig is considered
    inline void reduce_sum(std::vector<double> &dest, const std::vector<double> &orig)
    {
        size_t n = dest.size() < orig.size() ? dest.size() : orig.size();
        MPI_Reduce(orig.data(), dest.data(), n, MPI_DOUBLE, MPI_SUM, 0, this->comm);
    }

    // broadcast_from_root broadcasts vector from root (Rank == 0) to all other processors
    inline void broadcast_from_root(std::vector<double> &x)
    {
        MPI_Bcast(x.data(), x.size(), MPI_DOUBLE, 0, this->comm);
    }
};