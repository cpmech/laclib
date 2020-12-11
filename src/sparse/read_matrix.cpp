#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include "read_matrix.h"

bool has_prefix(std::string line, std::string search_criterion)
{
    if (line.rfind(search_criterion, 0) == 0)
    {
        return true;
    }
    return false;
}

std::vector<std::string> fields(std::string line)
{
    std::istringstream iss(line);
    std::vector<std::string> res(std::istream_iterator<std::string>{iss},
                                 std::istream_iterator<std::string>());
    return res;
}

ReadMatrixResults read_matrix(std::string filename, bool mirrorIfSym)
{
    std::ifstream myfile(filename);
    if (myfile.fail())
    {
        throw "read_matrix: cannot open file";
    }

    ReadMatrixResults results;

    bool initialized = false;
    size_t deltaIndex = 0;
    size_t id = 0;
    size_t sz = 1;
    size_t start = 0;
    size_t endp1 = 0;
    size_t indexNnz = 0;

    std::string line;
    while (getline(myfile, line))
    {
        if (has_prefix(line, "%%MatrixMarket"))
        {
            auto info = fields(line);
            if (info[1] != "matrix")
            {
                throw "can only read \"matrix\" MatrixMarket at the moment";
            }
            if (info[2] != "coordinate")
            {
                throw "can only read \"coordinate\" MatrixMarket at the moment";
            }
            if (info[3] != "real")
            {
                throw "the given MatrixMarket file must have the word \"real\" in the header";
            }
            if (info[4] != "general" && info[4] != "symmetric" && info[4] != "unsymmetric")
            {
                throw "this function only works with \"general\", \"symmetric\" and \"unsymmetric\" MatrixMarket files";
            }
            if (info[4] == "symmetric")
            {
                results.symmetric = true;
            }
            deltaIndex = 1;
            continue;
        }

        if (has_prefix(line, "%"))
        {
            continue;
        }

        auto r = fields(line);

        if (!initialized)
        {
            if (r.size() != 3)
            {
                throw "the number of columns in the line with dimensions must be 3 (m,n,nnz)";
            }
            size_t m = std::stoi(r[0]);
            size_t n = std::stoi(r[1]);
            size_t nnz = std::stoi(r[2]);
            start = (id * nnz) / sz;
            endp1 = ((id + 1) * nnz) / sz;
            if (results.symmetric)
            {
                results.T = triplet_new(m, n, (endp1 - start) * 2); // assuming that the diagonal is all-zeros (for safety)
            }
            else
            {
                results.T = triplet_new(m, n, endp1 - start);
            }
            initialized = true;
        }
        else
        {
            if (r.size() != 3)
            {
                throw "the number of columns in the data lines must be 3 (i,j,x)";
            }
            size_t i = std::stoi(r[0]);
            size_t j = std::stoi(r[1]);
            size_t x = std::stoi(r[2]);
            if (indexNnz >= start && indexNnz < endp1)
            {
                triplet_put(results.T.get(), i - deltaIndex, j - deltaIndex, x);
                if (results.symmetric && mirrorIfSym && i != j)
                {
                    triplet_put(results.T.get(), j - deltaIndex, i - deltaIndex, x);
                }
            }
            indexNnz++;
        }
    }

    myfile.close();

    return results;
}
