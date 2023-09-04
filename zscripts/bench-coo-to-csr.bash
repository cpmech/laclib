#!/bin/bash

set -e

N_THREADS="1 2"

MATS="Flan_1565"

gen_fnkey() {
    local method=$1
    local matrix=$2
    local omp_nt=$3
    echo "${method}_${matrix}_omp${omp_nt}"
}

# compile optimized code
bash all.bash ON

# change to build dir
cd /tmp/build-laclib/benchmarks/coo-to-csr

echo
echo
echo "### MKL #################################################"

for mat in $MATS; do
    for n in $N_THREADS; do
        fnk=$(gen_fnkey mkl $mat $n)
        echo "... $fnk"
        ./bmark_conv_mkl $mat $n
    done
done

echo
echo
echo "### LOCAL ###############################################"

for mat in $MATS; do
    for n in $N_THREADS; do
        fnk=$(gen_fnkey local $mat $n)
        echo "... $fnk"
        ./bmark_conv_local $mat $n
    done
done

echo
echo
echo "### done ###"
