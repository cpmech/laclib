#!/bin/bash

cd build
make
ctest -T memcheck
