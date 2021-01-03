#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "constants.h"
#include "sleep.h"
#include "stopwatch.h"

TEST_CASE("stopwatch")
{
    auto sw_total = Stopwatch::make_new();
    auto sw = Stopwatch::make_new();

    sleep(333);

    auto et = sw.stop("A: ", true);
    CHECK((et / NS_PER_MILLISECOND) == 333);

    sleep(444);

    et = sw.stop("B: ");
    CHECK((et / NS_PER_MILLISECOND) == 444);

    auto total_et = sw_total.stop("C: ");
    CHECK((total_et / NS_PER_MILLISECOND) == 777);
}