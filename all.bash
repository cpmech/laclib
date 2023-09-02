#!/bin/bash

set -e

MKL=${1:-"OFF"}
OPTIMIZED=${2:-"OFF"}

BUILD_TYPE="Debug"
if [ "${OPTIMIZED}" = "ON" ]; then
    BUILD_TYPE="Release"
fi

rm -rf ./build

cmake \
    -D A1_MKL=${MKL} \
    -D A2_OPTIMIZED=${OPTIMIZED} \
    -D CMAKE_BUILD_TYPE=${BUILD_TYPE} \
    -B build

cd build

make && make test
