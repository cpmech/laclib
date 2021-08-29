#!/bin/bash

set -e

ORDERING=${1:-"metis"}
SOLVER=${2:-"mumps"}

RESDIR=`pwd`/benchmarks/sparse/results/latest

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

gen_fnkey() {
    local matrix=$1
    local has_omp=$2
    local omp_nt=$3
    local plat="_open_seq"
    if [ "${has_omp}" = "ON" ]; then
        plat="${plat}_omp${omp_nt}"
    fi
    echo "${SOLVER}_${matrix}_${ORDERING}${plat}"
}

here=`pwd`

compile() {
    local omp=$1
    echo
    cd $here
    bash ./all-bench.bash $omp
    cd build/benchmarks/sparse
    echo
}

echo
echo
echo "### 1: no omp ###########################################"

compile OFF

for mat in $MATS; do
    fnk=$(gen_fnkey $mat OFF 1)
    log="${RESDIR}/${fnk}.txt"
    echo "... $fnk"
    ./bmark_sparse $mat 1 $ORDERING > $log
done

echo
echo
echo "### 2: with omp #########################################"

compile ON

for mat in $MATS; do
    for n in 1 2 3 4; do
        fnk=$(gen_fnkey $mat ON $n)
        log="${RESDIR}/${fnk}.txt"
        echo "... $fnk"
        ./bmark_sparse $mat $n $ORDERING > $log
    done
done

echo
echo
echo "### done ###"
