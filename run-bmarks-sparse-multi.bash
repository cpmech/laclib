#!/bin/bash

set -e

USE_OMP=${1:-"false"}
ORDERING=${2:-"metis"}
USE_INTEL=${3:-"false"}
SOLVER_KIND=${4:-"mumps"}

# INPUT:
#   1 -- matrix name [string]
#   2 -- mpi size [number]
#   3 -- omp num threads [number]
#   4 -- solver kind [string]
#   5 -- ordering [string]
#   6 -- intel {true, false}
fnkey() {
    local matrixName=$1
    local mpiSize=$2
    local ompNumThreads=$3
    local solverKind=$4
    local ordering=$5
    local intel=$6
    local pfx=""
    local sfx=""
    if [ "${intel}" = "true" ]; then
        pfx="intel_"
    fi
    if [ ${ompNumThreads} -gt 0 ]; then
        sfx="_omp${ompNumThreads}"
    else
        sfx="_mpi${mpiSize}"
    fi
    echo "${pfx}${solverKind}_${matrixName}_${ordering}${sfx}"
}

MATS="
    inline_1 \
    Flan_1565 \
    pre2 \
    bfwb62 \
"

# MATS="
#     inline_1 \
#     Flan_1565 \
#     pre2 \
#     bfwb62 \
#     av41092 \
#     helm2d03 \
#     oilpan \
#     tmt_unsym \
#     twotone \
# "

# MATS="bfwb62"

RESDIR=`pwd`/benchmarks/sparse/results

bash ./all-bench.bash
cd build/benchmarks/sparse

for mat in $MATS; do
    for n in 1 2 3 4; do
        if [ "${USE_OMP}" = "true" ]; then
            fnk=$(fnkey $mat 1 $n $SOLVER_KIND $ORDERING $USE_INTEL)
            echo "... $fnk"
            log="${RESDIR}/${fnk}.txt"
            OMP_NUM_THREADS=$n ./benchmark_sparse $mat > $log
        else
            fnk=$(fnkey $mat $n 0 $SOLVER_KIND $ORDERING $USE_INTEL)
            echo "... $fnk"
            log="${RESDIR}/${fnk}.txt"
            mpirun -np $n ./bmark_sparse $mat $ORDERING > $log
        fi
    done
done
