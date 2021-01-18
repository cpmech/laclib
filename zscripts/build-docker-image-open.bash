#!/bin/bash

docker build --no-cache -t laclib_open . -f zscripts/Dockerfile-open
docker images -q -f "dangling=true" | xargs docker rmi
