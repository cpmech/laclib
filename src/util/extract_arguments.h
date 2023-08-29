#pragma once
#include <string>
#include <vector>

// extract_arguments returns all arguments (but not the name of the current exec program)
inline std::vector<std::string> extract_arguments(int argc, char **argv) {
    std::vector<std::string> fields;
    if (argc > 1) {
        fields.assign(argv + 1, argv + argc);
    }
    return fields;
}

inline std::string extract_first_argument(int argc, char **argv, std::string default_arg = "") {
    auto arguments = extract_arguments(argc, argv);
    if (arguments.size() > 0) {
        return arguments[0];
    }
    return default_arg;
}

inline std::vector<std::string> extract_arguments_or_use_defaults(int argc, char **argv, const std::vector<std::string> &defaults) {
    auto arguments = extract_arguments(argc, argv);
    std::vector<std::string> results(defaults.size(), "");
    for (size_t i = 0; i < defaults.size(); i++) {
        if (arguments.size() > i) {
            results[i] = arguments[i];
        } else {
            results[i] = defaults[i];
        }
    }
    return results;
}
