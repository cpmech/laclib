#!/bin/bash

USE_INTEL=${1:-"OFF"}

if [ "${USE_INTEL}" = "ON" ]; then
    docker build --no-cache -t laclib_intel . -f zscripts/Dockerfile-intel
else
    docker build --no-cache -t laclib_open . -f zscripts/Dockerfile-open
fi

docker images -q -f "dangling=true" | xargs docker rmi 2>/dev/null
