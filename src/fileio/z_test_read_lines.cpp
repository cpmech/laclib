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

    size_t first_index = -1;
    string first_line;

    read_lines(filename, [&first_index, &first_line](size_t index, string line) -> bool {
        first_index = index;
        first_line = line;
        return true; // stop
    });

    CHECK(first_index == 0);
    CHECK(first_line == "I'm nobody! Who are you?");
}
