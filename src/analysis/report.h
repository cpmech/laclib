#pragma once
#include <fstream>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>

#include "../util/memory_usage.h"
#include "../util/path_tools.h"
#include "../util/stopwatch.h"
#include "stats.h"

#define SNSEC(ns) format_nanoseconds(ns).c_str()
#define SMIB(bytes) format_large_number(bytes_to_MiB(bytes)).c_str()

enum StepName {
    STEP_READ_MATRIX,
    STEP_ANALYZE,
    STEP_FACTORIZE,
    STEP_SOLVE,
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
    uint64_t solver_nanoseconds;

    inline static std::unique_ptr<Report> make_new() {
        return std::unique_ptr<Report>{new Report{
            Stopwatch::make_new(),
            Stopwatch::make_new(),
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

        default:
            throw "Report::measure_now: StepName is invalid";
        }
    }

    inline void write_json(const std::string &output_dir,
                           const std::string &solver_kind,
                           const std::string &matrix_name,
                           const std::string &ordering,
                           int omp_num_threads,
                           const std::unique_ptr<SparseTriplet> &trip,
                           const std::unique_ptr<Stats> &stats) {

        std::string suffix = "_open_seq";
        int effective_mpi_size = 0;
#ifdef HAS_OMP
        int effective_omp_num_threads = omp_num_threads;
        suffix += "_omp" + std::to_string(omp_num_threads);
#else
        int effective_omp_num_threads = 0;
#endif

        std::stringstream fnkey;
        fnkey << solver_kind
              << "_" << matrix_name
              << "_" << ordering
              << suffix;

        std::string filepath = output_dir + "/" + fnkey.str() + ".json";

        std::string str_symmetric = is_symmetric(trip->layout) ? "true" : "false";

        std::ofstream ofs(filepath, std::ofstream::out);
        ofs << "{\n";
        ofs << "  \"Platform\": \"laclib\",\n";
        ofs << "  \"SolverKind\": \"" << solver_kind << "\",\n";
        ofs << "  \"MatrixName\": \"" << matrix_name << "\",\n";
        ofs << "  \"Ordering\": \"" << ordering << "\",\n";
        ofs << "  \"MpiSize\": " << effective_mpi_size << ",\n";
        ofs << "  \"OmpNumThreads\": " << effective_omp_num_threads << ",\n";
        ofs << "  \"Symmetric\": " << str_symmetric << ",\n";
        ofs << "  \"NumberOfRows\": " << trip->dimension << ",\n";
        ofs << "  \"NumberOfCols\": " << trip->dimension << ",\n";
        ofs << "  \"NumberOfNonZeros\": " << trip->pos << ",\n";
        ofs << "  \"StepReadMatrix\": {\n";
        ofs << "    \"ElapsedTimeNanoseconds\": " << this->step_read_matrix.nanoseconds << ",\n";
        ofs << "    \"ElapsedTimeString\": \"" << SNSEC(this->step_read_matrix.nanoseconds) << "\",\n";
        ofs << "    \"MemoryBytes\": " << this->step_read_matrix.bytes << ",\n";
        ofs << "    \"MemoryMiB\": \"" << SMIB(this->step_read_matrix.bytes) << "\"\n";
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
};

#undef SNSEC
#undef SMIB
