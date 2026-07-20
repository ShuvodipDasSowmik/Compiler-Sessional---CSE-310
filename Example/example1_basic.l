%option noyywrap

%{
#include <iostream>
using namespace std;
%}

KEYWORD    "if"|"else"|"while"|"int"|"float"
IDENTIFIER [a-zA-Z_][a-zA-Z0-9_]*
NUMBER     [0-9]+
WHITESPACE [ \t\n]

%%

{KEYWORD}      { cout << "<KEYWORD, " << yytext << ">" << endl; }
{IDENTIFIER}   { cout << "<ID, " << yytext << ">" << endl; }
{NUMBER}       { cout << "<NUMBER, " << yytext << ">" << endl; }
{WHITESPACE}   { }
.              { cout << "<UNKNOWN, " << yytext << ">" << endl; }

%%

int main() {
  yylex();
  return 0;
}
