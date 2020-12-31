#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "sleep.h"
#include "stopwatch.h"

TEST_CASE("stopwatch")
{
    auto sw_total = Stopwatch::make_new();
    auto sw = Stopwatch::make_new();

    sleep(333);

    auto str_et = sw.stop("A: ", true);
    CHECK(str_et.substr(0, 4) == "333.");
    CHECK(str_et.substr(str_et.size() - 2) == "ms");

    sleep(444);

    str_et = sw.stop("B: ");
    CHECK(str_et.substr(0, 4) == "444.");
    CHECK(str_et.substr(str_et.size() - 2) == "ms");

    auto str_total_et = sw_total.stop("C: ");
    CHECK(str_total_et.substr(0, 4) == "777.");
    CHECK(str_total_et.substr(str_total_et.size() - 2) == "ms");
}