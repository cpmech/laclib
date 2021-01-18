#!/bin/bash

USE_INTEL=${1:-"OFF"}
WITH_OMP=${2:-"ON"}
OPTIMIZED=${3:-"OFF"}
VERBOSE=${4:-"OFF"}

bash zscripts/do_cmake.bash ${USE_INTEL} ${WITH_OMP} ${OPTIMIZED} ${VERBOSE}
cd build/benchmarks/sparse
make
