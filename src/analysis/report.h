#pragma once
#include <fstream>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>

#include "../util/memory_usage.h"
#include "../util/stopwatch.h"
#include "stats.h"

#define SNSEC(ns) format_nanoseconds(ns).c_str()
#define SMIB(bytes) format_large_number(bytes_to_MiB(bytes)).c_str()

enum StepName {
    STEP_READ_MATRIX,
    STEP_ANALYZE,
    STEP_FACTORIZE,
    STEP_SOLVE,
    STEP_CONVERSION,
};

struct TimeAndMemory {
    uint64_t nanoseconds;
    uint64_t bytes;
};

struct Report {
    Stopwatch sw_step;
    Stopwatch sw_solver;
    TimeAndMemory step_read_matrix;
    TimeAndMemory step_analyze;
    TimeAndMemory step_factorize;
    TimeAndMemory step_solve;
    TimeAndMemory step_conversion;
    uint64_t solver_nanoseconds;

    inline static std::unique_ptr<Report> make_new() {
        return std::unique_ptr<Report>{new Report{
            Stopwatch::make_new(),
            Stopwatch::make_new(),
            {0, 0},
            {0, 0},
            {0, 0},
            {0, 0},
            {0, 0},
            0,
        }};
    }

    inline void solver_start_stopwatch() {
        this->sw_solver.reset();
    }

    inline void solver_stop_stopwatch() {
        this->solver_nanoseconds = this->sw_solver.stop("");
    }

    inline void measure_step(StepName step) {
        bool reset_stopwatch = true;
        auto nanoseconds = this->sw_step.stop("", reset_stopwatch);
        auto bytes = memory_usage();

        switch (step) {
        case STEP_READ_MATRIX:
            this->step_read_matrix = TimeAndMemory{nanoseconds, bytes};
            break;

        case STEP_ANALYZE:
            this->step_analyze = TimeAndMemory{nanoseconds, bytes};
            break;

        case STEP_FACTORIZE:
            this->step_factorize = TimeAndMemory{nanoseconds, bytes};
            break;

        case STEP_SOLVE:
            this->step_solve = TimeAndMemory{nanoseconds, bytes};
            break;

        case STEP_CONVERSION:
            this->step_conversion = TimeAndMemory{nanoseconds, bytes};
            break;

        default:
            throw "Report::measure_now: StepName is invalid";
        }
    }

    inline void write_json(const std::string &output_dir,
                           const std::string &solver_kind,
                           const std::string &matrix_name,
                           const std::string &ordering,
                           int omp_num_threads,
                           const std::unique_ptr<CooMatrix> &coo,
                           const std::unique_ptr<Stats> &stats) {

        std::stringstream filename_key;
        filename_key << solver_kind
                     << "_" << matrix_name
                     << "_" << ordering
                     << "_omp" << std::to_string(omp_num_threads);

        std::string filepath = output_dir + "/" + filename_key.str() + ".json";

        std::string str_symmetric = is_symmetric(coo->layout) ? "true" : "false";

        std::ofstream ofs(filepath, std::ofstream::out);
        ofs << "{\n";
        ofs << "  \"Platform\": \"laclib\",\n";
        ofs << "  \"SolverKind\": \"" << solver_kind << "\",\n";
        ofs << "  \"MatrixName\": \"" << matrix_name << "\",\n";
        ofs << "  \"Ordering\": \"" << ordering << "\",\n";
        ofs << "  \"MpiSize\": " << 0 << ",\n";
        ofs << "  \"OmpNumThreads\": " << omp_num_threads << ",\n";
        ofs << "  \"Symmetric\": " << str_symmetric << ",\n";
        ofs << "  \"NumberOfRows\": " << coo->dimension << ",\n";
        ofs << "  \"NumberOfCols\": " << coo->dimension << ",\n";
        ofs << "  \"NumberOfNonZeros\": " << coo->pos << ",\n";
        ofs << "  \"StepReadMatrix\": {\n";
        ofs << "    \"ElapsedTimeNanoseconds\": " << this->step_read_matrix.nanoseconds << ",\n";
        ofs << "    \"ElapsedTimeString\": \"" << SNSEC(this->step_read_matrix.nanoseconds) << "\",\n";
        ofs << "    \"MemoryBytes\": " << this->step_read_matrix.bytes << ",\n";
        ofs << "    \"MemoryMiB\": \"" << SMIB(this->step_read_matrix.bytes) << "\"\n";
        ofs << "  },\n";
        ofs << "  \"StepConversion\": {\n";
        ofs << "    \"ElapsedTimeNanoseconds\": " << this->step_conversion.nanoseconds << ",\n";
        ofs << "    \"ElapsedTimeString\": \"" << SNSEC(this->step_conversion.nanoseconds) << "\",\n";
        ofs << "    \"MemoryBytes\": " << this->step_conversion.bytes << ",\n";
        ofs << "    \"MemoryMiB\": \"" << SMIB(this->step_conversion.bytes) << "\"\n";
        ofs << "  },\n";
        ofs << "  \"StepAnalyze\": {\n";
        ofs << "    \"ElapsedTimeNanoseconds\": " << this->step_analyze.nanoseconds << ",\n";
        ofs << "    \"ElapsedTimeString\": \"" << SNSEC(this->step_analyze.nanoseconds) << "\",\n";
        ofs << "    \"MemoryBytes\": " << this->step_analyze.bytes << ",\n";
        ofs << "    \"MemoryMiB\": \"" << SMIB(this->step_analyze.bytes) << "\"\n";
        ofs << "  },\n";
        ofs << "  \"StepFactorize\": {\n";
        ofs << "    \"ElapsedTimeNanoseconds\": " << this->step_factorize.nanoseconds << ",\n";
        ofs << "    \"ElapsedTimeString\": \"" << SNSEC(this->step_factorize.nanoseconds) << "\",\n";
        ofs << "    \"MemoryBytes\": " << this->step_factorize.bytes << ",\n";
        ofs << "    \"MemoryMiB\": \"" << SMIB(this->step_factorize.bytes) << "\"\n";
        ofs << "  },\n";
        ofs << "  \"StepSolve\": {\n";
        ofs << "    \"ElapsedTimeNanoseconds\": " << this->step_solve.nanoseconds << ",\n";
        ofs << "    \"ElapsedTimeString\": \"" << SNSEC(this->step_solve.nanoseconds) << "\",\n";
        ofs << "    \"MemoryBytes\": " << this->step_solve.bytes << ",\n";
        ofs << "    \"MemoryMiB\": \"" << SMIB(this->step_solve.bytes) << "\"\n";
        ofs << "  },\n";
        ofs << "  \"TimeSolverNanoseconds\": " << this->solver_nanoseconds << ",\n";
        ofs << "  \"TimeSolverString\": \"" << SNSEC(this->solver_nanoseconds) << "\",\n";
        ofs << "  \"Stats\": " << stats->json("  ");
        ofs << "}\n";
        ofs.close();
    }

    inline void write_json_conversion(const std::string &output_dir,
                                      const std::string &method,
                                      const std::string &matrix_name,
                                      int omp_num_threads,
                                      const std::unique_ptr<CooMatrix> &coo) {

        std::stringstream filename_key;
        filename_key << method
                     << "_" << matrix_name
                     << "_omp" << std::to_string(omp_num_threads);

        std::string filepath = output_dir + "/" + filename_key.str() + ".json";

        std::string str_symmetric = is_symmetric(coo->layout) ? "true" : "false";

        std::ofstream ofs(filepath, std::ofstream::out);
        ofs << "{\n";
        ofs << "  \"Platform\": \"laclib\",\n";
        ofs << "  \"Method\": \"" << method << "\",\n";
        ofs << "  \"MatrixName\": \"" << matrix_name << "\",\n";
        ofs << "  \"OmpNumThreads\": " << omp_num_threads << ",\n";
        ofs << "  \"Symmetric\": " << str_symmetric << ",\n";
        ofs << "  \"NumberOfRows\": " << coo->dimension << ",\n";
        ofs << "  \"NumberOfCols\": " << coo->dimension << ",\n";
        ofs << "  \"NumberOfNonZeros\": " << coo->pos << ",\n";
        ofs << "  \"StepReadMatrix\": {\n";
        ofs << "    \"ElapsedTimeNanoseconds\": " << this->step_read_matrix.nanoseconds << ",\n";
        ofs << "    \"ElapsedTimeString\": \"" << SNSEC(this->step_read_matrix.nanoseconds) << "\",\n";
        ofs << "    \"MemoryBytes\": " << this->step_read_matrix.bytes << ",\n";
        ofs << "    \"MemoryMiB\": \"" << SMIB(this->step_read_matrix.bytes) << "\"\n";
        ofs << "  },\n";
        ofs << "  \"StepConversion\": {\n";
        ofs << "    \"ElapsedTimeNanoseconds\": " << this->step_conversion.nanoseconds << ",\n";
        ofs << "    \"ElapsedTimeString\": \"" << SNSEC(this->step_conversion.nanoseconds) << "\",\n";
        ofs << "    \"MemoryBytes\": " << this->step_conversion.bytes << ",\n";
        ofs << "    \"MemoryMiB\": \"" << SMIB(this->step_conversion.bytes) << "\"\n";
        ofs << "  }\n";
        ofs << "}\n";
        ofs.close();
    }
};

#undef SNSEC
#undef SMIB
