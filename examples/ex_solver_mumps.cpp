#include "../src/laclib.h"
#include <iostream>
using namespace std;

// NOTE: The code must be inside a sub-scope such as the "run"
//       function because the destructor of SolverMumps will call
//       dmumps to clean up memory. Also, the "run" function
//       assists in catching exceptions.

void run(int argc, char **argv) {
    // Solving:
    //            A              x         b
    //   [  2  3  0  0  0  ]   [ x0 ]   [  8 ]
    //   [  3  0  4  0  6  ]   [ x1 ]   [ 45 ]
    //   [  0 -1 -3  2  0  ] ⋅ [ x2 ] = [ -3 ]
    //   [  0  0  1  0  0  ]   [ x3 ]   [  3 ]
    //   [  0  4  2  0  1  ]   [ x4 ]   [ 19 ]
    //
    // where A is stored as a "triplet" of indices and values
    //
    // NOTE: the triplet may contain entries with duplicated indices
    //
    // The solution is: x = {1, 2, 3, 4, 5}

    // constants
    auto one_based = true;  // important for MUMPS (indices start at 1)
    auto symmetric = false; // the triplet doesn't consider symmetry of A

    // input A matrix in triplet format
    auto trip = SparseTriplet::make_new(5, 5, 13, one_based, symmetric);
    trip->put(0, 0, +1.0); // << duplicated (no problem)
    trip->put(0, 0, +1.0); // << duplicated
    trip->put(1, 0, +3.0);
    trip->put(0, 1, +3.0);
    trip->put(2, 1, -1.0);
    trip->put(4, 1, +4.0);
    trip->put(1, 2, +4.0);
    trip->put(2, 2, -3.0);
    trip->put(3, 2, +1.0);
    trip->put(4, 2, +2.0);
    trip->put(2, 3, +2.0);
    trip->put(1, 4, +6.0);
    trip->put(4, 4, +1.0);

    // allocate MUMPS solver and options
    auto options = MumpsOptions::make_new(symmetric);
    auto solver = SolverMumps::make_new(options);

    // analyze and factorize the matrix
    solver->analyze_and_factorize(trip);

    // allocate some vectors
    auto b = vector<double>{8.0, 45.0, -3.0, 3.0, 19.0};
    auto x = vector<double>{0, 0, 0, 0, 0};
    auto x_correct = vector<double>{1, 2, 3, 4, 5};

    // solve linear system
    solver->solve(x, b);

    // print the solution
    print_vector("x = A⁻¹ ⋅ b", x);

    // check the solution
    auto ok = equal_vectors_tol(x, x_correct, 1e-14);
    if (ok) {
        cout << "OK\n";
    } else {
        cout << "not OK\n";
    }
}

// NOTE: the main function will "always" be like this:
int main(int argc, char **argv) {
    try {
        run(argc, argv);
    }
    CATCH_ALL
    return 0;
}
