#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../util/doctest.h"
#include "../util/path_tools.h"
#include "../check/equal_vectors.h"
#include "read_matrix.h"
#include <vector>
using namespace std;

TEST_CASE("testing the return value from read_matrix")
{
    SUBCASE("cannot open file")
    {
        CHECK_THROWS_WITH(read_matrix("invalid.mtx", true), "read_matrix: cannot open file");
    }

    SUBCASE("small-sparse-matrix")
    {
        vector<size_t> Icorrect = {0, 1, 0, 2, 4, 1, 2, 3, 4, 2, 1, 4};
        vector<size_t> Jcorrect = {0, 0, 1, 1, 1, 2, 2, 2, 2, 3, 4, 4};
        vector<double> Xcorrect = {2, 3, 3, -1, 4, 4, -3, 1, 2, 2, 6, 1};

        auto data_path = path_get_current() + "/../../../data";
        auto mtx_path = data_path + "/small-sparse-matrix.mtx";
        auto mirrorIfSym = false;
        auto res = read_matrix(mtx_path, mirrorIfSym);

        CHECK(equal_vectors(res.T.get()->I, Icorrect) == true);
        CHECK(equal_vectors(res.T.get()->J, Jcorrect) == true);
        CHECK(equal_vectors_tol(res.T.get()->X, Xcorrect, 1e-15) == true);
    }
}
