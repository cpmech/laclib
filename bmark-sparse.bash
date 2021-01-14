#!/bin/bash

INTEL=${1:-"OFF"}

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

#MATS="bfwb62"

RESDIR=`pwd`/benchmarks/sparse/results

PFIX=""
if [ "${INTEL}" = "ON" ]; then
    PFIX="intel_"
fi

bash ./all-bench.bash $INTEL
cd build/benchmarks/sparse

for mat in $MATS; do
    for nt in 1 2 3 4; do
        SFIX="_omp$nt"
        LOG="${RESDIR}/${PFIX}log_${mat}${SFIX}.txt"
        OMP_NUM_THREADS=$nt ./benchmark_sparse $mat > $LOG
    done
done
