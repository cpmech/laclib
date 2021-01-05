#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../util/doctest.h"
#include "../util/path_tools.h"
#include "wrapper.h"
using namespace std;

TEST_CASE("testing NIST-MMIO")
{
    auto data_path = path_get_current() + "/../../../data/sparse-matrix/";

    SUBCASE("read sparse-matrix ok1")
    {
        auto mtx = data_path + "ok1.mtx";
        hello(mtx);
    }
}