#!/bin/bash

echo "ying qi orz..."

g++ -std=c++17 -o main type3.cpp &
g++ -std=c++17 -o solve type2.cpp &
g++ -std=c++17 -o gen gen.cpp &
wait

for((t=0;;t++)) do
    printf "\r$t"
    ./gen >input.txt || exit 1
    ./main <input.txt >fast.txt || exit 2
    ./solve <input.txt >slow.txt || exit 3
    diff fast.txt slow.txt || exit 4
done