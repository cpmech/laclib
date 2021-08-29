#!/bin/bash

set -e

OMP=${1:-"OFF"}
OPTIMIZED=${2:-"OFF"}
VERBOSE=${3:-"OFF"}

CC=/usr/bin/gcc
CXX=/usr/bin/g++

BUILD_TYPE="Debug"
if [ "${OPTIMIZED}" = "ON" ]; then
    BUILD_TYPE="Release"
fi

rm -rf ./build

cmake -D A1_OMP=${OMP} \
      -D A2_OPTIMIZED=${OPTIMIZED} \
      -D A3_VERBOSE=${VERBOSE} \
      -D CMAKE_C_COMPILER=${CC} \
      -D CMAKE_CXX_COMPILER=${CXX} \
      -D CMAKE_BUILD_TYPE=${BUILD_TYPE} \
      -B build
