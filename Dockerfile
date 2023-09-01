# select base image
ARG BASE_IMAGE
FROM ${BASE_IMAGE}

# install deps
ENV DEBIAN_FRONTEND=noninteractive
SHELL ["/bin/bash", "-c"]
RUN apt-get update -y && apt-get install -y --no-install-recommends \
  liblapacke-dev \
  wget \
  && apt-get clean && rm -rf /var/lib/apt/lists/*

# copy files
COPY . /tmp/laclib
WORKDIR /tmp/laclib

# install Intel MKL
RUN bash zscripts/install-intel-mkl-linux.bash

# configure image for remote development
RUN bash zscripts/common-debian.sh

# install laclib
# RUN bash install.bash
