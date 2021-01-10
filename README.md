# laclib - Linear Algebra C++ Library

This project implements some structures and functions to assist the development of code involving (large) linear algebra problems.

**NOTE**: The files starting with `zz_...` are _unit_ tests whereas the files starting with `zzi_...` are _integration_ tests.

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

### Compilation

NOTE: we cannot call _cmake_ directly because the compilers must be set via CLI arguments, so use the following script:

```bash
./all.bash
```

## Examples

### Solving a linear system with a sparse matrix

```c++
// TODO
```
