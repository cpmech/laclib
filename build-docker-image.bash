#!/bin/bash

# arguments
INTEL=${1:-"OFF"}
MPI=${2:-"OFF"}

# images name
BASE="mumps_open"
NAME="laclib_open"
if [ "${INTEL}" = "ON" ]; then
    BASE="mumps_intel"
    NAME="laclib_intel"
fi
if [ "${MPI}" = "ON" ]; then
    BASE="${BASE}_mpi"
    NAME="${NAME}_mpi"
else
    BASE="${BASE}_seq"
    NAME="${NAME}_seq"
fi

# build Docker image
docker build --no-cache -t $NAME . \
    --build-arg BASE_IMAGE=$BASE \
    --build-arg INTEL=$INTEL \
    --build-arg MPI=$MPI

# remove dangling images
docker images -q -f "dangling=true" | xargs docker rmi 2>/dev/null

echo
echo
echo
echo "... SUCCESS ..."
echo
echo "... image ${NAME} created ..."
echo
