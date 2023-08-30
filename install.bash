#!/bin/bash

set -e

# arguments
MKL=${1:-"ON"}
OMP=${2:-"OFF"}

# options
PREFIX="/usr/local"
INCDIR=$PREFIX/include/laclib
LIBDIR=$PREFIX/lib/laclib

# platform suffix
PLAT=""
if [ "${MPI}" = "ON" ]; then
    PLAT="_intel"
else
    PLAT="_open_seq"
    if [ "${OMP}" = "ON" ]; then
        PLAT="${PLAT}_omp"
    fi
fi

# remove previous build
rm -rf ./build

# call cmake
cmake -D A0_MKL=${MKL} \
      -D A1_OMP=${OMP} \
      -D A2_OPTIMIZED="ON" \
      -D A3_VERBOSE="OFF" \
      -D CMAKE_BUILD_TYPE="Release" \
      -B build

# compile the library
cd build
make && make test
cd ..

# copy internal include files
SUBDIRS="
    analysis
    check
    linalg
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
