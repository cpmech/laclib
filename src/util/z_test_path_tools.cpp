#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "path_tools.h"

TEST_CASE("testing path_tools")
{
    SUBCASE("path_get_self_exe")
    {
        CHECK(path_get_self_exe().size() > 4);
    }

    SUBCASE("path_get_current")
    {
        CHECK(path_get_current().size() > 4);
    }
}
