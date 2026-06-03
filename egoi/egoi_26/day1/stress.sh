#!/bin/bash

g++ -std=c++17 -o gen gen.cpp
g++ -std=c++17 -o census p4.cpp

for((t=0;;t++)) do
    printf "\r$t"
    ./gen >input.txt || exit 1
    python3 testing_tool.py ./census <input.txt >output.txt || exit 2
done