#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include "../../src/laclib.h"

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
    MpiAux &mpi;
    Stopwatch sw_step;
    Stopwatch sw_solver;
    TimeAndMemory step_read_matrix;
    TimeAndMemory step_analyze;
    TimeAndMemory step_factorize;
    TimeAndMemory step_solve;
    uint64_t solver_nanoseconds;

    inline static Report make_new(MpiAux &mpi)
    {
        return {
            mpi,
            Stopwatch::make_new(),
            Stopwatch::make_new(),
            {0, 0},
            {0, 0},
            {0, 0},
            {0, 0},
            0,
        };
    }

    template <typename T>
    inline void print(const std::string &prefix, const T &value)
    {
        bool verbose = this->mpi.rank() == 0;
        if (verbose)
        {
            std::cout << prefix << value << std::endl;
        }
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
        bool verbose = this->mpi.rank() == 0;
        std::string prefix = verbose ? "... " : "";
        bool reset_stopwatch = true;
        auto nanoseconds = this->sw_step.stop(prefix, reset_stopwatch);
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
                           const ReadMatrixForMumpsResults &data,
                           const MumpsOptions &options)
    {
        auto path = path_get_current() + "/../../../data/sparse-matrix/results/";
        auto ordering = mumps_ordering_to_string(options.ordering);
        auto mpi_size = this->mpi.size();

        std::stringstream fnkey;
        fnkey << solver_kind
              << "_" << matrix_name
              << "_" << ordering
              << "_np" << mpi_size << ".json";

        std::string filename = path + fnkey.str() + ".json";

        std::string str_symmetric = data.symmetric ? "true" : "false";

        std::ofstream ofs(filename, std::ofstream::out);
        ofs << "{\n";
        ofs << "  \"Platform\": \"laclib\",\n";
        ofs << "  \"SolverKind\": \"" << solver_kind << "\",\n";
        ofs << "  \"MatrixName\": \"" << matrix_name << "\",\n";
        ofs << "  \"Ordering\": \"" << ordering << "\",\n";
        ofs << "  \"MpiSize\": " << mpi_size << ",\n";
        ofs << "  \"Symmetric\": " << str_symmetric << ",\n";
        ofs << "  \"NumberOfRows\": " << data.trip->m << ",\n";
        ofs << "  \"NumberOfCols\": " << data.trip->n << ",\n";
        ofs << "  \"NumberOfNonZeros\": " << data.trip->pos << ",\n";
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
        ofs << "  \"TimeSolverString\": \"" << SNSEC(this->solver_nanoseconds) << "\"\n";
        ofs << "}\n";
        ofs.close();

        std::cout << "file <" << filename << "> written" << std::endl;
    }
};