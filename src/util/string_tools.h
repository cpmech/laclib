#pragma once
#include <string>
#include <vector>
#include <sstream>
#include <iterator>

inline bool string_has_prefix(std::string line, std::string search_criterion)
{
    if (line.rfind(search_criterion, 0) == 0)
    {
        return true;
    }
    return false;
}

inline std::vector<std::string> string_fields(std::string line)
{
    std::istringstream iss(line);
    std::vector<std::string> res(std::istream_iterator<std::string>{iss},
                                 std::istream_iterator<std::string>());
    return res;
}
