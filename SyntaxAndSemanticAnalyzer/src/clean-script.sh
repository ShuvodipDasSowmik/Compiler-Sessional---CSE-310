#!/bin/bash

# Enable extended globbing for pattern matching
shopt -s extglob

# Loop through all files that do NOT match *.sh, *.g4, *.cpp, *.h, *.hpp, *.pdf, or compile_commands.json
for file in !(*.sh|*.g4|*.cpp|*.h|*.hpp|*.pdf|compile_commands.json); do
    # Only delete if it's a regular file
    if [[ -f "$file" ]]; then
        rm -f "$file"
    fi
done

# Remove ANTLR-generated lexer, parser, and visitor files
rm -f CSubset.interp CSubset.tokens CSubsetLexer.cpp CSubsetLexer.h CSubsetLexer.interp CSubsetLexer.tokens CSubsetParser.cpp CSubsetParser.h CSubsetVisitor.cpp CSubsetVisitor.h CSubsetBaseVisitor.cpp CSubsetBaseVisitor.h

# Remove the 'output' directory if it exists
rm -rf output
