#include <string>
#include <sstream>

const uint64_t NS_PER_NANOSECOND = 1;
const uint64_t NS_PER_MICROSECOND = 1000 * NS_PER_NANOSECOND;
const uint64_t NS_PER_MILLISECOND = 1000 * NS_PER_MICROSECOND;
const uint64_t NS_PER_SECOND = 1000 * NS_PER_MILLISECOND;
const uint64_t NS_PER_MINUTE = 60 * NS_PER_SECOND;
const uint64_t NS_PER_HOUR = 60 * NS_PER_MINUTE;

std::string nanoseconds_to_string(uint64_t nanoseconds)
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