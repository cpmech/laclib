#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "path_tools.h"

TEST_CASE("testing path_tools")
{
    SUBCASE("path_get_self_exe")
    {
        auto self_exe = path_get_self_exe();
        CHECK(self_exe.size() > 17);
        CHECK(self_exe.substr(self_exe.size() - 17) == "z_test_path_tools");
    }

    SUBCASE("path_get_current")
    {
        auto current_path = path_get_current();
        CHECK(current_path.size() > 14);
        CHECK(current_path.substr(current_path.size() - 14) == "build/src/util");
    }
}
