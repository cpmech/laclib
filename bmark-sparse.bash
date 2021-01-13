#!/bin/bash

MATS="
    av41092 \
    bfwb62 \
    Flan_1565 \
    helm2d03 \
    inline_1 \
    oilpan \
    pre2 \
    tmt_unsym \
    twotone \
"

# MATS="bfwb62"

bash ./all-bench.bash
cd build/benchmarks/sparse

for mat in $MATS; do
    for nt in 1 2 3 4; do
        OMP_NUM_THREADS=$nt ./benchmark_sparse $mat
    done
done
