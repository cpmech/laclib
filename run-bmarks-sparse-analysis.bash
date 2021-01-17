#!/bin/bash

set -e

BMARK_DIR=`pwd`/benchmarks/sparse
ANA_DIR=$BMARK_DIR/analysis
README=$BMARK_DIR/README.md
README_INTEL=$BMARK_DIR/README-INTEL.md

cd $ANA_DIR
yarn build
node dist/cjs/index.js > $README
node dist/cjs/index.js ON > $README_INTEL
