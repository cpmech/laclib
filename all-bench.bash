#!/bin/bash

A1_USE_INTEL=${1:-"OFF"}
A2_OPTIMIZED=${2:-"ON"}
A3_VERBOSE=${3:-"OFF"}

bash zscripts/do_cmake.bash ${A1_USE_INTEL} ${A2_OPTIMIZED} ${A3_VERBOSE}
cd build/benchmarks/sparse
make