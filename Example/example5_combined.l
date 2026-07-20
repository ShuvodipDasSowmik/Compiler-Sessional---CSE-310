%option noyywrap

%{
#include <iostream>
#include <string>
using namespace std;

string buffer = "";
int bufferStartLine = 1;
int lineCount = 1;

void handleEscape(char c) {
  switch(c) {
    case 'n': buffer += '\n'; break;
    case 't': buffer += '\t'; break;
    case '\\': buffer += '\\'; break;
    case '"': buffer += '"'; break;
    case '\'': buffer += '\''; break;
    default: buffer += c;
  }
}
%}

%x STRING_STATE
%x CHAR_STATE
%x COMMENT_STATE

KEYWORD    "if"|"else"|"while"|"int"|"char"|"float"
IDENTIFIER [a-zA-Z_][a-zA-Z0-9_]*
NUMBER     [0-9]+
OPERATOR   "+"|"-"|"*"|"/"|"="
LPAREN     "("
RPAREN     ")"
LBRACE     "{"
RBRACE     "}"
SEMICOLON  ";"
WHITESPACE [ \t]
NEWLINE    "\n"

%%

{NEWLINE}      { lineCount++; }
{WHITESPACE}   { }

{KEYWORD}      { cout << "<KW, " << yytext << ">" << endl; }
{IDENTIFIER}   { cout << "<ID, " << yytext << ">" << endl; }
{NUMBER}       { cout << "<NUM, " << yytext << ">" << endl; }
{OPERATOR}     { cout << "<OP, " << yytext << ">" << endl; }
{LPAREN}       { cout << "<LPAREN>" << endl; }
{RPAREN}       { cout << "<RPAREN>" << endl; }
{LBRACE}       { cout << "<LBRACE>" << endl; }
{RBRACE}       { cout << "<RBRACE>" << endl; }
{SEMICOLON}    { cout << "<SEMICOLON>" << endl; }

\"             {
  buffer = "";
  bufferStartLine = lineCount;
  BEGIN(STRING_STATE);
}

\'             {
  buffer = "";
  bufferStartLine = lineCount;
  BEGIN(CHAR_STATE);
}

"/*"           {
  buffer = "";
  bufferStartLine = lineCount;
  BEGIN(COMMENT_STATE);
}

"//".*         {
  cout << "<COMMENT> at line " << lineCount << endl;
}

<STRING_STATE>
{
  \\[ntr\\"]   { handleEscape(yytext[1]); }
  [^\\\"\n]+   { buffer += yytext; }
  \"           {
    cout << "<STRING, \"" << buffer << "\">" << endl;
    BEGIN(INITIAL);
  }
  \n           {
    cout << "ERROR at line " << bufferStartLine << ": Unterminated string" << endl;
    BEGIN(INITIAL);
    lineCount++;
  }
}

<CHAR_STATE>
{
  \\[ntr\\']   { handleEscape(yytext[1]); }
  [^\\'\n]     { buffer = yytext; }
  \'           {
    if (buffer.length() == 1) {
      cout << "<CHAR, " << buffer << ">" << endl;
    } else if (buffer.length() == 0) {
      cout << "ERROR at line " << bufferStartLine << ": Empty char" << endl;
    } else {
      cout << "ERROR at line " << bufferStartLine << ": Multi-char" << endl;
    }
    BEGIN(INITIAL);
  }
  \n           {
    cout << "ERROR at line " << bufferStartLine << ": Unterminated char" << endl;
    BEGIN(INITIAL);
    lineCount++;
  }
}

<COMMENT_STATE>
{
  "*/"         {
    cout << "<COMMENT> at line " << bufferStartLine << endl;
    BEGIN(INITIAL);
  }
  [^*\n]+      { buffer += yytext; }
  "*"          { buffer += "*"; }
  \n           {
    buffer += '\n';
    lineCount++;
  }
}

.              { cout << "ERROR: Unknown char '" << yytext << "'" << endl; }

%%

int main() {
  yylex();
  return 0;
}
