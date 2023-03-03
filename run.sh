#!/bin/zsh

g++ Main.cc -o Main -O2 -Wall -lm -std=gnu++17 -DONLINE_JUDGE -DBOJ

cat $1 | ./Main
