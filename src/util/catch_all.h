#pragma once
#include <iostream>

#define CATCH_ALL                                                    \
    catch (std::exception & e)                                       \
    {                                                                \
        std::cout << e.what() << std::endl;                          \
    }                                                                \
    catch (std::string & msg)                                        \
    {                                                                \
        std::cout << msg.c_str() << std::endl;                       \
    }                                                                \
    catch (const char *msg)                                          \
    {                                                                \
        std::cout << msg << std::endl;                               \
    }                                                                \
    catch (...)                                                      \
    {                                                                \
        std::cout << "some unknown exception happened" << std::endl; \
    }