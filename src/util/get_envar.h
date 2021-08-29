#pragma once
#include <cstdlib>
#include <string>

inline std::string get_envar(const std::string &envar_name) {
    auto envar = std::getenv(envar_name.c_str());
    if (envar == NULL) {
        return "";
    }
    return std::string(envar);
}
