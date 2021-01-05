#include <cstdio>
#include <string>
#include <sstream>
#include <iostream>
#include "wrapper.h"

extern "C"
{
#include "mmio.h"
}

static inline void _throw_status_error(FILE *f, const std::string &prefix, int status)
{
    std::stringstream ss;

    switch (status)
    {
    case MM_COULD_NOT_READ_FILE:
        ss << "ERROR (" << MM_COULD_NOT_READ_FILE << "): " << prefix << ": could not read file\n";
        break;

    case MM_PREMATURE_EOF:
        ss << "ERROR (" << MM_PREMATURE_EOF << "): " << prefix << ": premature EOF\n";
        break;

    case MM_NOT_MTX:
        ss << "ERROR (" << MM_NOT_MTX << "): " << prefix << ": not Matrix Market (MTX) file\n";
        break;

    case MM_NO_HEADER:
        ss << "ERROR (" << MM_NO_HEADER << "): " << prefix << ": missing header\n";
        break;

    case MM_UNSUPPORTED_TYPE:
        ss << "ERROR (" << MM_UNSUPPORTED_TYPE << "): " << prefix << ": unsupported type\n";
        break;

    case MM_LINE_TOO_LONG:
        ss << "ERROR (" << MM_LINE_TOO_LONG << "): " << prefix << ": line is too long\n";
        break;

    case MM_COULD_NOT_WRITE_FILE:
        ss << "ERROR (" << MM_COULD_NOT_WRITE_FILE << "): " << prefix << ": could not write file\n";
        break;

    default:
        ss << "ERROR (" << status << "): unknown error code\n";
    }

    fclose(f);
    throw ss.str().c_str();
}

static inline void _throw_typecode_error(FILE *f, char *matcode)
{
    std::stringstream ss;
    ss << "Market Market type = " << mm_typecode_to_str(matcode) << " is not supported";
    fclose(f);
    throw ss.str().c_str();
}

bool read_mtx(const std::string &filename,
              std::function<void(int m, int n, int nnz)> allocator,
              std::function<void(int k, int ik_onebased, int jk_onebased, double xk)> setter)
{
    // open file
    FILE *f = fopen(filename.c_str(), "r");
    if (f == NULL)
    {
        throw "could not open file";
    }

    // read banner
    MM_typecode matcode;
    int status = mm_read_banner(f, &matcode);
    if (status != 0)
    {
        _throw_status_error(f, "mm_read_banner", status);
    }

    // check types
    if (!(mm_is_real(matcode) && mm_is_matrix(matcode) && mm_is_sparse(matcode)))
    {
        _throw_typecode_error(f, matcode);
    }

    // read sizes
    int m, n, nnz;
    status = mm_read_mtx_crd_size(f, &m, &n, &nnz);
    if (status != 0)
    {
        _throw_status_error(f, "mm_read_mtx_crd_size", status);
    }

    // call allocator
    allocator(m, n, nnz);

    /* NOTE: when reading in doubles, ANSI C requires the use of the "l"  */
    /*   specifier as in "%lg", "%lf", "%le", otherwise errors will occur */
    /*  (ANSI C X3.159-1989, Sec. 4.9.6.2, p. 136 lines 13-15)            */

    // read data
    int ik, jk;
    double xk;
    for (int k = 0; k < nnz; k++)
    {
        fscanf(f, "%d %d %lg\n", &ik, &jk, &xk);
        setter(k, ik, jk, xk);
    }

    // close file
    fclose(f);

    // results
    return mm_is_symmetric(matcode);
}