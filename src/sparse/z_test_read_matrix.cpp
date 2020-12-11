#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../util/doctest.h"
#include "../util/path_tools.h"
#include "read_matrix.h"

TEST_CASE("testing the return value from read_matrix")
{
    // SUBCASE("cannot open file")
    // {
    //     CHECK_THROWS_WITH(read_matrix("data/small-sparse-matix.mtx", true), "read_matrix: cannot open file");
    // }

    SUBCASE("small-sparse-matrix")
    {
        auto data_path = path_get_current() + "/../../../data";
        auto mtx_path = data_path + "/small-sparse-matrix.mtx";
        read_matrix(mtx_path, true);
    }
}
