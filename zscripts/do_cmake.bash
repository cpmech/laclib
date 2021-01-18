#!/bin/bash

USE_INTEL=${1:-"OFF"}
WITH_OMP=${2:-"ON"}
OPTIMIZED=${3:-"OFF"}
VERBOSE=${4:-"OFF"}

CC=/usr/bin/mpicc
CXX=/usr/bin/mpicxx

if [ "${A1_USE_INTEL}" = "ON" ]; then
  CC=/opt/intel/oneapi/mpi/latest/bin/mpiicc
  CXX=/opt/intel/oneapi/mpi/latest/bin/mpiicpc
fi

rm -rf ./build

cmake -D A1_USE_INTEL=${USE_INTEL} \
      -D A2_WITH_OMP=${WITH_OMP} \
      -D A3_OPTIMIZED=${OPTIMIZED} \
      -D A4_VERBOSE=${VERBOSE} \
      -D CMAKE_C_COMPILER=${CC} \
      -D CMAKE_CXX_COMPILER=${CXX} \
      -B build
