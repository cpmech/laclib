#!/bin/bash

set -e

MKL=${1:-"OFF"}
OMP=${2:-"ON"}
OPTIMIZED=${3:-"OFF"}
VERBOSE=${4:-"OFF"}

BUILD_TYPE="Debug"
if [ "${OPTIMIZED}" = "ON" ]; then
    BUILD_TYPE="Release"
fi

rm -rf ./build

cmake -D A0_MKL=${MKL} \
      -D A1_OMP=${OMP} \
      -D A2_OPTIMIZED=${OPTIMIZED} \
      -D A3_VERBOSE=${VERBOSE} \
      -D CMAKE_BUILD_TYPE=${BUILD_TYPE} \
      -B build

cd build

make && make test
