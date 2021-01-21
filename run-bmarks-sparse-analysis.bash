#!/bin/bash

set -e

BMARK_DIR=`pwd`/benchmarks/sparse
ANA_DIR=$BMARK_DIR/analysis

cd $ANA_DIR
yarn build

CASES="
    open_seq_ana_fact_total
    open_mpionly_ana_fact_total
    open_mpi1_omp_fact_problem
    open_intel_all_fact
"

for case in $CASES; do
    node dist/cjs/index.js $case > "${BMARK_DIR}/README-${case}.md"
done
