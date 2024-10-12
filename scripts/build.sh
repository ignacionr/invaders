#!/bin/bash

mkdir -p build
pushd build
g++ ../src/invaders.cpp -std=c++20 -o invaders -lncurses
popd
