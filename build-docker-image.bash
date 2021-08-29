#!/bin/bash

# images name
BASE="mumps_open"
NAME="laclib_open"

# message
echo
echo
echo "... the base image is = ${BASE} ..."
echo

# build Docker image
docker build --no-cache -t $NAME . \
    --build-arg BASE_IMAGE=$BASE

# remove dangling images
docker images -q -f "dangling=true" | xargs docker rmi 2>/dev/null

echo
echo
echo
echo "... SUCCESS ..."
echo
echo "... image ${NAME} created ..."
echo
