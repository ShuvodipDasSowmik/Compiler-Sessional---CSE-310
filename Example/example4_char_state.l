%option noyywrap

%{
#include <iostream>
#include <string>
using namespace std;

string charBuffer = "";
int charStartLine = 1;
int lineCount = 1;
%}

%x CHAR_STATE

KEYWORD    "int"|"char"|"float"
IDENTIFIER [a-zA-Z_][a-zA-Z0-9_]*
WHITESPACE [ \t]
NEWLINE    "\n"

%%

{NEWLINE}      { lineCount++; }
{WHITESPACE}   { }

{KEYWORD}      { cout << "<KEYWORD, " << yytext << ">" << endl; }
{IDENTIFIER}   { cout << "<ID, " << yytext << ">" << endl; }

\'             {
  charBuffer = "";
  charStartLine = lineCount;
  BEGIN(CHAR_STATE);
}

<CHAR_STATE>
{
  \\n          { charBuffer = "\n"; }
  \\t          { charBuffer = "\t"; }
  \\\\         { charBuffer = "\\"; }
  \\\'         { charBuffer = "\'"; }
  
  [^\\\']+     { charBuffer = yytext; }
  
  \'           {
    if (charBuffer.length() == 1) {
      cout << "<CONST_CHAR, " << charBuffer << ">" << endl;
      BEGIN(INITIAL);
    } else if (charBuffer.length() == 0) {
      cout << "ERROR at line " << charStartLine << ": Empty character" << endl;
      BEGIN(INITIAL);
    } else {
      cout << "ERROR at line " << charStartLine << ": Too many characters" << endl;
      BEGIN(INITIAL);
    }
  }
  
  \n           {
    cout << "ERROR at line " << charStartLine << ": Unterminated character" << endl;
    BEGIN(INITIAL);
    lineCount++;
  }
}

.              { cout << "<UNKNOWN>" << endl; }

%%

int main() {
  yylex();
  return 0;
}
