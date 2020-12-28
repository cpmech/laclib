#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "sleep.h"
#include "stopwatch.h"

TEST_CASE("stopwatch")
{
    auto sw = Stopwatch::make_new();

    sleep(333);

    auto str_et = sw.stop("A: ");
    CHECK(str_et.substr(0, 5) == "0.333");
    CHECK(str_et.back() == 's');

    sw.reset();

    sleep(444);

    str_et = sw.stop("B: ");
    CHECK(str_et.substr(0, 5) == "0.444");
    CHECK(str_et.back() == 's');
}