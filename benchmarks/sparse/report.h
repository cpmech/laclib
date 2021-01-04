#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include "../../src/laclib.h"

#define SNSEC(ns) format_nanoseconds(ns).c_str()

enum StepName
{
    STEP_READ_MATRIX,
    STEP_INITIALIZE,
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
    // auxiliary
    const MpiAux &mpi;
    Stopwatch sw_step;
    Stopwatch sw_solver;

    // output data
    std::string matrix_name;
    std::string solver_kind;
    std::string ordering;
    size_t mpi_size;
    bool symmetric;
    size_t number_of_rows;
    size_t number_of_columns;
    size_t number_of_nonzeros;
    TimeAndMemory step_read_matrix;
    TimeAndMemory step_initialize;
    TimeAndMemory step_analyze;
    TimeAndMemory step_factorize;
    TimeAndMemory step_solve;
    uint64_t solver_nanoseconds;

    inline static Report make_new(const MpiAux &mpi)
    {
        return {
            mpi,
            Stopwatch::make_new(),
            Stopwatch::make_new(),
            "",
            "",
            "",
            0,
            false,
            0,
            0,
            0,
            {0, 0},
            {0, 0},
            {0, 0},
            {0, 0},
            {0, 0},
            0,
        };
    }

    template <typename T>
    inline void print(const std::string &fmt, T value)
    {
        // if (this->mpi.rank() == 0)
        {
            std::cout << fmt << value << std::endl;
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
        // bool verbose = this->mpi.rank() == 0;
        bool verbose = true;
        bool reset_stopwatch = true;
        auto nanoseconds = this->sw_step.stop(verbose ? "... " : "", reset_stopwatch);
        auto bytes = memory_usage();

        switch (step)
        {
        case STEP_READ_MATRIX:
            this->step_read_matrix = TimeAndMemory{nanoseconds, bytes};
            break;

        case STEP_INITIALIZE:
            this->step_initialize = TimeAndMemory{nanoseconds, bytes};
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

    inline void write_json(std::string fnkey)
    {
        auto str_symmetric = this->symmetric ? "true" : "false";
        std::ofstream ofs(fnkey + ".json", std::ofstream::out);
        ofs << "{\n";
        ofs << "  \"MatrixName\": \"%s\"," << this->matrix_name.c_str() << "\n";
        ofs << "  \"SolverKind\": \"%s\"," << this->solver_kind.c_str() << "\n";
        ofs << "  \"Ordering\": \"%s\"," << this->ordering.c_str() << "\n";
        ofs << "  \"MpiSize\": %zd," << this->mpi_size << "\n";
        ofs << "  \"Symmetric\": %s," << str_symmetric << "\n";
        ofs << "  \"NumberOfRows\": %z," << this->number_of_rows << "\n";
        ofs << "  \"NumberOfCols\": %z," << this->number_of_columns << "\n";
        ofs << "  \"NumberOfNonZeros\": %z," << this->number_of_nonzeros << "\n";
        ofs << "  \"StepReadMatrix\": {\n";
        ofs << "    \"ElapsedTimeNanoseconds\": %z," << this->step_read_matrix.nanoseconds << "\n";
        ofs << "    \"ElapsedTimeString\": \"%s\"," << SNSEC(this->step_read_matrix.nanoseconds) << "\n";
        ofs << "    \"MemoryBytes\": %z," << this->step_read_matrix.bytes << "\n";
        ofs << "    \"MemoryMiB\": %z" << bytes_to_MiB(this->step_read_matrix.bytes) << "\n";
        ofs << "  },\n";
        ofs << "  \"StepInitialize\": {\n";
        ofs << "    \"ElapsedTimeNanoseconds\": %z," << this->step_initialize.nanoseconds << "\n";
        ofs << "    \"ElapsedTimeString\": \"%s\"," << SNSEC(this->step_initialize.nanoseconds) << "\n";
        ofs << "    \"MemoryBytes\": %z," << this->step_initialize.bytes << "\n";
        ofs << "    \"MemoryMiB\": %z" << bytes_to_MiB(this->step_initialize.bytes) << "\n";
        ofs << "  },\n";
        ofs << "  \"StepFactorize\": {\n";
        ofs << "    \"ElapsedTimeNanoseconds\": %z," << this->step_factorize.nanoseconds << "\n";
        ofs << "    \"ElapsedTimeString\": \"%s\"," << SNSEC(this->step_factorize.nanoseconds) << "\n";
        ofs << "    \"MemoryBytes\": %z," << this->step_factorize.bytes << "\n";
        ofs << "    \"MemoryMiB\": %z" << bytes_to_MiB(this->step_factorize.bytes) << "\n";
        ofs << "  },\n";
        ofs << "  \"StepSolve\": {\n";
        ofs << "    \"ElapsedTimeNanoseconds\": %z," << this->step_solve.nanoseconds << "\n";
        ofs << "    \"ElapsedTimeString\": \"%s\"," << SNSEC(this->step_solve.nanoseconds) << "\n";
        ofs << "    \"MemoryBytes\": %z," << this->step_solve.bytes << "\n";
        ofs << "    \"MemoryMiB\": %z" << bytes_to_MiB(this->step_solve.bytes) << "\n";
        ofs << "  },\n";
        ofs << "  \"TimeSolverNanoseconds\": %z," << this->solver_nanoseconds << "\n";
        ofs << "  \"TimeSolverString\": \"%s\"" << SNSEC(this->solver_nanoseconds) << "\n";
        ofs << "}\n";
        ofs.close();
    }
};