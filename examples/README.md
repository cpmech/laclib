# Examples using laclib

## Solving a linear system with a sparse matrix

The file [ex_solver_mumps.cpp](https://github.com/cpmech/laclib/blob/main/examples/ex_solver_mumps.cpp) shows how to solve the following small linear system using MUMPS:

```
           A              x         b
  [  2  3  0  0  0  ]   [ x0 ]   [  8 ]
  [  3  0  4  0  6  ]   [ x1 ]   [ 45 ]
  [  0 -1 -3  2  0  ] ⋅ [ x2 ] = [ -3 ]
  [  0  0  1  0  0  ]   [ x3 ]   [  3 ]
  [  0  4  2  0  1  ]   [ x4 ]   [ 19 ]

where A is stored as a "triplet" of indices and values

NOTE: the triplet may contain entries with duplicated indices

The solution is: x = {1, 2, 3, 4, 5}
```
