# laclib - Linear Algebra C++17 Library

This project implements some structures and functions to assist in developing code for linear algebra computations using **modern C++17**. This project wraps some BLAS routines and solvers for sparse linear systems.

In this repository, the files starting with `zz_...` are **unit tests** whereas the files such as `zzi_...` are **integration tests** (those involving more than one single structure or function).

## Installation

### Install some dependencies

Execute:

```bash
sudo apt-get update -y \
&& sudo apt-get install -y --no-install-recommends \
  gcc \
  gfortran \
  libopenmpi-dev \
  liblapacke-dev \
  libopenblas-dev \
  libsuitesparse-dev
```
### Install the MUMPS Sparse Solver

Follow the procedures in https://github.com/cpmech/script-install-mumps

**NOTE**: we prefer to compile MUMPS ourselves instead of using the default Debian package named _libmumps-dev_ because the Debian package doesn't include some additional, and efficient, ordering tools.

### Compilation

Execute:

```bash
./all.bash
```

We could call _cmake_ directly as long as we'd set the CC and CXX environmental flags first (see the file `all.bash`).

## Examples

See the [examples](https://github.com/cpmech/laclib/tree/main/examples) directory.

### Solving a linear system with a sparse matrix

```c++
#include <iostream>
#include "../src/laclib.h"
using namespace std;

// NOTE: The code must be inside a sub-scope such as the "run"
//       function because the destructor of SolverMumps will call
//       dmumps to clean up memory. Also, the "run" function
//       assists in catching exceptions.

void run(int argc, char **argv)
{
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
    auto onebased = true;   // important for MUMPS (indices start at 1)
    auto symmetric = false; // the triplet doen't consider symmetry of A

    // input A matrix in triplet format
    auto trip = SparseTriplet::make_new(5, 5, 13, onebased, symmetric);
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
    auto mpi = MpiAux::make_new();
    auto solver = SolverMumps::make_new(mpi, symmetric);
    auto options = MumpsOptions::make_new();

    // analyse and factorize the matrix
    solver->analyze_and_factorize(trip, options);

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
    if (ok)
    {
        cout << "OK\n";
    }
    else
    {
        cout << "not OK\n";
    }
}

// NOTE: the main function will "always" be like this:
int main(int argc, char **argv)
{
    MPI_Init(&argc, &argv);
    try
    {
        run(argc, argv);
    }
    CATCH_ALL
    MPI_Finalize();
    return 0;
}

```

## Code organization

```
├── benchmarks  # tests for computational performance
├── data        # auxiliary data for unit tests
├── examples    # examples of usage
├── src         # this is the "main library"
│   ├── blas    # basic linear algebra tools
│   ├── check   # functions for unit/integration tests
│   ├── mpiaux  # convenient wrapper to MPI functions
│   ├── sparse  # sparse matrix and solvers tools
│   └── util    # some utilities for file/string manipulations
└── zscripts    # auxiliary "internal" bash scripts
```

The `src` directory contains all the _library_ code that you can use in your project. The `blas` and `sparse` _libraries_ may be the most useful for your project. The other directories mostly contain functions used here internally. For instance, the `check` directory contains functions to assist in the unit (and integration) tests and `util` includes some utility functions.  The `mpiaux` directory contains a convenient wrapper to MPI.
