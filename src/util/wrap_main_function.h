#pragma once

#include <iostream>

#define MAIN_FUNCTION(run_function)                                  \
    int main(int argc, char **argv) {                                \
        try {                                                        \
            run_function(argc, argv);                                \
            return 0;                                                \
        } catch (std::exception & e) {                               \
            std::cout << e.what() << std::endl;                      \
        } catch (std::string & msg) {                                \
            std::cout << msg.c_str() << std::endl;                   \
        } catch (const char *msg) {                                  \
            std::cout << msg << std::endl;                           \
        } catch (...) {                                              \
            std::cout << "CAUGHT AN UNKNOWN EXCEPTION" << std::endl; \
        }                                                            \
        return 1;                                                    \
    }
