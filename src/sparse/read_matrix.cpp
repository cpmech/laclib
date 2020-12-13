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
    size_t m, n, nnz, i, j;
    double x;
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
                    myfile.close();
                    throw "read_matrix: header starting with %%MatrixMarket is incorrect";
                }
                if (info[1] != "matrix")
                {
                    myfile.close();
                    throw "read_matrix: can only read \"matrix\" MatrixMarket at the moment";
                }
                if (info[2] != "coordinate")
                {
                    myfile.close();
                    throw "read_matrix: can only read \"coordinate\" MatrixMarket at the moment";
                }
                if (info[3] != "real")
                {
                    myfile.close();
                    throw "read_matrix: the given MatrixMarket file must have the word \"real\" in the header";
                }
                if (info[4] != "general" && info[4] != "symmetric" && info[4] != "unsymmetric")
                {
                    myfile.close();
                    throw "read_matrix: only works with \"general\", \"symmetric\" and \"unsymmetric\" MatrixMarket files";
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
                throw "read_matrix: the number of columns in the line with dimensions must be 3 (m,n,nnz)";
            }

            try
            {
                m = stoi(r[0]);
                n = stoi(r[1]);
                nnz = stoi(r[2]);
            }
            catch (...)
            {
                throw "read_matrix: cannot parse m, n, or nnz values";
            }

            start = (id * nnz) / sz;
            endp1 = ((id + 1) * nnz) / sz;

            if (results.symmetric && mirrorIfSym)
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
                myfile.close();
                throw "read_matrix: the number of columns in the data lines must be 3 (i,j,x)";
            }

            try
            {
                i = stoi(r[0]);
                j = stoi(r[1]);
                x = stod(r[2]);
            }
            catch (...)
            {
                throw "read_matrix: cannot parse i, j or x values";
            }

            if (indexNnz >= start && indexNnz < endp1)
            {
                results.T->put(i - deltaIndex, j - deltaIndex, x);
                if (results.symmetric && mirrorIfSym && i != j)
                {
                    results.T->put(j - deltaIndex, i - deltaIndex, x);
                }
            }

            indexNnz++;
        }
    }

    myfile.close();

    return results;
}
