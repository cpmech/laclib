#!/bin/bash

ME="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"

NP=${1:-"1"}
PROG=${2:-"./z_test_solver_mumps_np1"}

SUPP1=/opt/intel/oneapi/itac/latest/lib/impi.supp
SUPP2=${ME}/valgrind.supp

LOG=/tmp/laclib.mpirun.vg

rm -f $LOG.*

mpirun -np ${NP} valgrind \
  --leak-check=full \
  --show-reachable=yes \
  --show-leak-kinds=definite,indirect,possible \
  --suppressions=${SUPP1} \
  --suppressions=${SUPP2} \
  --log-file=${LOG}.%p \
  ${PROG}

ls $LOG.*
