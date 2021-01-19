#!/bin/bash

set -e

INTEL=${1:-"OFF"}
MPI=${2:-"OFF"}
OMP=${3:-"OFF"}
ORDERING=${4:-"metis"}
SOLVER=${5:-"mumps"}

fnkey() {
    local matrix=$1
    local np_or_nt=$2
    PLAT="_open"
    if [ "${INTEL}" = "ON" ]; then
        PLAT="_intel"
    fi
    if [ "${MPI}" = "ON" ]; then
        PLAT="${PLAT}_mpi${np_or_nt}"
    else
        PLAT="${PLAT}_seq"
    fi
    if [ "${OMP}" = "ON" ]; then
        PLAT="${PLAT}_omp${np_or_nt}"
    fi
    echo "${SOLVER}_${matrix}_${ORDERING}${PLAT}"
}

RESDIR=`pwd`/benchmarks/sparse/results

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

MATS="bfwb62"

bash ./all-bench.bash $INTEL $MPI $OMP
cd build/benchmarks/sparse

NN="1"
if [ "${MPI}" = "ON" ] || [ "${OMP}" = "ON" ]; then
    NN="1 2 3 4"
fi

for mat in $MATS; do
    for n in $NN; do
        fnk=$(fnkey $mat $n)
        log="${RESDIR}/${fnk}.txt"
        echo "... $fnk"
        if [ "${MPI}" = "ON" ]; then
            mpirun -np $n ./bmark_sparse $mat 1 $ORDERING > $log
        else
            ./bmark_sparse $mat $n $ORDERING > $log
        fi
    done
done
