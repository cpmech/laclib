#pragma once
#include <memory>
#include <string>
#include <sstream>
#include <vector>
#include "../../src/laclib.h"

#define SNSEC(ns) format_nanoseconds(ns).c_str()

struct Stats
{
    double norm_inf_a;     // inf norm of a
    double norm_inf_ax;    // inf norm of a*x
    double norm_inf_diff;  // inf norm of diff = a*x - rhs
    double relative_error; // norm_inf_diff / (norm_inf_a + 1)
    uint64_t nanoseconds;  // time spent here

    inline static std::unique_ptr<Stats> make_new(MpiAux &mpi,
                                                  const std::unique_ptr<SparseTriplet> &a,
                                                  const std::vector<double> &x,
                                                  const std::vector<double> &rhs)
    {
        auto sw = Stopwatch::make_new();
        auto mpi_rank = mpi.rank();
        auto mpi_size = mpi.size();

        bool check_sizes = true;
        bool fill_zeros = false;

        auto m = a->m;
        double norm_inf_a = 0;
        std::vector<double> ax(m, 0.0);

        if (mpi_size > 1)
        {
            std::vector<double> norms_a_loc(mpi_size, 0.0);
            std::vector<double> norms_a_all(mpi_size, 0.0);
            norms_a_loc[mpi_rank] = norm_inf(a->X);
            mpi.reduce_sum(norms_a_all, norms_a_loc);
            norm_inf_a = norm_inf(norms_a_all);

            std::vector<double> ax_loc(m, 0.0);
            sp_matvecmul(ax_loc, 1.0, a, x, check_sizes, fill_zeros);
            mpi.reduce_sum(ax, ax_loc);
        }
        else
        {
            norm_inf_a = norm_inf(a->X);

            sp_matvecmul(ax, 1.0, a, x, check_sizes, fill_zeros);
        }

        if (mpi_rank != 0)
        {
            return std::unique_ptr<Stats>{new Stats{0, 0, 0, 0, 0}};
        }

        auto norm_inf_ax = norm_inf(ax);

        daxpy(m, -1.0, rhs, 1, ax, 1); // ax := -rhs + ax => diff

        auto norm_inf_diff = norm_inf(ax);
        auto relative_error = norm_inf_diff / (norm_inf_a + 1.0);
        auto nanoseconds = sw.stop("");

        return std::unique_ptr<Stats>{new Stats{
            norm_inf_a,
            norm_inf_ax,
            norm_inf_diff,
            relative_error,
            nanoseconds,
        }};
    }

    inline std::string json(const std::string &indent = "")
    {
        std::ostringstream oss;
        oss << "{\n";
        oss << indent << "  \"NormInfA\": " << this->norm_inf_a << ",\n";
        oss << indent << "  \"NormInfAx\": " << this->norm_inf_ax << ",\n";
        oss << indent << "  \"NormInfDiff\": " << this->norm_inf_diff << ",\n";
        oss << indent << "  \"RelativeError\": " << this->relative_error << ",\n";
        oss << indent << "  \"ElapsedTimeNanoseconds\": " << this->nanoseconds << ",\n";
        oss << indent << "  \"ElapsedTimeString\": \"" << SNSEC(this->nanoseconds) << "\"\n";
        oss << indent << "}\n";
        return oss.str();
    }
};

#undef SNSEC
