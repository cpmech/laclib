#pragma once
#include <memory>
#include <string>
#include <sstream>
#include <vector>
#include "../../src/laclib.h"

using namespace std;

struct Stats
{
    double norm_a;         // inf norm of a
    double norm_ax;        // inf norm of a*x
    double norm_diff;      // inf norm of diff = a*x - rhs
    double relative_error; // norm_diff / (norm_a + 1)

    inline static std::unique_ptr<Stats> make_new(MpiAux &mpi,
                                                  const std::unique_ptr<SparseTriplet> &a,
                                                  const std::vector<double> &x,
                                                  const std::vector<double> &rhs)
    {
        auto mpi_rank = mpi.rank();
        auto mpi_size = mpi.size();

        bool check_sizes = true;
        bool fill_zeros = false;

        auto m = a->m;
        double norm_a = 0;
        std::vector<double> ax(m, 0.0);

        if (mpi_size > 1)
        {
            std::vector<double> norms_a_loc(mpi_size, 0.0);
            std::vector<double> norms_a_all(mpi_size, 0.0);
            norms_a_loc[mpi_rank] = norm_inf(a->X);
            mpi.reduce_sum(norms_a_all, norms_a_loc);
            norm_a = norm_inf(norms_a_all);

            std::vector<double> ax_loc(m, 0.0);
            sp_matvecmul(ax_loc, 1.0, a, x, check_sizes, fill_zeros);
            mpi.reduce_sum(ax, ax_loc);
        }
        else
        {
            norm_a = norm_inf(a->X);

            sp_matvecmul(ax, 1.0, a, x, check_sizes, fill_zeros);
        }

        if (mpi_rank != 0)
        {
            return std::unique_ptr<Stats>{new Stats{0, 0, 0, 0}};
        }

        auto norm_ax = norm_inf(ax);

        daxpy(m, -1.0, rhs, 1, ax, 1); // ax := -rhs + ax => diff

        auto norm_diff = norm_inf(ax);

        auto relative_error = norm_diff / (norm_a + 1.0);

        return std::unique_ptr<Stats>{new Stats{
            norm_a,
            norm_ax,
            norm_diff,
            relative_error,
        }};
    }

    inline std::string json(const std::string &indent = "")
    {
        std::ostringstream oss;
        oss << "{\n";
        oss << indent << "  \"NormA\": " << this->norm_a << ",\n";
        oss << indent << "  \"NormAx\": " << this->norm_ax << ",\n";
        oss << indent << "  \"NormDiff\": " << this->norm_diff << ",\n";
        oss << indent << "  \"RelativeError\": " << this->relative_error << "\n";
        oss << indent << "}\n";
        return oss.str();
    }
};
