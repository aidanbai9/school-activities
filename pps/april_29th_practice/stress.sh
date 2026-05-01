#!/bin/bash

echo "compiling..."

g++ -std=c++17 -o gen gen.cpp &
g++ -std=c++17 -o main g2.cpp &
wait

for((t=0;;t++)) do
    printf "\r$t"
    ./gen >input.txt || exit 1
    ./main <input.txt >output.txt || exit 2
done