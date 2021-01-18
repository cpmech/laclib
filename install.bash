#!/bin/bash

set -e

USE_INTEL=${1:-"OFF"}
WITH_OMP=${2:-"ON"}

PREFIX="/usr/local"
INCDIR=$PREFIX/include/laclib
LIBDIR=$PREFIX/lib

if [ "${USE_INTEL}" = "ON" ]; then
    PLAT="_intel"
else
    PLAT="_open"
fi

if [ "${WITH_OMP}" = "ON" ]; then
    PLAT="${PLAT}_omp"
fi

OPTIMIZED="ON"

bash zscripts/do_cmake.bash $USE_INTEL $WITH_OMP $OPTIMIZED
cd build
make laclib${PLAT}
cd ..

SUBDIRS="
    blas
    check
    mpiaux
    sparse
    util
"

for dir in $SUBDIRS; do
    sudo mkdir -p $INCDIR/$dir
    sudo cp -av src/$dir/*.h $INCDIR/$dir/
done

sudo cp -av src/laclib.h $INCDIR/
sudo cp -av build/liblaclib${PLAT}.so $LIBDIR/
sudo ldconfig
