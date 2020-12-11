#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "get_selfpath.h"

TEST_CASE("testing get_selfpath")
{
    CHECK(get_selfpath().size() > 4);
}
