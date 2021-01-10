#include <cstdio>
#include <cstring>
#include "read_matrix_market.h"
#include "../util/string_tools.h"

std::unique_ptr<SparseTriplet> read_matrix_market(const std::string &filename,
                                                  bool onebased,
                                                  int mpi_rank,
                                                  int mpi_size)
{
    FILE *f = fopen(filename.c_str(), "r");
    if (f == NULL)
    {
        throw "read_matrix_market: cannot open file";
    }

    // header
    // 12345678901234 123456 1234567890 1234567 123456789
    // %%MatrixMarket matrix coordinate complex symmetric
    // %%MatrixMarket matrix coordinate real    general
    // 12345678901234 123456 1234567890 1234    1234567

    const int LINE_MAX = 2048;
    char line[LINE_MAX];

    if (fgets(line, LINE_MAX, f) == NULL)
    {
        fclose(f);
        throw "read_matrix_market: cannot read any line in the file";
    }

    char mm[24], opt[24], fmt[24], kind[24], sym[24];
    int nread = sscanf(line, "%24s %24s %24s %24s %24s", mm, opt, fmt, kind, sym);
    if (nread != 5)
    {
        fclose(f);
        throw "read_matrix_market: number of tokens in the header is incorrect";
    }
    if (strncmp(mm, "%%MatrixMarket", 14) != 0)
    {
        fclose(f);
        throw "read_matrix_market: header must start with %%MatrixMarket";
    }
    if (strncmp(opt, "matrix", 6) != 0)
    {
        fclose(f);
        throw "read_matrix_market: option must be \"matrix\"";
    }
    if (strncmp(fmt, "coordinate", 10) != 0)
    {
        fclose(f);
        throw "read_matrix_market: type must be \"coordinate\"";
    }
    if (strncmp(kind, "real", 4) != 0)
    {
        fclose(f);
        throw "read_matrix_market: number kind must be \"real\"";
    }
    if (strncmp(sym, "general", 7) != 0 && strncmp(sym, "symmetric", 9) != 0)
    {
        fclose(f);
        throw "read_matrix_market: matrix must be \"general\" or \"symmetric\"";
    }

    std::unique_ptr<SparseTriplet> trip;
    bool symmetric = strncmp(sym, "symmetric", 9) == 0;

    bool initialized = false;
    size_t id = mpi_rank;
    size_t sz = mpi_size;
    size_t start = 0;
    size_t endp1 = 0;
    size_t indexNnz = 0;
    size_t m, n, nnz, i, j;
    double x;

    while (fgets(line, LINE_MAX, f) != NULL)
    {
        // dimensions
        if (!initialized)
        {
            if (line[0] == '%')
            {
                continue;
            }

            nread = sscanf(line, "%zu %zu %zu", &m, &n, &nnz);
            if (nread != 3)
            {
                fclose(f);
                throw "read_matrix_market: cannot parse the dimensions (m,n,nnz)";
            }

            start = (id * nnz) / sz;
            endp1 = ((id + 1) * nnz) / sz;
            trip = SparseTriplet::make_new(m, n, endp1 - start, onebased, symmetric);
            initialized = true;
        }

        // values
        else
        {
            nread = sscanf(line, "%zu %zu %lg", &i, &j, &x);
            if (nread != 3)
            {
                fclose(f);
                throw "read_matrix_market: cannot parse the values (i,j,x)";
            }

            if (indexNnz >= start && indexNnz < endp1)
            {
                trip->put(i - 1, j - 1, x);
            }

            indexNnz++;
        }
    }

    fclose(f);
    return trip;
}
