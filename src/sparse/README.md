# sparse - Sparse Matrices

This directory contains functions and structures for solving problems involving sparse matrices.

NOTE: Files starting with `zz_...` are **unit** tests whereas files starting with `zzi_...` are
**integration** tests.

The main structures here are `SparseTriplet` and `SolverMumps`. `SparseTriplet` holds the content of a sparse matrix in _triplet_ (or coordinate) format. `SolverMumps` wraps the sparse solver MUMPS that finds the solution of large sparse linear systems.