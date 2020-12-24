#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../check/check.h"
#include "string_tools.h"
#include <vector>
#include <string>
using namespace std;

TEST_CASE("testing string_tools")
{
    SUBCASE("string_has_prefix")
    {
        CHECK(string_has_prefix("this is a string", "this") == true);
        CHECK(string_has_prefix("this is a string", "nada") == false);
        CHECK(string_has_prefix("this is a string", "") == true);
    }

    SUBCASE("string_fields")
    {
        auto res = string_fields("these are the fields");
        vector<string> correct{"these", "are", "the", "fields"};
        CHECK(res.size() == 4);
        CHECK(equal_vectors(res, correct) == true);
    }
}
