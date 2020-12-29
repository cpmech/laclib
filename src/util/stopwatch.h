#pragma once
#include <chrono>
#include <string>
#include <iostream>
#include <sstream>

struct Stopwatch
{
    std::chrono::steady_clock::time_point initial_time;

    inline static Stopwatch make_new()
    {
        return {
            std::chrono::steady_clock::now(),
        };
    };

    // returns the elased time as string
    inline std::string stop(const std::string &prefix, bool do_reset = false)
    {
        auto end = std::chrono::steady_clock::now();
        std::chrono::duration<double> elapsed_seconds = end - this->initial_time;
        std::ostringstream oss;
        oss << elapsed_seconds.count() << "s";
        if (prefix != "")
        {
            std::cout << prefix << "elapsed time = " << oss.str() << std::endl;
        }
        if (do_reset)
        {
            this->reset();
        }
        return oss.str();
    }

    inline void reset()
    {
        this->initial_time = std::chrono::steady_clock::now();
    }
};