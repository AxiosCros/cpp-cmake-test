#!/bin/bash

rm -rf build
mkdir -p build
cd build/
cmake -DENABLE_UNIT_TESTS=ON ..
cmake --build .
./cpp_test
