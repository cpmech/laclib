#include <string>
#include <memory>
#include "triplet.h"

struct ReadMatrixResults
{
    std::unique_ptr<Triplet> T;
    bool symmetric;
};

ReadMatrixResults read_matrix(std::string filename, bool mirrorIfSym);
