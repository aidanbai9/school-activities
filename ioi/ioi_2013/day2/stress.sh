#!/bin/bash

echo "compiling..."
g++ -std=c++17 -o main p3.cpp &
g++ -std=c++17 -o gen gen.cpp &
wait

for((t=0;;t++)) do
    printf "\r$t"
    ./gen >robots.in || exit 1
    ./main || exit 2
done