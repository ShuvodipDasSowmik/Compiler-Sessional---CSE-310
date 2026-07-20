%option noyywrap

%{
#include <iostream>
#include <string>
using namespace std;

string stringBuffer = "";
int stringStartLine = 1;
int lineCount = 1;
%}

%x STRING_STATE

KEYWORD    "if"|"else"|"int"
IDENTIFIER [a-zA-Z_][a-zA-Z0-9_]*
WHITESPACE [ \t]
NEWLINE    "\n"

%%

{NEWLINE}      { lineCount++; }
{WHITESPACE}   { }

{KEYWORD}      { cout << "<KEYWORD, " << yytext << ">" << endl; }
{IDENTIFIER}   { cout << "<ID, " << yytext << ">" << endl; }

\"             {
  stringBuffer = "";
  stringStartLine = lineCount;
  BEGIN(STRING_STATE);
}

<STRING_STATE>
{
  \\n          { stringBuffer += '\n'; }
  \\t          { stringBuffer += '\t'; }
  \\\\         { stringBuffer += '\\'; }
  \\\"         { stringBuffer += '\"'; }
  
  \"           {
    cout << "<STRING, \"" << stringBuffer << "\">" << endl;
    BEGIN(INITIAL);
  }
  
  [^\\\"\n]+   { stringBuffer += yytext; }
  
  \n           {
    cout << "ERROR at line " << stringStartLine << ": Unterminated string" << endl;
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
