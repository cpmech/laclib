#include <filesystem>

std::string get_current_path()
{
    return std::filesystem::current_path();
}
