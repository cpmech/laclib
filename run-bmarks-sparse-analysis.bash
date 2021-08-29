#!/bin/bash

set -e

BMARK_DIR=`pwd`/benchmarks/sparse
ANA_DIR=$BMARK_DIR/analysis

cd $ANA_DIR
npm run build

CASES="
    open_seq_ana_fact_total
"

for case in $CASES; do
    node dist/cjs/index.js $case > "${BMARK_DIR}/README-${case}.md"
done
