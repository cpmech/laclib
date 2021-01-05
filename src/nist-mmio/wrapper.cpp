#include <cstdio>
#include <string>
#include <sstream>
#include <iostream>
#include "wrapper.h"

extern "C"
{
#include "mmio.h"
}

using namespace std;

static inline std::string _error(const std::string &prefix, int status)
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

    return ss.str();
}

void hello(const std::string &filename)
{
    FILE *f = fopen(filename.c_str(), "r");

    if (f == NULL)
    {
        throw "could not open file";
    }

    MM_typecode matcode;

    int status = mm_read_banner(f, &matcode);

    if (status != 0)
    {
        fclose(f);
        throw _error("read_banner", status);
    }

    fclose(f);
}