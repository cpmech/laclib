# select base image
ARG BASE_IMAGE
FROM ${BASE_IMAGE}

# install deps
ENV DEBIAN_FRONTEND=noninteractive
SHELL ["/bin/bash", "-c"]
RUN apt-get update -y && apt-get install -y --no-install-recommends \
  liblapacke-dev \
  && apt-get clean && rm -rf /var/lib/apt/lists/*

# copy files
COPY . /tmp/laclib
WORKDIR /tmp/laclib

# install laclib
RUN bash install.bash "OFF"
RUN bash install.bash "ON"

# configure image for remote development
RUN bash zscripts/common-debian.sh
