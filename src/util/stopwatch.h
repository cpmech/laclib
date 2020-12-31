#pragma once
#include <chrono>
#include <string>
#include <iostream>
#include "nanoseconds_to_string.h"

struct Stopwatch
{
    std::chrono::time_point<std::chrono::high_resolution_clock> initial_time;

    inline static Stopwatch make_new()
    {
        return {
            std::chrono::high_resolution_clock::now(),
        };
    };

    // returns the elased time as string
    // INPUT:
    //   prefix != "" => will print to the terminal too
    //   do_reset => will reset initial time to the current time
    inline std::string stop(const std::string &prefix, bool do_reset = false)
    {
        auto end = std::chrono::high_resolution_clock::now();
        auto delta = std::chrono::duration_cast<std::chrono::nanoseconds>(end - this->initial_time);
        int64_t nanoseconds = std::chrono::duration<int64_t, std::nano>(delta).count();
        auto str = nanoseconds_to_string(nanoseconds);
        if (prefix != "")
        {
            std::cout << prefix << "elapsed time = " << str << std::endl;
        }
        if (do_reset)
        {
            this->reset();
        }
        return str;
    }

    inline void reset()
    {
        this->initial_time = std::chrono::high_resolution_clock::now();
    }
};