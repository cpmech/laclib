#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../util/doctest.h"
#include "../util/path_tools.h"
#include "read_lines.h"
#include <string>
using namespace std;

TEST_CASE("testing read_lines")
{
    auto data_path = path_get_current() + "/../../../data";
    auto filename = data_path + "/simple-text-file.txt";

    SUBCASE("read first line")
    {
        size_t first_index = 666;
        string first_line;

        read_lines(filename, [&first_index, &first_line](size_t index, const string &line) -> bool {
            if (first_index != 666 && first_index != 0)
            {
                throw "should have stopped by now";
            }
            first_index = index;
            first_line = line;
            return true; // stop
        });

        CHECK(first_index == 0);
        CHECK(first_line == "I'm nobody! Who are you?");
    }

    SUBCASE("exception: cannot open file")
    {
        auto handler = [](size_t index, const string &line) -> bool { return false; };
        CHECK_THROWS_WITH(read_lines("invalid.txt", handler), "read_lines: cannot open file");
    }

    SUBCASE("exception: handler throws char")
    {
        auto handler = [](size_t index, const string &line) -> bool {
            throw "cannot continue, sorry";
            return false;
        };
        CHECK_THROWS_WITH(read_lines(filename, handler), "cannot continue, sorry");
    }

    SUBCASE("exception: handler throws exception")
    {
        auto handler = [](size_t index, const string &line) -> bool {
            throw std::invalid_argument("just testing");
            return false;
        };
        CHECK_THROWS_WITH(read_lines(filename, handler), "just testing");
    }

    SUBCASE("exception: handler throws something else")
    {
        auto handler = [](size_t index, const string &line) -> bool {
            throw 666;
            return false;
        };
        CHECK_THROWS_WITH(read_lines(filename, handler), "read_lines: some error happened");
    }
}
