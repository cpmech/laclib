#!/bin/bash

OMP=${1:-"OFF"}

bash zscripts/do_cmake.bash ${OMP} ON OFF
cd build/benchmarks/sparse
make
