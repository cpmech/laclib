#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "get_envar.h"

TEST_CASE("get_envar") {
    auto envar = get_envar("OMP_NUM_THREADS");
    CHECK(envar == "4");
}
