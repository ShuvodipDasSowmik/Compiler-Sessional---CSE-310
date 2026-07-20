%option noyywrap

%{
#include <iostream>
#include <string>
using namespace std;

string commentBuffer = "";
int commentStartLine = 1;
int lineCount = 1;
%}

%x COMMENT_STATE

KEYWORD    "if"|"else"|"return"
IDENTIFIER [a-zA-Z_][a-zA-Z0-9_]*
NUMBER     [0-9]+
WHITESPACE [ \t]
NEWLINE    "\n"

%%

{NEWLINE}      { lineCount++; }
{WHITESPACE}   { }

{KEYWORD}      { cout << "<KEYWORD, " << yytext << ">" << endl; }
{IDENTIFIER}   { cout << "<ID, " << yytext << ">" << endl; }
{NUMBER}       { cout << "<NUMBER, " << yytext << ">" << endl; }

"/*"           {
  commentBuffer = "";
  commentStartLine = lineCount;
  BEGIN(COMMENT_STATE);
}

<COMMENT_STATE>
{
  "*/"         {
    cout << "<COMMENT> at line " << commentStartLine << endl;
    BEGIN(INITIAL);
  }
  
  [^*\n]+      { commentBuffer += yytext; }
  
  "*"          { commentBuffer += "*"; }
  
  \n           {
    commentBuffer += '\n';
    lineCount++;
  }
}

.              { cout << "<UNKNOWN>" << endl; }

%%

int main() {
  yylex();
  return 0;
}
