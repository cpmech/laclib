#pragma once
#include <filesystem>
#include <string>
#include <unistd.h>
#include <limits.h>

inline std::string path_get_self_exe()
{
    char buff[PATH_MAX];
    ssize_t len = ::readlink("/proc/self/exe", buff, sizeof(buff) - 1);
    if (len != -1)
    {
        buff[len] = '\0';
        return std::string(buff);
    }
    throw "cannot read self/exe path";
}

inline std::string path_get_current()
{
    return std::filesystem::current_path();
}
