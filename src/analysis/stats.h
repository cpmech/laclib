#pragma once
#include <iomanip>
#include <memory>
#include <sstream>
#include <string>
#include <vector>

#include "../sparse/sparse_blas.h"
#include "../sparse/coo_matrix.h"
#include "../util/stopwatch.h"
#include "cblas_tools.h"

#define SNSEC(ns) format_nanoseconds(ns).c_str()

struct Stats {
    double max_abs_a;      // max abs value of a
    double max_abs_ax;     // max abs value of a*x
    double max_abs_diff;   // max abs value of diff = a*x - rhs
    double relative_error; // norm_inf_diff / (norm_inf_a + 1)
    uint64_t nanoseconds;  // time spent here

    inline static std::unique_ptr<Stats> make_new(const std::unique_ptr<SparseTriplet> &a,
                                                  const std::vector<double> &x,
                                                  const std::vector<double> &rhs) {
        auto sw = Stopwatch::make_new();
        auto max_abs_a = max_abs_value(a->values_aij);

        // compute ax := a*x
        auto m = a->dimension;
        std::vector<double> ax(m, 0.0);
        bool check_sizes = true;
        bool fill_zeros = false;
        sp_mat_vec_mul(ax, 1.0, a, x, check_sizes, fill_zeros);

        auto max_abs_ax = max_abs_value(ax);

        // compute diff := a*x - rhs
        daxpy(m, -1.0, rhs, ax); // ax := -rhs + ax => diff

        auto max_abs_diff = max_abs_value(ax);

        // compute relative error
        auto relative_error = max_abs_diff / (max_abs_a + 1.0);
        auto nanoseconds = sw.stop("");

        return std::unique_ptr<Stats>{new Stats{
            max_abs_a,
            max_abs_ax,
            max_abs_diff,
            relative_error,
            nanoseconds,
        }};
    }

    inline std::string json(const std::string &indent = "") {
        std::ostringstream oss;
        oss << std::setprecision(15);
        oss << "{\n";
        oss << indent << "  \"MaxAbsA\": " << this->max_abs_a << ",\n";
        oss << indent << "  \"MaxAbsAx\": " << this->max_abs_ax << ",\n";
        oss << indent << "  \"MaxAbsDiff\": " << this->max_abs_diff << ",\n";
        oss << indent << "  \"RelativeError\": " << this->relative_error << ",\n";
        oss << indent << "  \"ElapsedTimeNanoseconds\": " << this->nanoseconds << ",\n";
        oss << indent << "  \"ElapsedTimeString\": \"" << SNSEC(this->nanoseconds) << "\"\n";
        oss << indent << "}\n";
        return oss.str();
    }
};

#undef SNSEC
