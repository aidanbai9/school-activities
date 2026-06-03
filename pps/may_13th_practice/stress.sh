#!/bin/bash

echo "YING QI"

g++ -std=c++17 -o main h.cpp &
g++ -std=c++17 -o gen gen.cpp &
wait

for((t=0;;t++)) do

    ./gen >input.txt || exit 1
    ./main <input.txt >fast.txt || exit 2
done