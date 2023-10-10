#!/bin/bash

set -e

ORDERING=${1:-"metis"}

N_THREADS=1
#N_THREADS="1 2 3 4 5 6 7 8"

RESDIR=`pwd`/benchmarks/sparse-solver/results/latest

# MATS="bfwb62"

# MATS="Flan_1565"

MATS="pre2"

# MATS="
#     bfwb62 \
#     inline_1 \
# "

# MATS="
#     bfwb62 \
#     inline_1 \
#     Flan_1565 \
#     pre2 \
#     tmt_unsym \
# "

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

gen_fnkey() {
    local solver=$1
    local matrix=$2
    local omp_nt=$3
    local str_ord=$ORDERING
    if [ "${solver}" = "intel" ]; then
        str_ord="unknown"
    fi
    echo "${solver}_${matrix}_${str_ord}_omp${omp_nt}"
}

# compile optimized code
bash all.bash ON

# change to build dir
cd /tmp/build-laclib/benchmarks/sparse-solver

echo
echo
echo "### Intel DSS ###########################################"

for mat in $MATS; do
    for n in $N_THREADS; do
        fnk=$(gen_fnkey intel $mat $n)
        log="${RESDIR}/${fnk}.txt"
        echo "... $fnk"
        ./mm_dss $mat $n $ORDERING > $log
    done
done

echo
echo
echo "### MUMPS ###############################################"

for mat in $MATS; do
    for n in $N_THREADS; do
        fnk=$(gen_fnkey mumps $mat $n)
        log="${RESDIR}/${fnk}.txt"
        echo "... $fnk"
        ./mm_mumps $mat $n $ORDERING > $log
    done
done

echo
echo
echo "### done ###"
