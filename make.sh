#!/bin/bash

if [ ! -d ./build/ ]; then
  mkdir ./build
fi;

cd build

if [ "$1"="debug" ]; then
  cmake -DCMAKE_BUILD_TYPE=debug ..
else
  cmake -DCMAKE_BUILD_TYPE=release ..
fi;

make

cd ..
