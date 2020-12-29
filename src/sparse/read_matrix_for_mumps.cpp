#include <fstream>
#include "read_matrix_for_mumps.h"
#include "../util/string_tools.h"

ReadMatrixForMumpsResults read_matrix_for_mumps(std::string filename)
{
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
                if (info[4] != "general" && info[4] != "symmetric" && info[4] != "unsymmetric")
                {
                    myfile.close();
                    throw "read_matrix_for_mumps: only works with \"general\", \"symmetric\" and \"unsymmetric\" MatrixMarket files";
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
