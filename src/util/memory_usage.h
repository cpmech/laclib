#pragma once
#include <fstream>
#include <unistd.h>

// memory_usage reads /proc/self/stat and returns the memory used (bytes) by this process
inline uint64_t memory_usage()
{
    // from `man proc`
    //
    //   /proc/[pid]/stat
    //     Status information about the process. This is used by ps(1). It is defined in
    //     the kernel source file fs/proc/array.c.
    //
    //   (23) vsize  %lu
    //        Virtual memory size in bytes.

    uint64_t vsize = 0;
    std::string _;
    std::ifstream ifs("/proc/self/stat", std::ios_base::in);
    //     1    2    3    4    5    6    7    8    9   10   11   12   13   14   15   16   17   18   19   20   21   22     23
    ifs >> _ >> _ >> _ >> _ >> _ >> _ >> _ >> _ >> _ >> _ >> _ >> _ >> _ >> _ >> _ >> _ >> _ >> _ >> _ >> _ >> _ >> _ >> vsize;
    ifs.close();
    return vsize;
}