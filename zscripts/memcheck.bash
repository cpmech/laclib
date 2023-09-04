#!/bin/bash

set -e

bash all.bash
cd /tmp/build-laclib
#ctest -T memcheck --label-exclude "^noMemcheck$"
ctest -T memcheck --label-regex "^doMemcheck$"
