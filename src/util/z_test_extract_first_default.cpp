#include "extract_arguments.h"
#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    auto first_arg = extract_first_argument(argc, argv, "using-default");

    if (first_arg != "using-default")
    {
        cout << "ERROR: 1st argument must be \"using-default\"" << endl;
        return 1;
    }

    cout << "### OK ###" << endl;
    return 0;
}