%option noyywrap

%{
#include "../headers/2205150_SymbolTable.hpp"
using namespace std;

int lineCount = 1, errorCount = 0;
int bucketNumber = 7;

ofstream tokenOutput;
ofstream logOutput;

SymbolTable* symbolTable = new SymbolTable(bucketNumber);

void logToken(string token, string lexeme, int lineCount){
    logOutput << "Line no " << lineCount << ": Token <" << token << "> Lexeme " << lexeme << " found\n\n";  
}

void logConstantCharToken(string token, string lexeme, string asciiChar, int lineCount){
    logOutput << "Line no " << lineCount << ": Token <" << token << "> Lexeme \'" << lexeme << "\' found --> <CONST_CHAR, " << asciiChar << ">\n\n";
}

void logStringSuccess(string token, string lexeme, string linear, int lineCount){
    logOutput << "Line no " << lineCount << ": Token <" << token << "> Lexeme \"" << lexeme << "\" found --> <STRING, " << linear << ">\n\n";
}

void printKEYWORD(string token, int lineCount){
    string lexeme = token;
    for(auto &c : token) c = toupper(c);
    tokenOutput << "<" << token << "> ";
    logToken(token, lexeme, lineCount);
}

void printOperator(string type, string symbol, int lineCount){
    tokenOutput << "<" << type << ", " << symbol << "> ";
    logToken(type, symbol, lineCount);
}

void printConstant(string type, string symbol, int lineCount) {
    string displaySymbol = symbol;

    if (type == "CONST_CHAR" && symbol.size() == 2 && symbol[0] == '\\') {
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
    else if(type == "CONST_CHAR" && symbol.size() > 2){
        cout << "##ERROR ! Unknown char length found,symbol=" << symbol << "##" << endl;
    }

    if(type == "CONST_CHAR"){
        logConstantCharToken(type, symbol, displaySymbol, lineCount); 
        tokenOutput << "<" << type << ", " << displaySymbol << "> ";
        symbolTable->insert("'" + symbol + "'", type);
    }      
    else{  
        logToken(type, symbol, lineCount);
        tokenOutput << "<" << type << ", " << symbol << "> ";
        symbolTable->insert(symbol, type);
    }    
}

void printIDENTIFIER (string type, string symbol, int lineCount){
    logToken(type, symbol, lineCount);
    tokenOutput << "<" << type << ", " << symbol << "> ";
    symbolTable->insert(symbol, type);
}

%}

WHITESPACE                  [ \t\f\r\v]
ALPHABET                    [a-zA-Z]
DIGIT                       [0-9]
NEWLINE                     "\n"|"\r\n"
KEYWORD                     "if"|"else"|"goto"|"for"|"while"|"long"|"do"|"break"|"short"|"int"|"char"|"static"|"float"|"double"|"unsigned"|"void"|"return"|"switch"|"case"|"default"|"continue"

ADDOP                       "+"|"-"
MULOP                       "*"|"/"|"%"
INCOP                       "++"|"--"
RELOP                       "<"|"<="|">"|">="|"=="|"!="
ASSIGNOP                    "="
LOGICOP                     "&&"|"||"
NOT                         "!"
LPAREN                      "("
RPAREN                      ")"
LCURL                       "{"
RCURL                       "}"
LTHIRD                      "["
RTHIRD                      "]"
COMMA                       ","
SEMICOLON                   ";"

NOT_SBN                     [^'\n\\]
NOT_DBN                     [^"\n\\]
ALPHANUMERIC                ({ALPHABET}|{DIGIT})
CONST_INT                   {DIGIT}+
EXPONENT                    [Ee][+-]?{DIGIT}+
CONST_FLOAT                 ({DIGIT}+\.{DIGIT}*|{DIGIT}*\.{DIGIT}+)({EXPONENT})?|{DIGIT}+{EXPONENT}
SINGLE_QUOTE                "'"
DOUBLE_QUOTE                "\""
ESCAPE_SEQ                  \\[nt\\afrbv0']
CONST_CHAR                  {SINGLE_QUOTE}({NOT_SBN}|{ESCAPE_SEQ}){SINGLE_QUOTE}

UNDER_SCORE                 "_"
IDENTIFIER                  ({ALPHABET}|{UNDER_SCORE})({ALPHANUMERIC}|{UNDER_SCORE})*
STRINGS                     {DOUBLE_QUOTE}({NOT_DBN}|\\(.|\n))*{DOUBLE_QUOTE}

COMMENT_LINE                "//"[^\n]*(\\\n[^\n]*)*
COMMENT_BLOCK               "/*"([^*]|"*"[^*/])*"*"+"/"
COMMENT                     ({COMMENT_LINE})|({COMMENT_BLOCK})

TOO_MANY_DEC                {DIGIT}*\.+[0-9\.]*
ILL_FORMED_NUM              ({DIGIT}*[eE][+-]?{CONST_FLOAT}+)|({DIGIT}*\.+[0-9\.eE+-]*)
EMPTY_CHAR                  {SINGLE_QUOTE}{SINGLE_QUOTE}

INVALID_PREFIX_OR_SUFFIX    ({DIGIT}+[_]?[a-zA-Z]+)
UNTERMINATED_CHAR           ({SINGLE_QUOTE}[^'\n]*\n)|({SINGLE_QUOTE})
OUT_OF_SCOPE_UC             {SINGLE_QUOTE}"\\"{SINGLE_QUOTE}
UNTERMINATED_COMMENT        "/*"([^*]|"*"[^*/])*
UNTERMINATED_STRING         {DOUBLE_QUOTE}([^"\\\n]|\\(.|\n))*
MULTI_CHAR_CONST            {SINGLE_QUOTE}[^'\n]{2,255}{SINGLE_QUOTE}

%%

{WHITESPACE}    { }

{NEWLINE}       { lineCount++; }

{KEYWORD} {
    printKEYWORD(yytext, lineCount);
}

{IDENTIFIER} {
    string lexeme = yytext;
    printIDENTIFIER("ID", lexeme, lineCount);
}

{CONST_FLOAT} {
    string lexeme = yytext;
    printConstant("CONST_FLOAT", lexeme, lineCount);
}

{CONST_INT} {
    string lexeme = yytext;
    printConstant("CONST_INT", lexeme, lineCount);
}

{ADDOP} {
    printOperator("ADDOP", yytext, lineCount);
}

{MULOP} {
    printOperator("MULOP", yytext, lineCount);
}

{INCOP} {
    printOperator("INCOP", yytext, lineCount);
}

{RELOP} {
    printOperator("RELOP", yytext, lineCount);
}

{ASSIGNOP} {
    printOperator("ASSIGNOP", yytext, lineCount);
}

{LOGICOP} {
    printOperator("LOGICOP", yytext, lineCount);
}

{NOT} {
    printOperator("NOT", yytext, lineCount);
}

{LPAREN} {
    printOperator("LPAREN", yytext, lineCount);  
}

{RPAREN} {
    printOperator("RPAREN", yytext, lineCount);
}

{LCURL} {
    printOperator("LCURL", yytext, lineCount);
    symbolTable->enterScope();
}

{RCURL} {
    printOperator("RCURL", yytext, lineCount);
    symbolTable->exitScope();
}

{LTHIRD} {
    printOperator("LTHIRD", yytext, lineCount);
}

{RTHIRD} {
    printOperator("RTHIRD", yytext, lineCount);
}

{SEMICOLON} {
    printOperator("SEMICOLON", yytext, lineCount);
}

{COMMA} {
    printOperator("COMMA", yytext, lineCount);
}

{CONST_CHAR} {
    string lexeme = yytext;  
    string character;

    if (lexeme.length() == 4 && lexeme[1] == '\\') {
        character = lexeme.substr(1, 2);   
        printConstant("CONST_CHAR", character, lineCount);
    } 
    else if (lexeme.length() == 3) {
        character = string(1, lexeme[1]); 
        printConstant("CONST_CHAR", character, lineCount);
    } 
    else {
        cout << "#DEBUG3 .ERROR! checkout the CONST_CHAR" << endl;
    } 
}

{STRINGS} {
    string lexeme = yytext;
    string content = lexeme.substr(1, lexeme.size() - 2);

    string display_content;
    bool escape = false;

    for (char c : content){
        if (escape) {
            if (c == 'n') display_content += '\n';
            else if (c == 't') display_content += '\t';
            else if (c == '\\') display_content += '\\';
            else if (c == '"') display_content += '"';
            else if (c == '\n') continue; 
            else display_content += c;
            escape = false;
        }
        else if (c == '\\'){
            escape = true;
        }
        else{
            display_content += c;
        }
    }

    int newlineCount = 0;
    for (char c : lexeme) {
        if (c == '\n') newlineCount++;
    }

    int stringEndLine = lineCount + newlineCount;

    tokenOutput << "<STRING, " << display_content << "> ";
    logStringSuccess("STRING", content, display_content, stringEndLine);

    lineCount = stringEndLine;
}

    /* ========== COMMENT HANDLING ========== */

{COMMENT} {
    string lexeme = yytext;
    int newlineCount = 0;
    for (char c : lexeme) if (c == '\n') newlineCount++;
    int commentEndLine = lineCount + newlineCount;

    logOutput << "Line no " << commentEndLine << ": Token <COMMENT> Lexeme " << lexeme << " found\n\n";
    lineCount = commentEndLine;
}

{UNTERMINATED_COMMENT} {
    string lexeme = yytext;
    int newlineCount = 0;
    for (char c : lexeme) if (c == '\n') newlineCount++;
    int commentEndLine = lineCount + newlineCount;

    logOutput << "Error at line no " << lineCount << ": Unterminated comment " << lexeme << "\n\n";
    lineCount = commentEndLine;
    errorCount++;
}

    /* ========== ERROR HANDLING ========== */

{UNTERMINATED_STRING} {
    string lexeme = yytext;
    logOutput << "Error at line no " << lineCount << ": Unterminated string " << lexeme << "\n\n";
    errorCount++;
    for (char c : lexeme) if (c == '\n') lineCount++; 
}

{OUT_OF_SCOPE_UC} {
    logOutput << "Error at line no " << lineCount << ": Unterminated character " << yytext << "\n\n\n";
    errorCount++;
}

{UNTERMINATED_CHAR} {
    string lexeme = yytext;
    logOutput << "Error at line no " << lineCount << ": Unterminated character " << lexeme.substr(0, lexeme.length() - 1) << "\n\n\n";
    errorCount++;
    lineCount++;
}

{EMPTY_CHAR} {
    logOutput << "Error at line no " << lineCount << ": Empty character constant error " << yytext << "\n\n\n";
    errorCount++;
}

{MULTI_CHAR_CONST} {
    logOutput << "Error at line no " << lineCount << ": Multi character constant error " << yytext << "\n\n\n";
    errorCount++;
}

{TOO_MANY_DEC} {
    logOutput << "Error at line no " << lineCount << ": Too many decimal points " << yytext << "\n\n\n";
    errorCount++;
}

{ILL_FORMED_NUM} {
    logOutput << "Error at line no " << lineCount << ": Ill formed number " << yytext << "\n\n\n";
    errorCount++;
}

{INVALID_PREFIX_OR_SUFFIX} {
    logOutput << "Error at line no " << lineCount << ": Invalid prefix on ID or invalid suffix on Number " << yytext << "\n\n";
    errorCount++;
}

. {
    logOutput << "Error at line no " << lineCount << ": Unrecognized character " << yytext << "\n\n";
    errorCount++;
}

<<EOF>> {
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
    string studentId = "2205150"; 
    string tokenFileName = "output/"+ studentId + "_token.txt";
    string logFileName = "output/"+ studentId + "_log.txt";

    yyin = fopen(inputFilename.c_str(), "r");

    if (!yyin){
        cerr << "Unable to open input file " << inputFilename << endl;
        return 1;
    }

    tokenOutput.open(tokenFileName);
    logOutput.open(logFileName);

    streambuf *originalCoutBuffer = cout.rdbuf();
    cout.rdbuf(logOutput.rdbuf());

    if (!tokenOutput.is_open()){
        cerr << "Unable to open token output file " << tokenFileName << endl;
        fclose(yyin);
        return 1;
    }

    if (!logOutput.is_open()){
        cerr << "Unable to open log output file " << logFileName << endl;
        fclose(yyin);
        tokenOutput.close();
        return 1;
    }

    yylex();

    fclose(yyin);
    symbolTable->printAllScopeTables();
    
    logOutput << endl;
    logOutput << "Total lines: " << lineCount << endl;
    logOutput << "Total errors: " << errorCount << endl; 

    tokenOutput.close();
    logOutput.close();
    cout.rdbuf(originalCoutBuffer);

    delete symbolTable;
    cout << "Output written to " << tokenFileName << " and " << logFileName << endl;

    return 0;
}