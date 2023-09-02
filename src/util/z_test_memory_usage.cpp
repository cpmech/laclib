#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <iostream>

#include "../check/index.h"
#include "constants.h"
#include "doctest.h"
#include "formaters.h"
#include "memory_usage.h"
using namespace std;

#define F(num) format_large_number(num)

TEST_CASE("memory_usage") {
    // allocate 2 GiB
    void *ptr = malloc(2 * BYTES_PER_GIB);
    if (ptr == NULL) {
        throw "cannot allocate memory";
    }

    auto mem_bytes = memory_usage();
    auto mem_GiB = bytes_to_GiB(mem_bytes);

    free(ptr);

    cout << "mem = " << F(mem_bytes) << " bytes = " << mem_GiB << " GiB\n";

    CHECK(mem_GiB == 2);
}
