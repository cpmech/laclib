#pragma once
#include <memory>
#include "dmumps_c.h"
#include "triplet_for_mumps.h"
#include "solver_mumps_constants.h"
#include "solver_mumps_options.h"
#include "solver_mumps_wrapper.h"

struct MumpsSolver
{
    DMUMPS_STRUC_C data;
    bool factorized;

    inline static std::unique_ptr<MumpsSolver> make_new(MumpsSymmetry symmetry)
    {
        DMUMPS_STRUC_C data;
        data.comm_fortran = MUMPS_USE_COMM_WORLD;
        data.par = 1; // host also works
        data.sym = symmetry;

        auto status = call_dmumps(&data, MUMPS_JOB_INITIALIZE, false);

        if (status != 0)
        {
            throw "MumpsSolver::make_new: MUMPS initialization failed";
        }

        auto solver = std::unique_ptr<MumpsSolver>{
            new MumpsSolver{
                data,
                false,
            }};

        return solver;
    };

    int analize_and_factorize(TripletForMumps *trip, const MumpsOptions &options, bool verbose);
    // void solve(double *x, double *rhs, bool rhs_is_distributed);
    int solve(std::vector<double> &input_rhs_output_x, bool iam_root_proc, bool verbose);
    void terminate();
};