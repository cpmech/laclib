#!/bin/bash

set -e

BMARK_DIR=`pwd`/benchmarks/sparse
ANA_DIR=$BMARK_DIR/analysis
README=$BMARK_DIR/README.md

cd $ANA_DIR
yarn build
node dist/cjs/index.js > $README
