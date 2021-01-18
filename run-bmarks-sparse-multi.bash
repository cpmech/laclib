#!/bin/bash

set -e

USE_INTEL=${1:-"OFF"}
WITH_OMP=${2:-"OFF"}
ORDERING=${3:-"metis"}
SOLVER_KIND=${4:-"mumps"}

fnkey() {
    local matrix=$1
    local np_or_nt=$2
    local pfx=""
    local sfx=""
    if [ "${USE_INTEL}" = "ON" ]; then
        pfx="intel_"
    fi
    if [ "${WITH_OMP}" = "ON" ]; then
        sfx="_omp${np_or_nt}"
    else
        sfx="_mpi${np_or_nt}"
    fi
    echo "${pfx}${SOLVER_KIND}_${matrix}_${ORDERING}${sfx}"
}

MATS="
    bfwb62 \
    inline_1 \
    Flan_1565 \
    pre2 \
    tmt_unsym \
"

# MATS="
#     bfwb62 \
#     inline_1 \
#     Flan_1565 \
#     pre2 \
#     tmt_unsym \
#     av41092 \
#     helm2d03 \
#     oilpan \
#     twotone \
# "

#MATS="bfwb62"
# MATS="inline_1"

IGNORE_OMP=0
RESDIR=`pwd`/benchmarks/sparse/results

bash ./all-bench.bash $USE_INTEL $WITH_OMP
cd build/benchmarks/sparse

for mat in $MATS; do
    for n in 1 2 3 4; do
        if [ "${WITH_OMP}" = "ON" ]; then
            fnk=$(fnkey $mat $n)
            echo "... $fnk"
            log="${RESDIR}/${fnk}.txt"
            ./bmark_sparse $mat $n $ORDERING > $log
        else
            fnk=$(fnkey $mat $n)
            echo "... $fnk"
            log="${RESDIR}/${fnk}.txt"
            mpirun -np $n ./bmark_sparse $mat $IGNORE_OMP $ORDERING > $log
        fi
    done
done
