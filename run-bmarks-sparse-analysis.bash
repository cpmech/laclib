#!/bin/bash

set -e

BMARK_DIR=`pwd`/benchmarks/sparse
ANA_DIR=$BMARK_DIR/analysis

cd $ANA_DIR
yarn build

A="open_intel_ana_fact_all"

node dist/cjs/index.js $A > "${BMARK_DIR}/README-${A}.md"
