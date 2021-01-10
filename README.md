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

### Solving a linear system with a sparse matrix

```c++
// TODO
```

## Code organization

```
.
├── benchmarks
│   ├── blas
│   └── sparse
├── data
│   └── sparse-matrix
│       └── results
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
