# laclib - Linear Algebra C++17 Library

This project implements some structures and functions to assist in developing code for linear algebra computations using **modern C++17**. This project wraps some BLAS routines and solvers for sparse linear systems.

In this repository, the files starting with `zz_...` are **unit tests** whereas the files such as `zzi_...` are **integration tests** (those involving more than one single structure or function).

## Installation

### Ubuntu/Linux 20.10

#### Install some dependencies

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
#### Install the MUMPS Sparse Solver

**NOTE**: we prefer to compile MUMPS ourselves instead of using the default Debian package named _libmumps-dev_ because the Debian package doesn't include some additional, and efficient, ordering tools.

Follow the procedures in https://github.com/cpmech/script-install-mumps

#### Compilation

Execute:

```bash
./all.bash
```

We could call _cmake_ directly as long as we'd set the CC and CXX environmental flags first; see the file [all.bash](https://github.com/cpmech/laclib/blob/main/all.bash).

## Examples

The following code shows how to solving a linear system with a (large) sparse matrix:

```c++
auto onebased = true;
auto trip = read_matrix_market("my-matrix.mtx", onebased);
auto mpi = MpiAux::make_new();
auto solver = SolverMumps::make_new(mpi, trip->symmetric);
auto rhs = vector<double>(trip->n, 1.0);
auto x = vector<double>(trip->n, 0.0);
solver->analyze_and_factorize(trip);
solver->solve(x, rhs);
```

See [ex_solver_mumps.cpp](https://github.com/cpmech/laclib/blob/main/examples/ex_solver_mumps.cpp) for the complete code.

See the [examples](https://github.com/cpmech/laclib/tree/main/examples) directory for more examples.

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

We suggest looking at the [sparse](https://github.com/cpmech/laclib/tree/main/src/sparse) directory first.
