# select base image
ARG BASE_IMAGE
FROM ${BASE_IMAGE}

# install deps
ENV DEBIAN_FRONTEND=noninteractive
SHELL ["/bin/bash", "-c"]
RUN apt-get update -y && apt-get install -y --no-install-recommends \
  wget \
  && apt-get clean && rm -rf /var/lib/apt/lists/*

# copy files
COPY . /tmp/docker-laclib
WORKDIR /tmp/docker-laclib

# install Intel MKL
RUN bash install-deps.bash

# configure image for remote development
RUN bash zscripts/common-debian.sh

# install laclib
RUN bash install.bash

# clean up
RUN rm -rf /tmp/docker-laclib
RUN rm -rf /tmp/build-laclib
