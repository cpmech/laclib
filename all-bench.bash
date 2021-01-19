#!/bin/bash

INTEL=${1:-"OFF"}
MPI=${2:-"OFF"}
OMP=${3:-"OFF"}

bash zscripts/do_cmake.bash ${INTEL} ${MPI} ${OMP} ON OFF
cd build/benchmarks/sparse
make
