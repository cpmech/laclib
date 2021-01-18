#pragma once
#include <fstream>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include "../../src/laclib.h"
#include "stats.h"

#define SNSEC(ns) format_nanoseconds(ns).c_str()
#define SMIB(bytes) format_large_number(bytes_to_MiB(bytes)).c_str()

enum StepName
{
    STEP_READ_MATRIX,
    STEP_ANALYZE,
    STEP_FACTORIZE,
    STEP_SOLVE,
};

struct TimeAndMemory
{
    uint64_t nanoseconds;
    uint64_t bytes;
};

struct Report
{
    const std::unique_ptr<MpiAux> &mpi;
    Stopwatch sw_step;
    Stopwatch sw_solver;
    TimeAndMemory step_read_matrix;
    TimeAndMemory step_analyze;
    TimeAndMemory step_factorize;
    TimeAndMemory step_solve;
    uint64_t solver_nanoseconds;

    inline static std::unique_ptr<Report> make_new(const std::unique_ptr<MpiAux> &mpi)
    {
        return std::unique_ptr<Report>{new Report{
            mpi,
            Stopwatch::make_new(),
            Stopwatch::make_new(),
            {0, 0},
            {0, 0},
            {0, 0},
            {0, 0},
            0,
        }};
    }

    inline void solver_start_stopwatch()
    {
        this->sw_solver.reset();
    }

    inline void solver_stop_stopwatch()
    {
        this->solver_nanoseconds = this->sw_solver.stop("");
    }

    inline void measure_step(StepName step)
    {
        bool reset_stopwatch = true;
        auto nanoseconds = this->sw_step.stop("", reset_stopwatch);
        auto bytes = memory_usage();

        switch (step)
        {
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

    inline void write_json(const std::string &solver_kind,
                           const std::string &matrix_name,
                           const std::unique_ptr<MumpsOptions> &options,
                           const std::unique_ptr<SparseTriplet> &trip,
                           const std::unique_ptr<Stats> &stats,
                           bool ignore_omp)
    {
        auto mpi_rank = this->mpi->rank();
        auto mpi_size = this->mpi->size();
        if (mpi_rank != 0)
        {
            return;
        }

        auto path = path_get_current() + "/../../../benchmarks/sparse/results/";
        auto ordering = mumps_ordering_to_string(options->ordering);

#ifdef USE_INTEL
        std::string pfx = "intel_";
#else
        std::string pfx = "";
#endif

        std::string sfx = "";
        auto omp_num_threads = options->omp_num_threads;
        if (ignore_omp)
        {
            omp_num_threads = 0;
            sfx = "_mpi" + std::to_string(mpi_size);
        }
        else
        {
            sfx = "_omp" + std::to_string(options->omp_num_threads);
        }

        std::stringstream fnkey;
        fnkey << pfx << solver_kind
              << "_" << matrix_name
              << "_" << ordering
              << sfx;

        std::string filename = path + fnkey.str() + ".json";

        std::string str_symmetric = trip->symmetric ? "true" : "false";

        std::ofstream ofs(filename, std::ofstream::out);
        ofs << "{\n";
        ofs << "  \"Platform\": \"laclib\",\n";
        ofs << "  \"SolverKind\": \"" << solver_kind << "\",\n";
        ofs << "  \"MatrixName\": \"" << matrix_name << "\",\n";
        ofs << "  \"Ordering\": \"" << ordering << "\",\n";
        ofs << "  \"MpiSize\": " << mpi_size << ",\n";
        ofs << "  \"OmpNumThreads\": " << omp_num_threads << ",\n";
        ofs << "  \"Symmetric\": " << str_symmetric << ",\n";
        ofs << "  \"NumberOfRows\": " << trip->m << ",\n";
        ofs << "  \"NumberOfCols\": " << trip->n << ",\n";
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
