# Benchmarks using laclib

This directory contains some benchmark tests using the _laclib_ library.

**NOTE:** The benchmarks require MUMPS, thus they only work on **Linux** at the moment.

```
├── benchmarks
│   ├── coo-to-csr            # conversion of COO to CSR matrix
│   ├── intel-website-results # results published by Intel
    └── sparse-solver         # performance of sparse solvers
```

First, we need to download some (large) test matrices:

```bash
bash zscripts/download-from-matrix-market.bash
```

Then, run:

```bash
bash zscripts/bench-sparse-solver.bash
```

The results will be saved in the [benchmarks/sparse-solver/results/latests](https://github.com/cpmech/laclib/tree/main/benchmarks/sparse-solver/results-results/latest) directory.
