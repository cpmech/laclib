#!/bin/bash

OMP=${1:-"OFF"}
OPTIMIZED=${2:-"OFF"}
VERBOSE=${3:-"OFF"}

bash zscripts/do_cmake.bash ${OMP} ${OPTIMIZED} ${VERBOSE}
cd build
make && make test
