#!/bin/bash

set -e

# fake sudo function to be used by docker build
sudo () {
  [[ $EUID = 0 ]] || set -- command sudo "$@"
  "$@"
}

# install packages
sudo apt-get update -y && \
sudo apt-get install -y --no-install-recommends \
    cmake \
    g++ \
    gdb \
    gfortran \
    git \
    liblapacke-dev \
    libmetis-dev \
    libopenblas-dev \
    make \
    patch

bash zscripts/install-intel-mkl-linux.bash
