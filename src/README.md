# Main laclib directory

We suggest looking at the [sparse](https://github.com/cpmech/laclib/tree/main/src/sparse) directory first.

This is the "main" laclib directory with the following:

- [analysis](https://github.com/cpmech/laclib/tree/main/src/analysis) analysis of results and reporting
- [check](https://github.com/cpmech/laclib/tree/main/src/check) functions for unit/integration tests
- [sparse](https://github.com/cpmech/laclib/tree/main/src/sparse) sparse matrix and solvers tools
- [util](https://github.com/cpmech/laclib/tree/main/src/util) some utilities for file/string manipulations

Here, the files starting with `zz_...` are **unit tests** whereas the files such as `zzi_...` are **integration tests** (those involving more than one single structure or function).
