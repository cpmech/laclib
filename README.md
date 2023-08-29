# Simple Linear Algebra Library

Laclib implements basic linear algebra functions, wrapping OpenBLAS or Intel MKL. It also wraps MUMPS or Intel Direct Sparse Solver (DSS, e.g., PARDISO) for the solution of large linear systems with sparse matrices.

## Examples

The following code shows how to solve a linear system with a (large) sparse matrix:

```c++
auto one_based = true;
auto trip = read_matrix_market("my-matrix.mtx", one_based);
auto options = MumpsOptions::make_new(trip->symmetric);
auto solver = SolverMumps::make_new(options);
auto rhs = vector<double>(trip->n, 1.0);
auto x = vector<double>(trip->n, 0.0);
solver->analyze_and_factorize(trip);
solver->solve(x, rhs);
```

See [ex_solver_mumps.cpp](https://github.com/cpmech/laclib/blob/main/examples/ex_solver_mumps.cpp) for a complete code.

## Use laclib in your project

After installation (explained below), you may clone https://github.com/cpmech/use-laclib to bootstrap a project using `laclib`.

## Docker image

The docker image is convenient with Visual Code remote development tools (but containerized; "not really remote").

```bash
./build-docker-image.bash
```

## Ubuntu/Linux 22.04

First, follow the procedures from https://github.com/cpmech/script-install-mumps

Then, execute

```bash
./install.bash [OMP]
```

which will compile and install the header files in `/usr/local/include/laclib` and the library files in `/usr/local/lib/laclib`.

The `OMP` option above enables the use of OpenMP when using OpenBLAS.

## Directory structure

```
├── benchmarks   # tests for computational performance
├── data         # auxiliary data for unit tests
├── examples     # examples of usage
├── src          # this is the "main library"
│   ├── analysis # analysis, stats, and reporting
│   ├── check    # functions for unit/integration tests
│   ├── linalg   # basic linear algebra functions
│   ├── sparse   # sparse matrix and solvers tools
│   └── util     # some utilities for file/string manipulations
└── zscripts     # auxiliary "internal" bash scripts
```

We suggest looking at the [sparse](https://github.com/cpmech/laclib/tree/main/src/sparse) directory first.

## Intel MKL Installation

From: https://www.intel.com/content/www/us/en/developer/tools/oneapi/onemkl-download.html

Link advisor: https://www.intel.com/content/www/us/en/developer/tools/oneapi/onemkl-link-line-advisor.html

Example: https://www.intel.com/content/www/us/en/docs/onemkl/tutorial-c/2023-2/multiplying-matrices-using-dgemm.html

### Linux

Select `Linux → APT Package Manager` and follow the instructions (see below).

```bash
bash ./zscripts/install-intel-mkl-linux.bash
```

### Windows

Select `Windows → Online Installer` and follow the instructions.
