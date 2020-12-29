#!/bin/bash

bash zscripts/do_cmake.bash
cd build
make && make test