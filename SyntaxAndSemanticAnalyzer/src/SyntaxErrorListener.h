#pragma once

#include <bits/stdc++.h>
using namespace std;

#include "antlr4-runtime.h"

class SyntaxErrorListener : public antlr4::BaseErrorListener{
private:
    ofstream &log_file;
    ofstream &error_file;
    int &error_count;

public:
    SyntaxErrorListener(ofstream &log_file, ofstream &error_file, int &error_count) : log_file(log_file), error_file(error_file), error_count(error_count){}

    void syntaxError(antlr4::Recognizer *, antlr4::Token *, size_t line, size_t, const string &message, exception_ptr) override{
        error_count++;

        string output = "Error at line " + to_string(line) + ": syntax error, " + message;

        log_file << output << "\n\n";
        error_file << output << "\n\n";
    }
};
