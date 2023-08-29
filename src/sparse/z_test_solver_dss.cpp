#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <vector>

#include "../analysis/index.h"
#include "../check/check.h"
#include "../util/doctest.h"
#include "solver_dss.h"
#include "sparse_triplet.h"
using namespace std;

TEST_CASE("testing sparse solver Intel DSS") {
    set_num_threads(1);
}
