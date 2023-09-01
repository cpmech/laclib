# sparse - Sparse Matrices

This directory contains functions and structures for solving problems involving sparse matrices.

The main structures here are `CooMatrix` and `SolverMumps`. `CooMatrix` holds the content of a sparse matrix in _triplet_ (or coordinate) format. `SolverMumps` wraps the sparse solver MUMPS that finds the solution of large sparse linear systems.

## CooMatrix (aka Triplet)

The CooMatrix structure holds the content of a sparse matrix; those containing several entries with zero values. Only the non-zero entries need to be stored, however. The triplet is a set of row index (i), column index (j), and the real matrix value (x).

In this project, we like to use a function named `make_new` to allocate any "object/structure" instead of using "constructors."

For example:

```c++
auto coo = CooMatrix::make_new(3, 3, 4);
```

allocates a triplet with three rows, three columns, and four non-zero values. `coo` is a `unique_ptr` that can be "passed around" while the C++17 will worry about memory management.

After allocation, we can fill the triplet with values as follows:

```c++
coo->put(0, 0, 10.0);
coo->put(1, 1, 11.0);
coo->put(2, 2, 12.0);
coo->put(0, 1, 4.0);
```

Now, we can give the triplet to a sparse linear solver (or do something else).

Another way to create a CooMatrix is to read a MatrixMarket file (see https://math.nist.gov/MatrixMarket/ and https://sparse.tamu.edu/). To do so, we can use the function `read_matrix_market.` For instance:

```c++
auto coo = read_matrix_market("large-matrix.mtx");
```

will read "large-matrix.mtx" and store the values in a CooMatrix where the indices of rows and columns start at 1 (one-based, as required by MUMPS).

## SolverMumps

SolverMumps wraps the high-performant linear solver named MUMPS (not the disease) that can handle very large sparse matrices. The problem solved by MUMPS is: find x such that A ⋅ x = b. In other words, x is the vector given by x = A⁻¹ ⋅ b. Note however that it's not generally efficient to perform the matrix inversion first.

MUMPS solves the problem by doing three steps: analysis, factorization, and back substitution (the "solve" step). In this way, having the CooMatrix configured already, we can use SolverMumps as follows:

```c++
auto coo = read_matrix_market("my-matrix.mtx");
auto options = MumpsOptions::make_new(is_symmetric(coo->layout));
auto solver = SolverMumps::make_new(options);
auto rhs = vector<double>(coo->n, 1.0);
auto x = vector<double>(coo->n, 0.0);
solver->analyze_and_factorize(coo);
solver->solve(x, rhs);
```

See the [examples](https://github.com/cpmech/laclib/tree/main/examples) directory for more examples.
