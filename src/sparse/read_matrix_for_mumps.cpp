#include <fstream>
#include "read_matrix_for_mumps.h"
#include "../util/string_tools.h"
#include "../nist-mmio/index.h"

static inline ReadMatrixForMumpsResults _do_read(std::string filename)
{
    ReadMatrixForMumpsResults results;

    auto allocator = [&](int m, int n, int nnz) {
        results.trip = TripletForMumps::make_new(m, n, nnz);
        results.trip->I.resize(nnz);
        results.trip->J.resize(nnz);
        results.trip->X.resize(nnz);
    };

    auto setter = [&](int k, int ik_onebased, int jk_onebased, double xk) {
        results.trip->put_zero_based(ik_onebased - 1, jk_onebased - 1, xk);
    };

    results.symmetric = read_mtx(filename, allocator, setter);

    return results;
}

ReadMatrixForMumpsResults read_matrix_for_mumps(const std::string &filename, bool use_nist_mmio)
{
    if (use_nist_mmio)
    {
        return _do_read(filename);
    }

    std::ifstream myfile(filename);
    if (myfile.fail())
    {
        throw "read_matrix_for_mumps: cannot open file";
    }

    ReadMatrixForMumpsResults results;
    results.symmetric = false;

    bool initialized = false;
    size_t deltaIndex = 0;
    size_t id = 0;
    size_t sz = 1;
    size_t start = 0;
    size_t endp1 = 0;
    size_t indexNnz = 0;
    size_t m, n, nnz, i, j;
    double x;
    std::string line;

    while (std::getline(myfile, line))
    {
        // read header
        if (!initialized)
        {
            if (string_has_prefix(line, "%%MatrixMarket"))
            {
                auto info = string_fields(line);
                if (info.size() != 5)
                {
                    myfile.close();
                    throw "read_matrix_for_mumps: header starting with %%MatrixMarket is incorrect";
                }
                if (info[1] != "matrix")
                {
                    myfile.close();
                    throw "read_matrix_for_mumps: can only read \"matrix\" MatrixMarket at the moment";
                }
                if (info[2] != "coordinate")
                {
                    myfile.close();
                    throw "read_matrix_for_mumps: can only read \"coordinate\" MatrixMarket at the moment";
                }
                if (info[3] != "real")
                {
                    myfile.close();
                    throw "read_matrix_for_mumps: the given MatrixMarket file must have the word \"real\" in the header";
                }
                if (info[4] != "general" && info[4] != "symmetric")
                {
                    myfile.close();
                    throw "read_matrix_for_mumps: only works with \"general\" or \"symmetric\" MatrixMarket files";
                }
                if (info[4] == "symmetric")
                {
                    results.symmetric = true;
                }
                deltaIndex = 1;
                continue;
            }

            if (string_has_prefix(line, "%"))
            {
                continue;
            }

            auto r = string_fields(line);

            if (r.size() != 3)
            {
                myfile.close();
                throw "read_matrix_for_mumps: the number of columns in the line with dimensions must be 3 (m,n,nnz)";
            }

            try
            {
                m = std::stoi(r[0]);
                n = std::stoi(r[1]);
                nnz = std::stoi(r[2]);
            }
            catch (...)
            {
                throw "read_matrix_for_mumps: cannot parse m, n, or nnz values";
            }

            start = (id * nnz) / sz;
            endp1 = ((id + 1) * nnz) / sz;

            results.trip = TripletForMumps::make_new(m, n, endp1 - start);

            initialized = true;
        }

        // read values
        else
        {
            if (string_has_prefix(line, "%"))
            {
                continue;
            }

            auto r = string_fields(line);

            if (r.size() != 3)
            {
                myfile.close();
                throw "read_matrix_for_mumps: the number of columns in the data lines must be 3 (i,j,x)";
            }

            try
            {
                i = std::stoi(r[0]);
                j = std::stoi(r[1]);
                x = std::stod(r[2]);
            }
            catch (...)
            {
                throw "read_matrix_for_mumps: cannot parse i, j or x values";
            }

            if (indexNnz >= start && indexNnz < endp1)
            {
                results.trip->put_zero_based(i - deltaIndex, j - deltaIndex, x);
            }

            indexNnz++;
        }
    }

    myfile.close();

    return results;
}
