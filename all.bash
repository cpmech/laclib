#!/bin/bash

set -e

OPTIMIZED=${1:-"OFF"}

BUILD_TYPE="Debug"
if [ "${OPTIMIZED}" = "ON" ]; then
    BUILD_TYPE="Release"
fi

SOURCE=`pwd`

cd /tmp
mkdir -p build-laclib
cd build-laclib/
cmake -S $SOURCE \
    -D A1_OPTIMIZED=${OPTIMIZED} \
    -D CMAKE_BUILD_TYPE=${BUILD_TYPE}

make && make test
