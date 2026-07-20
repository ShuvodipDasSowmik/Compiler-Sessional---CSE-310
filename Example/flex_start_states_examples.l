/* ============================================================
   EXAMPLE 1: Basic start state for handling strings
   ============================================================ */

%option noyywrap

%{
#include <iostream>
#include <string>
using namespace std;

string currentString = "";
%}

/* Define a start state for inside strings */
%x STRING_STATE

/* Regular patterns (active in INITIAL state) */
KEYWORD    "if"|"else"|"int"|"float"
IDENTIFIER [a-zA-Z_][a-zA-Z0-9_]*
WHITESPACE [ \t\n]

%%

/* Rules in INITIAL state (default) */
{KEYWORD}      { cout << "KEYWORD: " << yytext << endl; }
{IDENTIFIER}   { cout << "ID: " << yytext << endl; }

/* When we encounter a quote, SWITCH to STRING_STATE */
\"             { currentString = ""; BEGIN(STRING_STATE); }

{WHITESPACE}   { /* ignore */ }

/* Rules ONLY active in STRING_STATE */
<STRING_STATE>
{
  /* Any character except quote */
  [^\"]+       { currentString += yytext; }
  
  /* When we hit the closing quote, switch back to INITIAL */
  \"           { 
    cout << "STRING: \"" << currentString << "\"" << endl;
    BEGIN(INITIAL); 
  }
}

%%

int main() {
  yylex();
  return 0;
}


/* ============================================================
   EXAMPLE 2: Multiple start states for strings vs comments
   ============================================================ */

%option noyywrap

%{
#include <iostream>
#include <string>
using namespace std;

string buffer = "";
%}

/* Define two start states */
%x STRING_STATE
%x COMMENT_STATE

KEYWORD    "if"|"else"
IDENTIFIER [a-zA-Z_][a-zA-Z0-9_]*

%%

/* In INITIAL state */
{KEYWORD}      { cout << "KEYWORD: " << yytext << endl; }
{IDENTIFIER}   { cout << "ID: " << yytext << endl; }

/* Enter STRING_STATE when we see " */
\"             { buffer = ""; BEGIN(STRING_STATE); }

/* Enter COMMENT_STATE when we see // */
"//"           { buffer = ""; BEGIN(COMMENT_STATE); }

[ \t\n]        { /* ignore whitespace */ }

/* Rules in STRING_STATE */
<STRING_STATE>
{
  [^\"\n]+     { buffer += yytext; }
  \"           { 
    cout << "STRING: " << buffer << endl;
    BEGIN(INITIAL);  /* Go back to INITIAL */
  }
  \n           { 
    cout << "ERROR: Unterminated string" << endl;
    BEGIN(INITIAL);
  }
}

/* Rules in COMMENT_STATE */
<COMMENT_STATE>
{
  [^\n]+       { buffer += yytext; }
  \n           { 
    cout << "COMMENT: " << buffer << endl;
    BEGIN(INITIAL);  /* Go back to INITIAL */
  }
}

%%

int main() {
  yylex();
  return 0;
}


/* ============================================================
   EXAMPLE 3: Inclusive vs Exclusive start states
   ============================================================ */

%option noyywrap

%{
#include <iostream>
using namespace std;
%}

/* EXCLUSIVE: Only patterns tagged <STRING> can match here */
%x STRING_STATE

/* INCLUSIVE: Patterns without tags can still match here */
%s FLEXIBLE_STATE

KEYWORD "if"|"else"

%%

/* Active in INITIAL state and any inclusive state */
{KEYWORD}      { cout << "KEYWORD: " << yytext << endl; }

/* Exclusive state: ONLY this rule can match */
<STRING_STATE>
{
  \"           { cout << "End string" << endl; BEGIN(INITIAL); }
  [^\"]+       { cout << "String content: " << yytext << endl; }
}

/* Inclusive state: BOTH tagged and untagged rules can match */
<FLEXIBLE_STATE>
{
  [0-9]+       { cout << "NUMBER: " << yytext << endl; }
}

/* Untagged rule: active in INITIAL + all INCLUSIVE states (but not EXCLUSIVE) */
\" { cout << "Start string"; BEGIN(STRING_STATE); }

[0-9]+ { cout << "NUMBER: " << yytext << endl; }

%%

int main() {
  yylex();
  return 0;
}


/* ============================================================
   EXAMPLE 4: Practical example - handling C-style strings with escapes
   ============================================================ */

%option noyywrap

%{
#include <iostream>
#include <string>
using namespace std;

string stringBuffer = "";
int stringStartLine = 1;
%}

%x CSTRING

KEYWORD "int"|"float"|"return"
IDENTIFIER [a-zA-Z_][a-zA-Z0-9_]*

%%

/* Normal patterns in INITIAL */
{KEYWORD}      { cout << "KW: " << yytext << endl; }
{IDENTIFIER}   { cout << "ID: " << yytext << endl; }
[0-9]+         { cout << "NUM: " << yytext << endl; }

/* Start a string */
\"             { 
  stringBuffer = "";
  stringStartLine = 1;  /* Track line where string started */
  BEGIN(CSTRING); 
}

[ \t\n]        { if (yytext[0] == '\n') stringStartLine++; }

/* Inside a C string */
<CSTRING>
{
  /* Escaped characters */
  \\n          { stringBuffer += '\n'; }
  \\t          { stringBuffer += '\t'; }
  \\\\         { stringBuffer += '\\'; }
  \\\"         { stringBuffer += '\"'; }
  
  /* Closing quote */
  \"           { 
    cout << "STRING (line " << stringStartLine << "): \"" 
         << stringBuffer << "\"" << endl;
    BEGIN(INITIAL);
  }
  
  /* Regular characters */
  [^\\\"\n]+   { stringBuffer += yytext; }
  
  /* Newline inside string = error */
  \n           { 
    cout << "ERROR (line " << stringStartLine 
         << "): Unterminated string" << endl;
    BEGIN(INITIAL);
  }
}

.              { cout << "Unknown: " << yytext << endl; }

%%

int main() {
  yylex();
  return 0;
}


/* ============================================================
   HOW TO USE IN YOUR ASSIGNMENT
   ============================================================
   
   For your lexer, you might not NEED start states if you handle
   strings and comments in your main regex patterns (which you do).
   
   BUT if you want to handle NESTED comments or special contexts,
   you could add:

%x COMMENT_STATE

Then in your rules:
   
"/*"           { BEGIN(COMMENT_STATE); }

<COMMENT_STATE>
{
  "*/"         { BEGIN(INITIAL); }
  [^*]+        { /* accumulate */ }
  "*"          { /* handle */ }
}

   This makes multi-line comment parsing more robust!
   ============================================================ */
