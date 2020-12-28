#include "extract_arguments.h"
#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    auto args = extract_arguments(argc, argv);

    if (args.size() != 3)
    {
        cout << "ERROR: number of arguments is incorrect" << endl;
        return 1;
    }

    if (args[0] != "first")
    {
        cout << "ERROR: first argument must be \"first\"" << endl;
        return 1;
    }

    if (args[1] != "second")
    {
        cout << "ERROR: second argument must be \"second\"" << endl;
        return 1;
    }

    if (args[2] != "third")
    {
        cout << "ERROR: third argument must be \"third\"" << endl;
        return 1;
    }

    cout << "### OK ###" << endl;
    return 0;
}