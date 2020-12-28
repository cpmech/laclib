#pragma once
#include <string>
#include <vector>

// extract_arguments returns all arguments (but not the name of the currenct exec program)
inline std::vector<std::string> extract_arguments(int argc, char **argv)
{
    std::vector<std::string> fields;
    if (argc > 1)
    {
        fields.assign(argv + 1, argv + argc);
    }
    return fields;
}