#!/bin/bash

A1_USE_INTEL=${1:-"OFF"}
A2_OPTIMIZED=${2:-"OFF"}
A3_VERBOSE=${3:-"OFF"}

CC=/usr/bin/mpicc
CXX=/usr/bin/mpicxx

if [ "${A1_USE_INTEL}" = "ON" ]; then
  CC=/opt/intel/oneapi/mpi/latest/bin/mpiicc
  CXX=/opt/intel/oneapi/mpi/latest/bin/mpiicpc
fi

rm -rf ./build

cmake -D A1_USE_INTEL=${A1_USE_INTEL} \
      -D A2_OPTIMIZED=${A2_OPTIMIZED} \
      -D A3_VERBOSE=${A3_VERBOSE} \
      -D CMAKE_C_COMPILER=${CC} \
      -D CMAKE_CXX_COMPILER=${CXX} \
      -B build