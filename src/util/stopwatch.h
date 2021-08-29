#pragma once
#include <chrono>
#include <iostream>
#include <string>

#include "formaters.h"

struct Stopwatch {
    std::chrono::time_point<std::chrono::high_resolution_clock> initial_time;

    inline static Stopwatch make_new() {
        return {
            std::chrono::high_resolution_clock::now(),
        };
    };

    // returns the elased time in nanoseconds
    // INPUT:
    //   prefix != "" => will print to the terminal too
    //   do_reset => will reset initial time to the current time
    inline uint64_t stop(const std::string &prefix, bool do_reset = false) {
        auto end = std::chrono::high_resolution_clock::now();
        auto delta = std::chrono::duration_cast<std::chrono::nanoseconds>(end - this->initial_time);
        uint64_t nanoseconds = std::chrono::duration<uint64_t, std::nano>(delta).count();
        if (prefix != "") {
            auto str = format_nanoseconds(nanoseconds);
            std::cout << prefix << "elapsed time = " << str << std::endl;
        }
        if (do_reset) {
            this->reset();
        }
        return nanoseconds;
    }

    inline void reset() {
        this->initial_time = std::chrono::high_resolution_clock::now();
    }
};
