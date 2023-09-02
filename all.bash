#!/bin/bash

set -e

OPTIMIZED=${1:-"OFF"}

BUILD_TYPE="Debug"
if [ "${OPTIMIZED}" = "ON" ]; then
    BUILD_TYPE="Release"
fi

rm -rf ./build

cmake \
    -D A1_OPTIMIZED=${OPTIMIZED} \
    -D CMAKE_BUILD_TYPE=${BUILD_TYPE} \
    -B build

cd build

make && make test
