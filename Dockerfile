ARG BASE_IMAGE
ARG INTEL="OFF"
ARG MPI="OFF"

FROM ${BASE_IMAGE}

# install deps
ENV DEBIAN_FRONTEND=noninteractive
SHELL ["/bin/bash", "-c"]
RUN apt-get update -y && apt-get install -y --no-install-recommends \
  liblapacke-dev \
  && apt-get clean && rm -rf /var/lib/apt/lists/*

# copy files
COPY . /tmp/app
WORKDIR /tmp/app

# install laclib
RUN bash install.bash ${INTEL} ${MPI}
RUN bash install.bash ${INTEL} ${MPI} "ON"

# configure image for remote development
RUN bash zscripts/common-debian.sh
