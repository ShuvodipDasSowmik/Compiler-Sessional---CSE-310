#!/bin/bash

shopt -s extglob

for file in !(*.sh|*.g4|*.cpp|*.h|*.hpp|*.pdf|compile_commands.json); do
    if [[ -f "$file" ]]; then
        rm -f "$file"
    fi
done

rm -f CSubset.interp CSubset.tokens CSubsetLexer.cpp CSubsetLexer.h CSubsetLexer.interp CSubsetLexer.tokens CSubsetParser.cpp CSubsetParser.h CSubsetVisitor.cpp CSubsetVisitor.h CSubsetBaseVisitor.cpp CSubsetBaseVisitor.h

rm -rf output
rm -f ../io/code.asm ../io/optimized_code.asm ../io/code ../io/optimized_code
