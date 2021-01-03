#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "formaters.h"

TEST_CASE("format_large_number")
{
    CHECK(format_large_number(12345678) == "12,345,678");
}

TEST_CASE("bytes conversion")
{
    CHECK(bytes_to_KiB(BYTES_PER_KIB) == 1);
    CHECK(bytes_to_MiB(BYTES_PER_MIB) == 1);
    CHECK(bytes_to_GiB(BYTES_PER_GIB) == 1);
    CHECK(bytes_to_GiB(BYTES_PER_TIB) == 1024);
    CHECK(bytes_to_GiB(BYTES_PER_PIB) == 1024 * 1024);
    CHECK(bytes_to_GiB(BYTES_PER_EIB) == 1024 * 1024 * 1024);
}

TEST_CASE("format_nanoseconds")
{
    SUBCASE("250 => 250ns")
    {
        auto res = format_nanoseconds(250);
        CHECK(res == "250ns");
    }

    SUBCASE("2500 (2.5e3) => 2.5µs")
    {
        auto res = format_nanoseconds(2500);
        CHECK(res == "2.5µs");
    }

    SUBCASE("25,000 (2.5e4) = 25µs")
    {
        auto res = format_nanoseconds(25000);
        CHECK(res == "25µs");
    }

    SUBCASE("250,000 (2.5e5) = 250µs")
    {
        auto res = format_nanoseconds(250000);
        CHECK(res == "250µs");
    }

    SUBCASE("2,500,000 (2.5e6) = 2.5ms")
    {
        auto res = format_nanoseconds(2500000);
        CHECK(res == "2.5ms");
    }

    SUBCASE("25,000,000 (2.5e7) = 25ms")
    {
        auto res = format_nanoseconds(25000000);
        CHECK(res == "25ms");
    }

    SUBCASE("250,000,000 (2.5e8) = 250ms")
    {
        auto res = format_nanoseconds(250000000);
        CHECK(res == "250ms");
    }

    SUBCASE("2,500,000,000 (2.5e9) = 2.5s")
    {
        auto res = format_nanoseconds(2500000000);
        CHECK(res == "2.5s");
    }

    SUBCASE("25,000,000,000 (2.5e10) = 25s")
    {
        auto res = format_nanoseconds(25000000000);
        CHECK(res == "25s");
    }

    SUBCASE("250,000,000,000 (2.5e11) = 250s = 4m10s")
    {
        auto res = format_nanoseconds(250000000000);
        CHECK(res == "4m10s");
    }

    SUBCASE("2,500,000,000,000 (2.5e12) = 2500s = 41m40s")
    {
        auto res = format_nanoseconds(2500000000000);
        CHECK(res == "41m40s");
    }

    SUBCASE("25,000,000,000,000 (2.5e13) = 25000s = 416m40s = 6h56m40s")
    {
        auto res = format_nanoseconds(25000000000000);
        CHECK(res == "6h56m40s");
    }

    SUBCASE("250,000,000,000,000 (2.5e14) = 250000s = 4166m40s = 69h26m40s")
    {
        auto res = format_nanoseconds(250000000000000);
        CHECK(res == "69h26m40s");
    }

    SUBCASE("60,000,000,000 (60e9, 6e10) = 1m")
    {
        auto res = format_nanoseconds(60000000000);
        CHECK(res == "1m");
    }

    SUBCASE("120,000,000,000 (120e9, 1.2e11) = 2m")
    {
        auto res = format_nanoseconds(120000000000);
        CHECK(res == "2m");
    }

    SUBCASE("3,600,000,000,000 (3.6e12) = 1h")
    {
        auto res = format_nanoseconds(3600000000000);
        CHECK(res == "1h");
    }

    SUBCASE("3,723,000,000,000 = 1h2m3s")
    {
        auto res = format_nanoseconds(3723000000000);
        CHECK(res == "1h2m3s");
    }
}
