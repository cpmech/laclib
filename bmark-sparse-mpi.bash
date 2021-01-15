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

MATS="bfwb62"

RESDIR=`pwd`/benchmarks/sparse/results

PFIX=""

bash ./all-bench.bash
cd build/benchmarks/sparse

for mat in $MATS; do
    for np in 1 2 3 4; do
        SFIX="_np$np"
        LOG="${RESDIR}/${PFIX}log_${mat}${SFIX}.txt"
        mpirun -np $np ./benchmark_sparse $mat > $LOG
    done
done
