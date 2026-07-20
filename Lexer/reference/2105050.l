%option noyywrap

%{
#include <bits/stdc++.h>
#include "headers/2105050_SymbolTable.hpp"
#include "headers/2105050_InputHandler.hpp"
using namespace std;
int lineCount=1,errorCount=0;
ofstream tokenOutput;
ofstream logOutput;
int hash_func=1,buckets=7;
InputHandler *inputHandler = new InputHandler();
SymbolTable *symbolTable = new SymbolTable(buckets, hash_func);

string to_upper(const string& s) {
    string result = s;
    transform(result.begin(), result.end(), result.begin(), ::toupper);
    return result;
}

void logSuccess(string token, string lexeme, int lineCount){
    logOutput << "Line no " << lineCount << ": " << "Token <" << token << "> Lexeme " << lexeme << " found\n\n";  
}

void logConstantCharSuccess(string token, string lexeme, string asciiChar , int lineCount){
    logOutput << "Line no " << lineCount << ": " << "Token <" << token << "> Lexeme \'" << lexeme << "\' found --> <CONST_CHAR, " << asciiChar << ">\n\n";
}

void logStringSuccess(string token, string lexeme,string linear, int lineCount){
 logOutput << "Line no " << lineCount << ": " << "Token <" << token << "> Lexeme \"" << lexeme << "\" found --> <STRING, " << linear << ">\n\n";
}

void printKEYWORD(string token,int lineCount){
    string lexeme = token;
    token =  to_upper(token);
    tokenOutput << "<"<< token << "> " ;
    logSuccess(token, lexeme, lineCount);
    
}

void printOperator(string type, string symbol, int lineCount){
    tokenOutput << "<" <<type<<", "<< symbol << "> ";
    logSuccess(type, symbol, lineCount);
}

void printConstant(string type, string symbol, int lineCount) {
    string displaySymbol = symbol;
    if (type=="CONST_CHAR" && symbol.size() == 2 && symbol[0] == '\\') {
        switch (symbol[1]) {
            case 'n': displaySymbol = "\n"; break;
            case 't': displaySymbol = "\t"; break;
            case '\\': displaySymbol = "\\"; break;
            case 'a': displaySymbol = "\a"; break;
            case 'f': displaySymbol = "\f"; break;
            case 'r': displaySymbol = "\r"; break;
            case 'b': displaySymbol = "\b"; break;
            case 'v': displaySymbol = "\v"; break;
            case '0': displaySymbol = "\0"; break;
            case '\'': displaySymbol = "'"; break;
            default: break; 
        }
    }
    else if(type=="CONST_CHAR" &&  symbol.size() > 2){
        cout << "##ERROR ! Unknown char length found,symbol=" <<symbol<<"##" << endl;
    }
    ///handled now lets print

    if(type=="CONST_CHAR"){
        logConstantCharSuccess(type,symbol, displaySymbol, lineCount); 
        tokenOutput << "<" << type << ", " << displaySymbol << "> ";
        string input = "I \'" + symbol + "\' " + type+"";
        //cout << "##inserting input="<< input << endl;
        inputHandler->inputHandling(symbolTable, input);
    }
        
    else
    {  
        logSuccess(type, symbol, lineCount);
        tokenOutput << "<" << type << ", " << symbol << "> ";
        string input = "I " + symbol + " " + type;
        inputHandler->inputHandling(symbolTable, input);
    }
          
   
    //cout << "DEBUG CONSTANT:##" << symbol << "##" << endl;
    
}

void printIDENTIFIER (string type, string symbol, int lineCount){
    logSuccess(type, symbol, lineCount);
   
    tokenOutput << "<" << type <<", " << symbol <<"> ";
    string input = "I " + symbol +" " +type ;
  // cout << "Input updated=" << input << endl;
   inputHandler->inputHandling(symbolTable, input);
}


// void enterNewScope(){
    
// }

%}


WHITESPACE 		[ \t\f\r\v]
ALPHABET		[a-zA-Z]
DIGIT 			[0-9]
NEWLINE 	    "\n"|"\r\n"
KEYWORD         "if"|"else"|"for"|"while"|"do"|"break"|"continue"|"return"|"int"|"float"|"double"|"char"|"long"|"short"|"unsigned"|"void"|"static"|"switch"|"case"|"default"|"goto"
ADDOP			"+"|"-"
MULOP			"*"|"/"|"%"
INCOP			"++"|"--"
RELOP			"<"|"<="|">"|">="|"=="|"!=" 
ASSIGNOP		"="
LOGICOP			"&&"|"||"
NOT				"!"
LPAREN 			"("
RPAREN			")"
LCURL			"{"
RCURL			"}"
LTHIRD 		    "["
RTHIRD 		    "]"
COMMA 			","
SEMICOLON		";"

ALPHANUMERIC    ({ALPHABET}|{DIGIT})

CONST_INT       {DIGIT}+
EXPONENT        [Ee][+-]?{DIGIT}+
CONST_FLOAT     ({DIGIT}+\.{DIGIT}*|{DIGIT}*\.{DIGIT}+)({EXPONENT})?|{DIGIT}+{EXPONENT}
SINGLE_QUOTE    \'
DOUBLE_QUOTE	\"
ESCAPE_SEQ      \\['nt\\afrbv0]
CONST_CHAR      {SINGLE_QUOTE}([^'\\\n]|{ESCAPE_SEQ}){SINGLE_QUOTE}
UNDER_SCORE     "_"
IDENTIFIER      ({ALPHABET}|{UNDER_SCORE})(({ALPHANUMERIC}|{UNDER_SCORE}))*
STRINGS         {DOUBLE_QUOTE}([^"\\\n]|\\(.|\n))*{DOUBLE_QUOTE}

%%

{WHITESPACE} {}

{NEWLINE} {lineCount++;}


{KEYWORD} {
    printKEYWORD(yytext, lineCount);
}

{IDENTIFIER}    {
    string lexeme =yytext;
    printIDENTIFIER("ID",lexeme,lineCount);

}
{CONST_FLOAT}   {
    string lexeme =yytext;
    printConstant("CONST_FLOAT",lexeme,lineCount);
}

{CONST_INT}     {
     string lexeme =yytext;
    printConstant("CONST_INT",lexeme,lineCount);

}

{CONST_CHAR} {
    string lexeme = yytext;  

    string character;

    //cout << "Found char; lexeme=" << yytext << endl;
    if (lexeme.length() == 4 && lexeme[1] == '\\') {
       
        character = lexeme.substr(1, 2);   
        //shuur hbe index 1 theke with 2 char len
       // cout << "#DEBUG1 character:" << character <<"##"<< endl;
        printConstant("CONST_CHAR", character, lineCount);
    } 
    else if (lexeme.length() == 3) {
        character = string(1, lexeme[1]); 
      //  cout << "#DEBUG2 character:" << character <<"##"<< endl;
       printConstant("CONST_CHAR", character, lineCount);
    } 
    else {
       cout << "#DEBUG3 .ERROR! checkout the CONST_CHAR" << endl;

       //call error function !!
    }

   
}

{STRINGS} {
    string lexeme = yytext;
    string content = lexeme.substr(1, lexeme.size() - 2);

    string display_content;
    bool escape = false;
    for (char c : content) {
        if (escape) {
            if (c == 'n') display_content += '\n';
            else if (c == 't') display_content += '\t';
            else if (c == '\\') display_content += '\\';
            else if (c == '"') display_content += '"';
            else if (c == '\n') continue; 
            else display_content += c;
            escape = false;
        } else if (c == '\\') {
            escape = true;
        } else {
            display_content += c;
        }
    }

    // Count newlines in the lexeme to find where the string ends
    int newlineCount = 0;
    for (char c : lexeme) {
        if (c == '\n') newlineCount++;
    }

    int stringEndLine = lineCount + newlineCount;

    tokenOutput << "<STRING, " << display_content << "> ";
    logStringSuccess("STRING", content, display_content, stringEndLine);

    lineCount = stringEndLine;
}


{ADDOP} {
    printOperator("ADDOP",yytext,lineCount);
}

{MULOP} {
     printOperator("MULOP",yytext,lineCount);
}

{INCOP} {
    printOperator("INCOP",yytext,lineCount);
}

{RELOP} {
     printOperator("RELOP",yytext,lineCount);
}

{ASSIGNOP} {
    printOperator("ASSIGNOP",yytext,lineCount);
}

{LOGICOP} {
    printOperator("LOGICOP",yytext,lineCount);
}


{NOT} {
     printOperator("NOT",yytext,lineCount);
}

{LPAREN} {
   printOperator("LPAREN",yytext,lineCount);
    
}

{RPAREN} {
    printOperator("RPAREN",yytext,lineCount);
   
}

{LCURL} {
    printOperator("LCURL",yytext,lineCount);
    inputHandler->inputHandling(symbolTable, "S");
}

{RCURL} {
    printOperator("RCURL",yytext,lineCount);
     inputHandler->inputHandling(symbolTable, "E");
}

{LTHIRD} {
    printOperator("LTHIRD",yytext,lineCount);
}

{RTHIRD} {
     printOperator("RTHIRD",yytext,lineCount);
}


{SEMICOLON} {
     printOperator("SEMICOLON",yytext,lineCount);
}

{COMMA} {
    printOperator("COMMA",yytext,lineCount);
}

{DOUBLE_QUOTE}([^"\\\n]|\\(.|\n))* {
    string lexeme = yytext;
    logOutput << "Error at line no " << lineCount << ": Unterminated string " << lexeme << "\n\n";
    errorCount++;
    for (char c : lexeme) if (c == '\n') lineCount++; 
   
}


{SINGLE_QUOTE}"\\"{SINGLE_QUOTE} {
    logOutput << "Error at line no " << lineCount << ": Unterminated character " << yytext << "\n\n\n";
    errorCount++;

}

{SINGLE_QUOTE}[^'\n]*\n {
    string lexeme = yytext;
    logOutput << "Error at line no " << lineCount << ": Unterminated character " << lexeme.substr(0, lexeme.length() - 1) << "\n\n\n";
    errorCount++;
    lineCount++;
}
{SINGLE_QUOTE}{SINGLE_QUOTE} {
    logOutput << "Error at line no " << lineCount << ": Empty character constant error " << yytext << "\n\n\n";
    errorCount++;
}
{SINGLE_QUOTE}[^'\n]{2,255}{SINGLE_QUOTE} {
    logOutput << "Error at line no " << lineCount << ": Multi character constant error " << yytext << "\n\n\n";
    errorCount++;
}
{SINGLE_QUOTE} {
    logOutput << "Error at line no " << lineCount << ": Unterminated character " << yytext << "\n\n\n";
    errorCount++;
}

{DIGIT}*\.+[0-9\.]* {
    logOutput << "Error at line no " << lineCount << ": Too many decimal points " << yytext << "\n\n\n";
    
    errorCount++;
}

({DIGIT}*[eE][+-]?{CONST_FLOAT}+)|({DIGIT}*\.+[0-9\.eE+-]*) {
    logOutput << "Error at line no " << lineCount << ": Ill formed number " << yytext << "\n\n\n";
    errorCount++;

}



{DIGIT}+[_]?[a-zA-Z]+ {
    logOutput << "Error at line no " << lineCount << ": Invalid prefix on ID or invalid suffix on Number " << yytext << "\n\n";
    errorCount++;
}



"//"[^\n]*(\\\n[^\n]*)* {
   
    string lexeme = yytext;
    int newlineCount = 0;
    for (char c : lexeme) if (c == '\n') newlineCount++;
    int commentEndLine = lineCount + newlineCount;

    logOutput << "Line no " << commentEndLine << ": Token <COMMENT> Lexeme " << lexeme << " found\n\n";
    lineCount = commentEndLine;
}


"/*"([^*]|"*"[^*/])*"*"+"/" {
  
    string lexeme = yytext;
    int newlineCount = 0;
    for (char c : lexeme) if (c == '\n') newlineCount++;
    int commentEndLine = lineCount + newlineCount;

    logOutput << "Line no " << commentEndLine << ": Token <COMMENT> Lexeme " << lexeme << " found\n\n";
    
    lineCount = commentEndLine;
}

"/*"([^*]|"*"[^*/])*     {
    //logOutput << "Here\n";
    string lexeme = yytext;
    int newlineCount = 0;
    for (char c : lexeme) if (c == '\n') newlineCount++;
    int commentEndLine = lineCount + newlineCount;
    //logOutput << "newlineCount=" << newlineCount <<" ";
    logOutput << "Error at line no " << lineCount << ": Unterminated comment " << lexeme << "\n\n";
    lineCount = commentEndLine;
     errorCount++;
}


. {
    logOutput << "Error at line no " << lineCount << ": Unrecognized character " << yytext << "\n\n";
    errorCount++;
}

<<EOF>> {
    //lineCount++;
    yyterminate();
}


%%

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        cerr << "Usage: " << argv[0] << " Invalid command line parameters" << endl;
        return 1;
    }

    string inputFilename = argv[1];
    string studentId = "2105050"; 
    string tokenFileName = "output/"+ studentId + "_token.txt";
    string logFileName = "output/"+ studentId + "_log.txt";

     yyin = fopen(inputFilename.c_str(), "r");
    if (!yyin)
    {
        cerr << "Unable to open input file " << inputFilename << endl;
        return 1;
    }

    // Open output files
    tokenOutput.open(tokenFileName);
    logOutput.open(logFileName);

    streambuf *originalCoutBuffer = cout.rdbuf();
    cout.rdbuf(logOutput.rdbuf());
    
    if (!tokenOutput.is_open())
    {
        cerr << "Unable to open token output file " << tokenFileName << endl;
        fclose(yyin);
        return 1;
    }
    if (!logOutput.is_open())
    {
        cerr << "Unable to open log output file " << logFileName << endl;
        fclose(yyin);
        tokenOutput.close();
        return 1;
    }

    int hash_func = 1;
    /* if (argc == 4)
    {
        string hashName = argv[3];
        if (hashName == "djb")
        {
            hash_func = 2;
        }
        else if (hashName == "jenkins")
        {
            hash_func = 3;
        }
        else
        {
            hash_func = 1;
        }
    } */

    // Run the lexer
    yylex();

    

    // Close files
    fclose(yyin);
    symbolTable->printAllScopeTable();
    logOutput << "Total lines: " << lineCount << endl;
    logOutput << "Total errors: " << errorCount  <<endl; 


    tokenOutput.close();
    logOutput.close();
    cout.rdbuf(originalCoutBuffer);


    delete symbolTable;
    delete inputHandler;
    cout << "Output written to " << tokenFileName << " and " << logFileName << endl;

    return 0;
}