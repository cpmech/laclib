#pragma once
#ifdef HAS_MPI
#include "mpi.h"
#endif
#include <memory>
#include <vector>

struct MpiAux
{
#ifdef HAS_MPI
    MPI_Comm comm;
    MPI_Group group;
#else
    int comm;
    int group;
#endif

    // make_new creates a new subcommunicator based on the given world ranks
    // or simply returns the World Communicator and its group.
    // Input:
    //   ranks -- is a list of processors to make a subcommunicator
    //            if ranks.size == 0, will use the World Communicator
    inline static std::unique_ptr<MpiAux> make_new(const std::vector<int> &ranks)
    {
#ifdef HAS_MPI
        // reference:
        // https://mpitutorial.com/tutorials/introduction-to-groups-and-communicators/

        // grab world communicator and its group
        MPI_Comm world_comm = MPI_COMM_WORLD;
        MPI_Group world_group;
        MPI_Comm_group(world_comm, &world_group);

        // return world communicator
        if (ranks.size() == 0)
        {
            return std::unique_ptr<MpiAux>{new MpiAux{
                world_comm,
                world_group,
            }};
        }

        // create subgroup
        MPI_Group group;
        MPI_Group_incl(world_group, ranks.size(), ranks.data(), &group);

        // create subcommunicator
        MPI_Comm comm;
        MPI_Comm_create(world_comm, group, &comm);

        // results
        return std::unique_ptr<MpiAux>{new MpiAux{
            comm,
            group,
        }};
#else
        return std::unique_ptr<MpiAux>{new MpiAux{
            0,
            0,
        }};
#endif
    };

    // alternative constructor (use WORLD COMMUNICATOR)
    inline static std::unique_ptr<MpiAux> make_new()
    {
        return MpiAux::make_new(std::vector<int>{});
    }

    // clean-up
    ~MpiAux()
    {
#ifdef HAS_MPI
        if (this->comm != MPI_COMM_NULL && this->comm != MPI_COMM_WORLD)
        {
            MPI_Group_free(&this->group);
            MPI_Comm_free(&this->comm);
        }
#endif
    }

    // belong returns whether this processor belongs to group or not
    inline bool belong()
    {
#ifdef HAS_MPI
        return this->comm != MPI_COMM_NULL;
#else
        return true;
#endif
    }

    // returns the rank of this processor or -1 if it's outside the group
    inline int rank()
    {
#ifdef HAS_MPI
        if (this->comm == MPI_COMM_NULL)
        {
            return -1;
        }

        int rank;
        MPI_Comm_rank(this->comm, &rank);
        return static_cast<size_t>(rank);
#else
        return 0;
#endif
    }

    // returns the size of this group or -1 if it's outside the group
    inline int size()
    {
#ifdef HAS_MPI
        if (this->comm == MPI_COMM_NULL)
        {
            return -1;
        }

        int size;
        MPI_Comm_size(this->comm, &size);
        return static_cast<size_t>(size);
#else
        return 1;
#endif
    }

    // returns the Fortran communicator
    inline int get_fortran_comm()
    {
#ifdef HAS_MPI
        return MPI_Comm_c2f(this->comm);
#else
        return this->comm;
#endif
    }

    // reduce_sum combines orig from all processors into the processor with rank == 0
    // This function also sums the values at repeated locations.
    // NOTE: the smallest size between dest and orig is considered
    inline void reduce_sum(std::vector<double> &dest, const std::vector<double> &orig)
    {
#ifdef HAS_MPI
        size_t n = dest.size() < orig.size() ? dest.size() : orig.size();
        MPI_Reduce(orig.data(), dest.data(), n, MPI_DOUBLE, MPI_SUM, 0, this->comm);
#else
        dest = orig;
#endif
    }

    // broadcast_from_root broadcasts vector from root (Rank == 0) to all other processors
    inline void broadcast_from_root(std::vector<double> &x)
    {
#ifdef HAS_MPI
        MPI_Bcast(x.data(), x.size(), MPI_DOUBLE, 0, this->comm);
#endif
    }
};
