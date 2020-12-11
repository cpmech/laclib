#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "string_tools.h"

TEST_CASE("testing string_tools")
{
    SUBCASE("string_has_prefix")
    {
        CHECK(string_has_prefix("this is a string", "this") == true);
        CHECK(string_has_prefix("this is a string", "this") == false);
    }

    SUBCASE("string_fields")
    {
        auto res = string_fields("these are the fields");
        CHECK(res.size() == 4);
    }
}
