#!/bin/bash

echo "compiling..."

g++ -std=c++17 -o main p1.cpp -DLOCAL
g++ -std=c++17 -o solve solve.cpp -DLOCAL
g++ -std=c++17 -o gen gen.cpp -DLOCAL
wait

for((t=0;;t++)) do
    printf "\r$t"
    ./gen >input.txt || exit 1
    ./main <input.txt >fast.txt || exit 2
    ./solve <input.txt >slow.txt || exit 3
    diff fast.txt slow.txt || exit 4
done