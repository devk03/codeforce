#!/bin/bash

# Compile C++ file with optimizations and debug info
g++ -std=c++17 -O2 -Wall -Wextra -pedantic -Wno-unused-const-variable -o main main.cpp

if [ $? -eq 0 ]; then
    echo "[STEP] Compilation successful!"
else
    echo "[STEP] Compilation failed!"
    exit 1
fi