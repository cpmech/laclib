#include <iostream>
#include <string>
#include <vector>

#include "extract_arguments.h"
using namespace std;

int main(int argc, char **argv) {
    auto args = extract_arguments(argc, argv);

    if (args.size() != 3) {
        cout << "ERROR: number of arguments is incorrect" << endl;
        return 1;
    }

    if (args[0] != "first") {
        cout << "ERROR: first argument must be \"first\"" << endl;
        return 1;
    }

    if (args[1] != "second") {
        cout << "ERROR: second argument must be \"second\"" << endl;
        return 1;
    }

    if (args[2] != "third") {
        cout << "ERROR: third argument must be \"third\"" << endl;
        return 1;
    }

    auto first_arg = extract_first_argument(argc, argv);

    if (first_arg != "first") {
        cout << "ERROR: 1st argument must be \"first\"" << endl;
        return 1;
    }

    vector<string> defaults{"1", "2", "3", "4"};
    auto res = extract_arguments_or_use_defaults(argc, argv, defaults);
    if (res.size() != 4) {
        cout << "ERROR: size of res is incorrect\n";
    }
    if (res[0] != "first") {
        cout << "ERROR: first res must be \"first\"" << endl;
    }
    if (res[1] != "second") {
        cout << "ERROR: second res must be \"second\"" << endl;
    }
    if (res[2] != "third") {
        cout << "ERROR: third res must be \"third\"" << endl;
    }
    if (res[3] != "4") {
        cout << "ERROR: fourth res must be \"4\"" << endl;
    }

    cout << "### OK ###" << endl;
    return 0;
}
