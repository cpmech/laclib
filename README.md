# laclib - Linear Algebra (simple) C++17 Library

This project implements some structures and functions to assist in developing code for linear algebra computations. We wrap some BLAS routines and solvers for sparse linear systems.

We use **modern C++17 without the "fancy" stuff**. For example, we keep OOP usage to a minimal. The idea is to follow the best concepts of Rust and Go.

In this repository, the files starting with `zz_...` are **unit tests** whereas the files such as `zzi_...` are **integration tests** (those involving more than one single structure or function).

## Installation

### Ubuntu/Linux 20.10

#### Install the MUMPS Sparse Solver

**NOTE**: we prefer to compile MUMPS ourselves instead of using the default Debian package named _libmumps-dev_ because the Debian package doesn't include some additional, and efficient, ordering tools. Also, the libmumps compiled by Debian doesn't include OpenMPI.

Follow the procedures in https://github.com/cpmech/script-install-mumps

#### Install some dependencies

After installing all the dependencies listed by [script-install-mumps](https://github.com/cpmech/script-install-mumps), install:

```bash
sudo apt-get install cmake liblapacke-dev
```

#### Compilation

Execute:

```bash
./all.bash
```

We could call _cmake_ directly as long as we'd set the CC and CXX environmental flags first; see the file [all.bash](https://github.com/cpmech/laclib/blob/main/all.bash).

## Examples

The following code shows how to solve a linear system with a (large) sparse matrix:

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