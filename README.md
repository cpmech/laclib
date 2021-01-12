# laclib - Linear Algebra C++ Library

This project implements some structures and functions to assist in the development of code dealing with linear algebra algorithms. For instance, this project wraps some solvers for larse linear systems and several BLAS routines.

**NOTE**: The files starting with `zz_...` are **unit tests** whereas the files starting with `zzi_...` are **integration tests** (those involving more than one single structure or function).

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

**NOTE**: we cannot use the default Debian package named libmumps-dev because it's missing some additional (and efficient) ordering tools.

### Compilation

Execute:

```bash
./all.bash
```

**NOTE**: we cannot call _cmake_ directly because the compilers must be set via CLI arguments.

## Examples

See the `examples` directory.

### Solving a linear system with a sparse matrix

```c++
#include <iostream>
#include "../src/laclib.h"
using namespace std;

// NOTE: The code must be inside the "run" function because
//       the destructor of SolverMumps calls MPI_Finalize.

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
├── benchmarks
├── data
├── examples
├── src
│   ├── blas
│   ├── check
│   ├── mpiaux
│   ├── sparse
│   └── util
└── zscripts
```

The `src` directory contains all the _library_ code that you can use in your project. However the `blas` and `sparse` _libraries_ might be the most useful for you whereas the rest are mostly used internally here.

`check` contains functions to assist in (unit/integration) tests and `util` contains some utility functions.

`mpiaux` is a wrapper to MPI.
