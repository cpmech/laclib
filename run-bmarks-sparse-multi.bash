#!/bin/bash

set -e

INTEL=${1:-"OFF"}
ORDERING=${2:-"metis"}
SOLVER=${3:-"mumps"}

if [ "${INTEL}" = "ON" ]; then
    RESDIR=`pwd`/benchmarks/sparse/results/intel
else
    RESDIR=`pwd`/benchmarks/sparse/results/open
fi

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

gen_fnkey() {
    local matrix=$1
    local has_mpi=$2
    local has_omp=$3
    local mpi_np=$4
    local omp_nt=$5
    local plat="_open"
    if [ "${INTEL}" = "ON" ]; then
        plat="_intel"
    fi
    if [ "${has_mpi}" = "ON" ]; then
        plat="${plat}_mpi${mpi_np}"
    else
        plat="${plat}_seq"
    fi
    if [ "${has_omp}" = "ON" ]; then
        plat="${plat}_omp${omp_nt}"
    fi
    echo "${SOLVER}_${matrix}_${ORDERING}${plat}"
}

here=`pwd`

compile() {
    local mpi=$1
    local omp=$2
    echo
    cd $here
    bash ./all-bench.bash $INTEL $mpi $omp
    cd build/benchmarks/sparse
    echo
}

echo
echo
echo "### no mpi, no omp => seq ###########################################"

compile OFF OFF

for mat in $MATS; do
    fnk=$(gen_fnkey $mat OFF OFF 1 1)
    log="${RESDIR}/${fnk}.txt"
    echo "... $fnk"
    ./bmark_sparse $mat 1 $ORDERING > $log
done

echo
echo
echo "### no mpi, with omp => seq + omp ###################################"

compile OFF ON

for mat in $MATS; do
    for n in 1 2 3 4; do
        fnk=$(gen_fnkey $mat OFF ON 1 $n)
        log="${RESDIR}/${fnk}.txt"
        echo "... $fnk"
        ./bmark_sparse $mat $n $ORDERING > $log
    done
done

echo
echo
echo "### with mpi, no omp ################################################"

compile ON OFF

for mat in $MATS; do
    for n in 1 2 3 4; do
        fnk=$(gen_fnkey $mat ON OFF $n 1)
        log="${RESDIR}/${fnk}.txt"
        echo "... $fnk"
        mpirun -np $n ./bmark_sparse $mat 1 $ORDERING > $log
    done
done

echo
echo
echo "### with mpi and with omp, but changing omp only ####################"

compile ON ON

for mat in $MATS; do
    for n in 1 2 3 4; do
        fnk=$(gen_fnkey $mat ON ON 1 $n)
        log="${RESDIR}/${fnk}.txt"
        echo "... $fnk"
        mpirun -np 1 ./bmark_sparse $mat $n $ORDERING > $log
    done
done

echo
echo
echo "### with mpi and with omp, but changing mpi only ####################"

compile ON ON

for mat in $MATS; do
    for n in 1 2 3 4; do
        fnk=$(gen_fnkey $mat ON ON $n 1)
        log="${RESDIR}/${fnk}.txt"
        echo "... $fnk"
        mpirun -np $n ./bmark_sparse $mat 1 $ORDERING > $log
    done
done

echo
echo
echo "### with mpi and with omp, and changing both ########################"

compile ON ON

for mat in $MATS; do
    for np in 1 2; do
        for nt in 1 2; do
            fnk=$(gen_fnkey $mat ON ON $np $nt)
            log="${RESDIR}/${fnk}.txt"
            echo "... $fnk"
            mpirun -np $np ./bmark_sparse $mat $nt $ORDERING > $log
        done
    done
done

echo
echo
echo "### done ###"
