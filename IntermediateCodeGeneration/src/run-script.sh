#!/bin/bash
set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
cd "$SCRIPT_DIR"

ANTLR_JAR="${ANTLR_JAR:-$HOME/.m2/repository/org/antlr/antlr4/4.13.2/antlr4-4.13.2-complete.jar}"

if command -v antlr4 >/dev/null 2>&1; then
    antlr4 -Dlanguage=Cpp -visitor -no-listener CSubset.g4
else
    java -jar "$ANTLR_JAR" -Dlanguage=Cpp -visitor -no-listener CSubset.g4
fi

g++ -std=c++17 -w -I/usr/local/include/antlr4-runtime *.cpp -L/usr/local/lib/ -lantlr4-runtime -pthread -o compiler.out

LD_LIBRARY_PATH=/usr/local/lib ./compiler.out "$1"

(
    cd ../io
    fasm code.asm
    fasm optimized_code.asm
    chmod +x code optimized_code
)

echo "Assembled io/code and io/optimized_code"
