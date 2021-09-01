# Linear Algebra (simple) C++17 Library

Laclib wraps UMFPACK and MUMP solvers to solve large linear systems with a sparse matrix.

We use **modern C++17 without the "fancy" stuff**. For example, we keep OOP usage to a minimal. The idea is to follow the best concepts of Rust and Go.

In this repository, the files starting with `zz_...` are **unit tests** whereas the files such as `zzi_...` are **integration tests** (those involving more than one single structure or function).

## Examples

The following code shows how to solve a linear system with a (large) sparse matrix:

```c++
auto onebased = true;
auto trip = read_matrix_market("my-matrix.mtx", onebased);
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

After installing the MUMPS docker image according to [script-install-mumps](https://github.com/cpmech/script-install-mumps), we can build the Laclib Docker image by running:

```bash
./build-docker-image.bash
```

## Ubuntu/Linux 20.10

First, follow the procedures in https://github.com/cpmech/script-install-mumps

Next, compile and install the header files in `/usr/local/include/laclib` and the library files in `/usr/local/lib/laclib`, by using:

```bash
./install.bash [OMP]
```

where:

1. OMP = ON or OFF to allow use of OpenMP.

### Developing and debugging Laclib

Execute:

```bash
./all.bash [OMP]
```

## Code organization

```
├── benchmarks   # tests for computational performance
├── data         # auxiliary data for unit tests
├── examples     # examples of usage
├── src          # this is the "main library"
│   ├── analysis # analysis, stats, and reporting
│   ├── check    # functions for unit/integration tests
│   ├── sparse   # sparse matrix and solvers tools
│   └── util     # some utilities for file/string manipulations
└── zscripts     # auxiliary "internal" bash scripts
```

We suggest looking at the [sparse](https://github.com/cpmech/laclib/tree/main/src/sparse) directory first.
