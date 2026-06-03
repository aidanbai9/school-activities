#!/bin/bash

echo "compiling..."
g++ -std=c++17 -o main p2.cpp &
g++ -std=c++17 -o gen gen.cpp &
g++ -std=c++17 -o solve solve.cpp &
wait

for((t=0;;t++)) do
    printf "\r$t"
    ./gen >robots.in || exit 1
    ./main >fast.txt || exit 2
    ./solve >slow.txt || exit 3
    diff fast.txt slow.txt || exit 4
done