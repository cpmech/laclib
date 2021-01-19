#!/bin/bash

set -e

INTEL=${1:-"OFF"}
MPI=${2:-"OFF"}
OMP=${3:-"OFF"}
OPTIMIZED=${4:-"OFF"}
VERBOSE=${5:-"OFF"}

CC=/usr/bin/mpicc
CXX=/usr/bin/mpicxx

if [ "${INTEL}" = "ON" ]; then
    CC=/opt/intel/oneapi/mpi/latest/bin/mpiicc
    CXX=/opt/intel/oneapi/mpi/latest/bin/mpiicpc
fi

BUILD_TYPE="Debug"
if [ "${OPTIMIZED}" = "ON" ]; then
    BUILD_TYPE="Release"
fi

rm -rf ./build

cmake -D A1_INTEL=${INTEL} \
      -D A2_MPI=${MPI} \
      -D A3_OMP=${OMP} \
      -D A4_OPTIMIZED=${OPTIMIZED} \
      -D A5_VERBOSE=${VERBOSE} \
      -D CMAKE_C_COMPILER=${CC} \
      -D CMAKE_CXX_COMPILER=${CXX} \
      -D CMAKE_BUILD_TYPE=${BUILD_TYPE} \
      -B build
