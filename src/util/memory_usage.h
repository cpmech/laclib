#pragma once
#include <sys/time.h>
#include <sys/resource.h>

// memory_usage returns the maximum resident set size used (in kilobytes)
long memory_usage()
{
    struct rusage usage;
    auto status = getrusage(RUSAGE_SELF, &usage);
    if (status != 0)
    {
        throw "memory_usage: getrusage failed";
    }
    return usage.ru_maxrss;
}