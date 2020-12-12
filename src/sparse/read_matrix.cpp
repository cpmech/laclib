#include <fstream>
#include "read_matrix.h"
#include "../util/string_tools.h"
using namespace std;

ReadMatrixResults read_matrix(string filename, bool mirrorIfSym)
{
    ifstream myfile(filename);
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
    string line;

    while (getline(myfile, line))
    {
        // read header
        if (!initialized)
        {
            if (string_has_prefix(line, "%%MatrixMarket"))
            {
                auto info = string_fields(line);
                if (info.size() != 5)
                {
                    throw "info header starting with %%MatrixMarket is incorrect";
                }
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

            if (string_has_prefix(line, "%"))
            {
                continue;
            }

            auto r = string_fields(line);

            if (r.size() != 3)
            {
                throw "the number of columns in the line with dimensions must be 3 (m,n,nnz)";
            }

            size_t m = stoi(r[0]);
            size_t n = stoi(r[1]);
            size_t nnz = stoi(r[2]);

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
                throw "the number of columns in the data lines must be 3 (i,j,x)";
            }

            size_t i = stoi(r[0]);
            size_t j = stoi(r[1]);
            size_t x = stoi(r[2]);

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
