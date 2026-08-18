#include <bits/stdc++.h>
using namespace std;

#include "antlr4-runtime.h"
#include "CSubsetLexer.h"
#include "CSubsetParser.h"
#include "CSubset.h"
#include "SyntaxErrorListener.h"

using namespace antlr4;

ofstream lexLogFile; // used by Lexer.g4's writeIntoLexLogFile()

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

    filesystem::path output_directory = filesystem::path("output") / filesystem::path(argv[1]).stem();
    error_code directory_error;
    filesystem::create_directories(output_directory, directory_error);

    if (directory_error){
        cerr << "Error creating output directory: " << output_directory << endl;
        return 1;
    }

    ofstream log_file(output_directory / "log.txt");
    ofstream error_file(output_directory / "error.txt");
    lexLogFile.open(output_directory / "lexLogFile.txt");

    if (!log_file.is_open() || !error_file.is_open() || !lexLogFile.is_open()){
        cerr << "Error opening output files" << endl;
        return 1;
    }

    int error_count = 0;
    SyntaxErrorListener error_listener(log_file, error_file, error_count);

    ANTLRInputStream input(inputFile);
    CSubsetLexer lexer(&input);

    // remove the default error listener and add our custom error listener
    lexer.removeErrorListeners();
    // lexer.addErrorListener(&error_listener);

    CommonTokenStream tokens(&lexer);
    CSubsetParser parser(&tokens);

    parser.removeErrorListeners();
    // parser.addErrorListener(&error_listener);

    // Pointer to the root of the parse tree
    CSubsetParser::StartContext *tree = parser.start();

    CSubset visitor(log_file, error_file, error_count);

    try{
        // Start visiting the parse tree and perform semantic analysis
        visitor.visit(tree);
    }
    catch (const bad_any_cast &){
        string output = "Error: syntax recovery produced an incomplete parse-tree value";
        log_file << output << "\n\n";
        error_file << output << "\n\n";
    }

    cout << "Parsing completed." << endl;

    inputFile.close();
    return 0;
}
