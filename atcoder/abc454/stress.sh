#!/bin/bash

echo "orz ying qi"

g++ -std=c++17 -o main e.cpp &
g++ -std=c++17 -o gen gen.cpp &
wait

for((t=0;;t++)) do
    printf "\r$t"
    ./gen >input.txt || exit 1
    ./main <input.txt >fast.txt || exit 2
done