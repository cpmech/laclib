#pragma once
#include <string>
#include <fstream>
#include "../../src/laclib.h"
#define SNSEC(ns) nanoseconds_to_string(ns).c_str()

inline uint64_t bytes_to_MiB(uint64_t b)
{
    return b / 1024 / 1024;
}

struct TimeAndMemory
{
    uint64_t nanoseconds;
    uint64_t bytes;
};

struct Report
{
    std::string solver_kind;
    std::string ordering;
    size_t mpi_size;
    bool symmetric;
    size_t number_of_rows;
    size_t number_of_columns;
    size_t number_of_nonzeros;
    TimeAndMemory step_read_matrix;
    TimeAndMemory step_initialize;
    TimeAndMemory step_factorize;
    TimeAndMemory step_solve;
    uint64_t solver_nanoseconds;

    inline void write_json(std::string fnkey)
    {
        auto ssym = this->symmetric ? "true" : "false";
        std::ofstream ofs(fnkey + ".json", std::ofstream::out);
        ofs << "{\n";
        ofs << "  \"SolverKind\": \"%s\"," << this->solver_kind.c_str() << "\n";
        ofs << "  \"Ordering\": \"%s\"," << this->ordering.c_str() << "\n";
        ofs << "  \"MpiSize\": %zd," << this->mpi_size << "\n";
        ofs << "  \"Symmetric\": %s," << ssym << "\n";
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