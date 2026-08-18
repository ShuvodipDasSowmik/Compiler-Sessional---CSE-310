grammar CSubset;
import Lexer;

start
    : program EOF   # StartProgram
    ;

program
    : program unit  # ProgramMultipleUnits
    | unit  # ProgramSingleUnit
    ;

unit
    : var_declaration   # UnitVariableDeclaration
    | func_declaration  # UnitFunctionDeclaration
    | func_definition   # UnitFunctionDefinition
    ;

func_declaration
    : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON  # FunctionDeclarationWithParameters
    | type_specifier ID LPAREN RPAREN SEMICOLON     # FunctionDeclarationWithoutParameters
    ;

func_definition
    : type_specifier ID LPAREN parameter_list RPAREN compound_statement # FunctionDefinitionWithParameters
    | type_specifier ID LPAREN RPAREN compound_statement    # FunctionDefinitionWithoutParameters
    ;

parameter_list
    : parameter_list COMMA type_specifier ID    # ParameterAppendNamed
    | parameter_list COMMA type_specifier   # ParameterAppendUnnamed
    | type_specifier ID # ParameterSingleNamed
    | type_specifier ADDOP  # ParameterSingleInvalidName
    | type_specifier    # ParameterSingleUnnamed
    ;

compound_statement
    : LCURL statements RCURL    # CompoundWithStatements
    | LCURL RCURL   # EmptyCompound
    ;

var_declaration
    : type_specifier declaration_list SEMICOLON # VariableDeclaration
    ;

type_specifier
    : INT   # IntegerType
    | FLOAT # FloatType
    | VOID  # VoidType
    ;

declaration_list
    : declaration_list COMMA ID # DeclarationAppendScalar
    | declaration_list COMMA ID LTHIRD CONST_INT RTHIRD # DeclarationAppendArray
    | declaration_list ADDOP ID # DeclarationInvalidSeparator
    | ID    # DeclarationSingleScalar
    | ID LTHIRD CONST_INT RTHIRD    # DeclarationSingleArray
    ;

statements
    : statement # StatementsSingle
    | statements statement  # StatementsAppend
    ;

statement
    : var_declaration   # StatementVariableDeclaration
    | expression_statement  # StatementExpression
    | compound_statement    # StatementCompound
    | FOR LPAREN expression_statement expression_statement expression RPAREN statement # ForStatement
    | IF LPAREN expression RPAREN statement (ELSE statement)?   # IfStatement
    | WHILE LPAREN expression RPAREN statement  # WhileStatement
    | PRINTLN LPAREN ID RPAREN SEMICOLON    # PrintlnStatement
    | RETURN expression SEMICOLON   # ReturnStatement
    ;

expression_statement
    : SEMICOLON # EmptyExpressionStatement
    | expression SEMICOLON  # ExpressionStatementWithExpression
    | variable ASSIGNOP simple_expression ADDOP ASSIGNOP    # InvalidOperandExpressionStatement
    | expression    # MissingSemicolonExpressionStatement
    ;

variable
    : ID    # ScalarVariable
    | ID LTHIRD expression RTHIRD   # ArrayVariable
    ;

expression
    : logic_expression  # LogicOnlyExpression
    | variable ASSIGNOP logic_expression    # AssignmentExpression
    ;

logic_expression
    : rel_expression    # RelOnlyLogicExpression
    | rel_expression LOGICOP rel_expression # BinaryLogicExpression
    ;

rel_expression
    : simple_expression # SimpleOnlyRelExpression
    | simple_expression RELOP simple_expression # BinaryRelExpression
    ;

simple_expression
    : term  # TermOnlySimpleExpression
    | simple_expression ADDOP term  # AdditiveExpression
    ;

term
    : unary_expression  # UnaryOnlyTerm
    | term MULOP unary_expression   # MultiplicativeTerm
    ;

unary_expression
    : ADDOP unary_expression    # SignedUnary
    | NOT unary_expression  # NotUnary
    | factor    # FactorUnary
    ;

factor
    : variable  # VariableFactor
    | ID LPAREN argument_list RPAREN    # FunctionCallFactor
    | LPAREN expression RPAREN   # ParenthesizedFactor
    | CONST_INT # IntegerConstantFactor
    | CONST_FLOAT   # FloatConstantFactor
    | variable INCOP    # PostIncrementFactor
    | variable DECOP    # PostDecrementFactor
    ;

argument_list
    : arguments # NonEmptyArgumentList
    |   # EmptyArgumentList
    ;

arguments
    : arguments COMMA logic_expression  # ArgumentAppend
    | logic_expression  # ArgumentSingle
    ;
