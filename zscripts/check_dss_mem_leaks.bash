#!/bin/bash

cd build
make && ctest -T memcheck -R solver_dss
