#include "read_matrix_market.h"

#include <cstdio>
#include <cstring>

std::unique_ptr<CooMatrix> read_matrix_market(const std::string &filename,
                                              SymmetricHandling symmetric_handling) {
    FILE *f = fopen(filename.c_str(), "r");
    if (f == NULL) {
        throw "read_matrix_market: cannot open file";
    }

    // header
    // 12345678901234 123456 1234567890 1234567 123456789
    // %%MatrixMarket matrix coordinate complex symmetric
    // %%MatrixMarket matrix coordinate real    general
    // 12345678901234 123456 1234567890 1234    1234567

    const int line_max = 2048;
    char line[line_max];

    if (fgets(line, line_max, f) == NULL) {
        fclose(f);
        throw "read_matrix_market: cannot read any line in the file";
    }

    char mm[24], opt[24], fmt[24], kind[24], sym[24];
    int nread = sscanf(line, "%24s %24s %24s %24s %24s", mm, opt, fmt, kind, sym);
    if (nread != 5) {
        fclose(f);
        throw "read_matrix_market: number of tokens in the header is incorrect";
    }
    if (strncmp(mm, "%%MatrixMarket", 14) != 0) {
        fclose(f);
        throw "read_matrix_market: header must start with %%MatrixMarket";
    }
    if (strncmp(opt, "matrix", 6) != 0) {
        fclose(f);
        throw "read_matrix_market: option must be \"matrix\"";
    }
    if (strncmp(fmt, "coordinate", 10) != 0) {
        fclose(f);
        throw "read_matrix_market: type must be \"coordinate\"";
    }
    if (strncmp(kind, "real", 4) != 0) {
        fclose(f);
        throw "read_matrix_market: number kind must be \"real\"";
    }
    if (strncmp(sym, "general", 7) != 0 && strncmp(sym, "symmetric", 9) != 0) {
        fclose(f);
        throw "read_matrix_market: matrix must be \"general\" or \"symmetric\"";
    }

    std::unique_ptr<CooMatrix> coo;
    bool symmetric = strncmp(sym, "symmetric", 9) == 0;

    StoredLayout layout = FULL_MATRIX;
    if (symmetric) {
        switch (symmetric_handling) {
        case LEAVE_AS_LOWER:
            layout = LOWER_TRIANGULAR;
            break;
        case SWAP_TO_UPPER:
            layout = UPPER_TRIANGULAR;
            break;
        case MAKE_IT_FULL:
            layout = FULL_MATRIX;
            break;
        default:
            throw "symmetric handling option is invalid";
        }
    }

    bool initialized = false;
    size_t m, n, nnz, i, j;
    double x;

    while (fgets(line, line_max, f) != NULL) {
        // dimensions
        if (!initialized) {
            if (line[0] == '%') {
                continue;
            }

            nread = sscanf(line, "%zu %zu %zu", &m, &n, &nnz);
            if (nread != 3) {
                fclose(f);
                throw "read_matrix_market: cannot parse the dimensions (m,n,nnz)";
            }

            auto max = nnz;
            if (symmetric && symmetric_handling == MAKE_IT_FULL) {
                max = 2 * nnz;
            }

            coo = CooMatrix::make_new(layout, m, max);
            initialized = true;
        }

        // values
        else {
            nread = sscanf(line, "%zu %zu %lg", &i, &j, &x);
            if (nread != 3) {
                fclose(f);
                throw "read_matrix_market: cannot parse the values (i,j,x)";
            }

            if (symmetric) {
                switch (symmetric_handling) {
                case LEAVE_AS_LOWER:
                    coo->put(i - 1, j - 1, x);
                    break;
                case SWAP_TO_UPPER:
                    coo->put(j - 1, i - 1, x);
                    break;
                case MAKE_IT_FULL:
                    coo->put(i - 1, j - 1, x);
                    if (i != j) {
                        coo->put(j - 1, i - 1, x);
                    }
                    break;
                default:
                    throw "symmetric handling option is invalid";
                }
            } else {
                coo->put(i - 1, j - 1, x);
            }
        }
    }

    fclose(f);
    return coo;
}
