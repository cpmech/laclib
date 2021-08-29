#!/bin/bash

set -e

# arguments
OMP=${1:-"ON"}

# options
PREFIX="/usr/local"
INCDIR=$PREFIX/include/laclib
LIBDIR=$PREFIX/lib/laclib

# platform suffix
PLAT="_open_seq"
if [ "${OMP}" = "ON" ]; then
    PLAT="${PLAT}_omp"
fi

# compile the library
OPTIMIZED="ON"
bash zscripts/do_cmake.bash $OMP $OPTIMIZED
cd build
make laclib${PLAT}
cd ..

# copy internal include files
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

# copy main include file and library
sudo mkdir -p $LIBDIR
sudo cp -av src/laclib.h $INCDIR/
sudo cp -av build/liblaclib${PLAT}.so $LIBDIR/

# update ldconfig
echo "${LIBDIR}" | sudo tee /etc/ld.so.conf.d/laclib.conf >/dev/null
sudo ldconfig
