#pragma once
#include <regex>
#include <string>
#include <sstream>
#include "constants.h"

const std::regex RGX_NO_ALPHA("\\D", std::regex_constants::ECMAScript);
const std::regex RGX_SEP_NUM("\\B(?=(\\d{3})+(?!\\d))", std::regex_constants::ECMAScript);

template <typename T>
inline std::string format_large_number(const T &num)
{
    auto tmp = std::regex_replace(std::to_string(num), RGX_NO_ALPHA, "");
    return std::regex_replace(tmp, RGX_SEP_NUM, ",");
}

//  Note:
//   The SI prefixes are for strict use with powers of 10, not powers of 2 as used by computers.
//   To solve this the International Electrotechnical Commission (IEC) came up with a new prefix
//   standard for powers of 2, known as binary prefixes. The solution was to add an "i" between
//   the initial letter and the "B". Full prefixes were also defined. As per the specification
//   of the prefixes, the power of 2 prefix counterpart to Kilo- is Kibi-. The prefix Kilo-
//   stands for 10^3 while Kibi- stands for 2^10. This means that a Kilobyte is 1000 bytes while
//   a Kibibyte is 1024 bytes. This might not seem like a big difference but when it gets to
//   Gigabytes versus Gibibytes the difference becomes much more noticeable
//   REFERENCE: https://blog.digilentinc.com/mib-vs-mb-whats-the-difference/

inline uint64_t bytes_to_KiB(uint64_t b)
{
    return b / 1024;
}

inline uint64_t bytes_to_MiB(uint64_t b)
{
    return b / 1024 / 1024;
}

inline uint64_t bytes_to_GiB(uint64_t b)
{
    return b / 1024 / 1024 / 1024;
}

inline std::string format_nanoseconds(uint64_t nanoseconds)
{
    if (nanoseconds == 0)
    {
        return "0ns";
    }

    std::ostringstream oss;

    // nanoseconds is smaller than a second => use small units such as 2.5ms
    if (nanoseconds < NS_PER_SECOND)
    {
        if (nanoseconds < NS_PER_MICROSECOND)
        {
            oss << nanoseconds << "ns";
        }
        else if (nanoseconds < NS_PER_MILLISECOND)
        {
            oss << double(nanoseconds) / double(NS_PER_MICROSECOND) << "µs";
        }
        else
        {
            oss << double(nanoseconds) / double(NS_PER_MILLISECOND) << "ms";
        }
    }

    // nanoseconds is greater than a second => use large units such as 3m2.5s
    else
    {
        if (nanoseconds >= NS_PER_HOUR)
        {
            auto hours = nanoseconds / NS_PER_HOUR;
            nanoseconds -= hours * NS_PER_HOUR;
            oss << hours << "h";
        }

        if (nanoseconds >= NS_PER_MINUTE)
        {
            auto minutes = nanoseconds / NS_PER_MINUTE;
            nanoseconds -= minutes * NS_PER_MINUTE;
            oss << minutes << "m";
        }

        if (nanoseconds > 0)
        {
            auto seconds = double(nanoseconds) / double(NS_PER_SECOND);
            oss << seconds << "s";
        }
    }

    return oss.str();
}
