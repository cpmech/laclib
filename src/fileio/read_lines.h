#pragma once
#include <fstream>
#include <functional>
#include <string>

// handlerType is a function that takes the index of the line and the line content
// and returns true to stop the execution.
//
//   Example:
//
//     auto handler = [](size_t index, const string &line) -> bool {
//         cout << line << endl;
//         return false; // continue
//     };
//
using handlerType = std::function<bool(size_t, const std::string &)>;

// read_lines opens a file for reading and loops over each line
//
//   Input:
//     filename -- is the relative or full path
//     handler -- is a function that takes the line number and the line content as string.
//                handler returns stop=true to stop reading, or stop=false to continue reading.
//
//   Example:
//
//     read_lines("myfile.txt", [](size_t index, string line) -> bool {
//         cout << line << endl;
//         return false; // continue
//     });
//
void read_lines(std::string filename, handlerType handler)
{
    std::ifstream myfile(filename);
    if (myfile.fail())
    {
        throw "read_lines: cannot open file";
    }

    size_t index = 0;
    std::string line;

    while (getline(myfile, line))
    {
        try
        {
            bool stop = handler(index, line);
            if (stop)
            {
                try
                {
                    myfile.close();
                }
                catch (...)
                {
                }
                break;
            }
        }
        catch (const char *m)
        {
            try
            {
                myfile.close();
            }
            catch (...)
            {
            }
            std::cout << m << std::endl;
            throw;
        }
        catch (std::exception &e)
        {
            try
            {
                myfile.close();
            }
            catch (...)
            {
            }
            std::cout << e.what() << std::endl;
            throw;
        }
        catch (...)
        {
            try
            {
                myfile.close();
            }
            catch (...)
            {
            }
            throw "read_lines: some error happened";
        }
        index++;
    }
}