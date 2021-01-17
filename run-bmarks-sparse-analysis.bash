#!/bin/bash

set -e

BMARK_DIR=`pwd`/benchmarks/sparse
ANA_DIR=$BMARK_DIR/analysis
README=$BMARK_DIR/README.md

echo "# Benchmarks using the code for sparse matrices" > $README
echo "" >> $README
echo "The code here tests the perfomance of the MUMPS Sparse Solver." >> $README
echo "" >> $README

cd $ANA_DIR
yarn build
node dist/cjs/index.js >> $README
