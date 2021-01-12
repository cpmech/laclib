# Main laclib directory

We suggest looking at the [sparse](https://github.com/cpmech/laclib/tree/main/src/sparse) directory first.

This is the "main" laclib directory with the following:

- [blas](https://github.com/cpmech/laclib/tree/main/src/blas) basic linear algebra tools
- [check](https://github.com/cpmech/laclib/tree/main/src/check) functions for unit/integration tests
- [mpiaux](https://github.com/cpmech/laclib/tree/main/src/mpiaux) convenient wrapper to MPI functions
- [sparse](https://github.com/cpmech/laclib/tree/main/src/sparse) sparse matrix and solvers tools
- [util](https://github.com/cpmech/laclib/tree/main/src/util) some utilities for file/string manipulations

Here, the files starting with `zz_...` are **unit tests** whereas the files such as `zzi_...` are **integration tests** (those involving more than one single structure or function).
