#!/bin/bash

bash all.bash
cd /tmp/build-laclib
ctest -T memcheck
