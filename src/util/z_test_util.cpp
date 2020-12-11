#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "get_selfpath.h"
#include "get_current_path.h"

TEST_CASE("testing get_selfpath")
{
    CHECK(get_selfpath().size() > 4);
}

TEST_CASE("testing get_current_path")
{
    CHECK(get_current_path().size() > 4);
}
