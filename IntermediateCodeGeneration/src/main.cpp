#include <bits/stdc++.h>
using namespace std;

#include "antlr4-runtime.h"
#include "CSubsetLexer.h"
#include "CSubsetParser.h"
#include "CodeGenerator.h"
#include "Peephole.h"

using namespace antlr4;

ofstream lexLogFile;

int main(int argc, const char *argv[]){
    if (argc < 2){
        cerr << "Usage: " << argv[0] << " <input_file>" << endl;
        return 1;
    }

    ifstream inputFile(argv[1]);

    if (!inputFile.is_open()){
        cerr << "Error opening input file: " << argv[1] << endl;
        return 1;
    }

    filesystem::path output_directory = "../io";
    filesystem::create_directories(output_directory);

    lexLogFile.open("/dev/null");

    ANTLRInputStream input(inputFile);
    CSubsetLexer lexer(&input);
    lexer.removeErrorListeners();

    CommonTokenStream tokens(&lexer);
    CSubsetParser parser(&tokens);
    parser.removeErrorListeners();

    // Pointer to the root of the parse tree. Input is assumed to be free of
    // syntax/semantic errors (checked in the prior assignment)
    CSubsetParser::StartContext *tree = parser.start();

    CodeGenerator generator;
    generator.visit(tree);

    filesystem::path code_path = output_directory / "code.asm";
    filesystem::path optimized_path = output_directory / "optimized_code.asm";

    ofstream code_file(code_path);
    generator.write(code_file);
    code_file.close();

    Peephole::optimize(code_path.string(), optimized_path.string());

    cout << "Code generation completed." << endl;
    cout << "  " << code_path << endl;
    cout << "  " << optimized_path << endl;

    inputFile.close();
    return 0;
}
