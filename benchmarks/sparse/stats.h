#pragma once
#include <iomanip>
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

    inline static std::unique_ptr<Stats> make_new(const std::unique_ptr<SparseTriplet> &a,
                                                  const std::vector<double> &x,
                                                  const std::vector<double> &rhs,
                                                  bool distributed_matrix = false)
    {
        auto sw = Stopwatch::make_new();

        bool check_sizes = true;
        bool fill_zeros = false;

        auto m = a->m;
        double norm_inf_a = 0;
        std::vector<double> ax(m, 0.0);

        norm_inf_a = norm_inf(a->X);

        sp_matvecmul(ax, 1.0, a, x, check_sizes, fill_zeros);

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
        oss << std::setprecision(15);
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
