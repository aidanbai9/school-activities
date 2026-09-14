#!/bin/bash

echo "ying qi orz..."

g++ -std=c++17 -o main f.cpp &
g++ -std=c++17 -o gen gen.cpp &
g++ -std=c++17 -o solve solve.cpp &
wait

for((t=0;;t++)) do
    printf "\r$t"
    ./gen >input.txt || exit 1
    ./main <input.txt >fast.txt || exit 2
    ./solve <input.txt >slow.txt || exit 3
    diff slow.txt fast.txt || exit 4
done