#!/bin/bash

mkdir -p build
cd build && cmake -S .. -B . --log-level=STATUS
cmake --build . --parallel
cd ..
