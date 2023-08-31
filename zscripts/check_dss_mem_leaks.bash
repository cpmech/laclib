#!/bin/bash

cd build/src/sparse
make && ctest -T memcheck -R solver_dss
