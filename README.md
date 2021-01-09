# laclib - Linear Algebra C Library

Work in progress..

## Install MUMPS Sparse Solver

Follow the procedures from https://github.com/cpmech/script-install-mumps

## Compilation

NOTE: we cannot call _cmake_ directly because the compilers must be set via CLI arguments, so use the following script:

```bash
./all.bash
```

## Dependencies

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