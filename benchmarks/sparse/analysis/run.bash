#!/bin/bash

OUTPUT="../README.md"

echo "# Benchmarks using the code for sparse matrices" > $OUTPUT
echo "" >> $OUTPUT
echo "The code here tests the perfomance of the MUMPS Sparse Solver." >> $OUTPUT
echo "" >> $OUTPUT

yarn build
node dist/cjs/index.js >> $OUTPUT

