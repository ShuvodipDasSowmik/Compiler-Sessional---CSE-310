#!/bin/bash

# Build script for the Symbol Table assignment
# Compiles with address and undefined sanitizers, then runs with input.txt

echo "Building with address and undefined sanitizers..."
g++ -std=c++17 -Wall -g -fsanitize=address,undefined -o symbol_table 2205150_main.cpp

if [ $? -ne 0 ]; then
    echo "Build failed. See compiler errors above."
    exit 1
fi

echo "Build successful."

if [ ! -f "input.txt" ]; then
    echo "Warning: input.txt not found in current directory ($(pwd))."
    echo "Run manually with: ./symbol_table input.txt output.txt"
    exit 1
fi

echo "Running with input.txt -> output.txt"
./symbol_table input.txt output.txt

if [ $? -eq 0 ]; then
    echo "Run complete. Check output.txt"
else
    echo "Program exited with an error."
fi