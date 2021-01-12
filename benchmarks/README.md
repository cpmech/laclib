# Benchmarks using laclib

This directory contains some benchmarks using laclib.

```
├── benchmarks
    ├── blas    # tests the performance of some blas code
    └── sparse  # tests the performance of sparse solvers
``

First, we need to download some (large) test matrices in the data subdirectory:

```bash
cd benchmarks/sparse/data
./download.bash
```

Second, we need to compile the benchmark code:

```bash
./all-bench.bash
```

or

```bash
./all.bash OFF ON
```

Then, we can run the benchmarks as follows:

```bash
cd build/benchmarks/sparse
mpirun -np 2 ./benchmark_sparse pre2
```

to run the test with the "pre2" matrix.

The results will be stored in the `benchmarks/sparse/results` directory.

For instance:

```json
{
  "Platform": "laclib",
  "SolverKind": "mumps",
  "MatrixName": "pre2",
  "Ordering": "metis",
  "MpiSize": 1,
  "Symmetric": false,
  "NumberOfRows": 659033,
  "NumberOfCols": 659033,
  "NumberOfNonZeros": 5959282,
  "StepReadMatrix": {
    "ElapsedTimeNanoseconds": 1857100987,
    "ElapsedTimeString": "1.8571s",
    "MemoryBytes": 808529920,
    "MemoryMiB": "771"
  },
  "StepAnalyze": {
    "ElapsedTimeNanoseconds": 5408379292,
    "ElapsedTimeString": "5.40838s",
    "MemoryBytes": 1017524224,
    "MemoryMiB": "970"
  },
  "StepFactorize": {
    "ElapsedTimeNanoseconds": 4797668331,
    "ElapsedTimeString": "4.79767s",
    "MemoryBytes": 17145073664,
    "MemoryMiB": "16,350"
  },
  "StepSolve": {
    "ElapsedTimeNanoseconds": 697503634,
    "ElapsedTimeString": "697.504ms",
    "MemoryBytes": 17145073664,
    "MemoryMiB": "16,350"
  },
  "TimeSolverNanoseconds": 10903484008,
  "TimeSolverString": "10.9035s",
  "Stats": {
    "NormInfA": 1.47772e+10,
    "NormInfAx": 1.00001,
    "NormInfDiff": 1.21593e-05,
    "RelativeError": 8.22847e-16,
    "ElapsedTimeNanoseconds": 35116821,
    "ElapsedTimeString": "35.1168ms"
  }
}
```

indicates that the problem involving the **pre2** matrix took aobut 5.41s to analyze and 4.8s to factorize. The total time analyze+factorize+solve was 10.9s. In this problem, the maximum absolute value of the sparse matrix is 1.47772e+10 and the relative error was about 8e-16. The error calculation took 35ms to compute.
