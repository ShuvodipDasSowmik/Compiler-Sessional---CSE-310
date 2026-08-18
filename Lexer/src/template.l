%option noyywrap

%x COMMENT

%{

#include <bits/stdc++.h>
using namespace std;



%}

STRING   \"[^\n\"]*\"
WHITESPACE  [ \t\r\f\v]+
VECTOR      "vector<"{"float"|"int"|"double"}">"
NVECTOR     "vector<"

%%

{WHITESPACE} {

}  

"/*" {
    cout << "START" << endl;
    BEGIN(COMMENT);
}

<COMMENT>"*/" {
    cout << "END" << endl << yytext << endl;

    BEGIN(INITIAL);
}

<COMMENT><<EOF>> {
    cout << "Unclosed Comment" << endl;
    yyterminate();
}

<COMMENT>\n {
    cout << "NEWLINE" << endl;
}

<COMMENT>{STRING} {
    cout << "STRING IDENTIFIED" << yytext << endl;
}

<COMMENT>. {
}

{STRING} {
    cout << "STRING IDENTIFIED OUTSIDE COMMENT" << endl;
}


.   {

}

%%

int main(int argc, char* argv[]){
    if (argc > 1) {
        yyin = fopen(argv[1], "r");

        if (yyin == NULL) {
            perror("Cannot open input file");
            return 1;
        }
    }

    yylex();

    if (yyin != stdin)
        fclose(yyin);

    return 0;
}