#include "CSubset.h"

CSubset::CSubset(ofstream &log_file, ofstream &error_file, int &error_count) : symbol_table(30, 1), log_file(log_file), error_file(error_file), error_count(error_count){}

void CSubset::logRule(ParserRuleContext *ctx, const string &production, const string &text, bool include_text){
    log_file << "Line " << ctx->getStart()->getLine() << ": " << production << "\n\n";

    if (include_text){
        log_file << text << "\n\n";
    }
}

void CSubset::reportError(size_t line, const string &message){
    error_count++;
    string output = "Error at line " + to_string(line) + ": " + message;
    log_file << output << "\n\n";
    error_file << output << "\n\n";
}

vector<string> CSubset::collectParameterTypes(const vector<ParameterInfo> &parameters){
    vector<string> parameter_types;

    for (const ParameterInfo &parameter : parameters){
        parameter_types.push_back(parameter.type);
    }

    return parameter_types;
}

string CSubset::normalizeFloat(const string &text){
    stringstream stream;
    stream << fixed << setprecision(2) << stod(text);
    return stream.str();
}

string CSubset::visitText(ParseTree *node){
    if (node == nullptr){
        return "";
    }

    any value = visit(node);

    if (string *text = any_cast<string>(&value)){
        return *text;
    }

    return node->getText();
}

ExpressionInfo CSubset::getExpressionInfo(ParseTree *node) const{
    auto iterator = expression_info.find(node);

    if (iterator == expression_info.end()){
        return {};
    }

    return iterator->second;
}

vector<ExpressionInfo> CSubset::getArgumentInfo(ParseTree *node) const{
    auto iterator = argument_info.find(node);

    if (iterator == argument_info.end()){
        return {};
    }

    return iterator->second;
}

// Type cast for numeric types, if either is float, the result is float; otherwise, it's int. If either type is "error", the result is "error".
string CSubset::combinedNumericType(const ExpressionInfo &left, const ExpressionInfo &right) const{
    if (left.type == "error" || right.type == "error"){
        return "error";
    }

    if (left.type == "float" || right.type == "float"){
        return "float";
    }

    return "int";
}


// We cant use void functions in expressions
bool CSubset::reportVoidExpression(size_t line, const ExpressionInfo &left, const ExpressionInfo &right){
    if (!left.contains_void_function && !right.contains_void_function){
        return false;
    }

    reportError(line, "Void function used in expression");
    return true;
}

bool CSubset::reportArrayExpression(size_t line, const ExpressionInfo &left, const ExpressionInfo &right){
    const ExpressionInfo *array = nullptr;

    if (left.is_array){
        array = &left;
    }
    else if (right.is_array){
        array = &right;
    }

    if (array == nullptr){
        return false;
    }

    reportError(line, "Type mismatch, " + array->identifier + " is an array");
    return true;
}


any CSubset::handleFunctionDeclaration(ParserRuleContext *ctx, CSubsetParser::Type_specifierContext *type_ctx, TerminalNode *id, CSubsetParser::Parameter_listContext *parameter_ctx, const string &production){
    string return_type = visitText(type_ctx);
    ParameterListInfo parameter_list;

    if (parameter_ctx != nullptr){
        any parameter_value = visit(parameter_ctx);

        if (ParameterListInfo *parameters = any_cast<ParameterListInfo>(&parameter_value)){
            parameter_list = *parameters;
        }
    }

    string function_name = id->getText();
    size_t line = id->getSymbol()->getLine();
    SymbolInfo *function = symbol_table.lookUpCurrent(function_name);

    if (function != nullptr){
        reportError(line, "Multiple declaration of " + function_name);
    }
    else{
        symbol_table.insert(function_name, "ID", return_type);
        
        function = symbol_table.lookUpCurrent(function_name);
        function->setIsFunction(true);
        function->setFunctionDeclared(true);
        function->setReturnType(return_type);
        function->setParamTypes(collectParameterTypes(parameter_list.parameters));
    }

    symbol_table.enterScope();
    symbol_table.exitScope();
    string text = return_type + " " + function_name + "(" + parameter_list.text + ");";
    logRule(ctx, production, text);
    return text;
}

any CSubset::handleFunctionDefinition(ParserRuleContext *ctx, CSubsetParser::Type_specifierContext *type_ctx, TerminalNode *id, CSubsetParser::Parameter_listContext *parameter_ctx, CSubsetParser::Compound_statementContext *compound_ctx, const string &production){
    string return_type = visitText(type_ctx);
    ParameterListInfo parameter_list;

    if (parameter_ctx != nullptr){
        any parameter_value = visit(parameter_ctx);

        if (ParameterListInfo *parameters = any_cast<ParameterListInfo>(&parameter_value)){
            parameter_list = *parameters;
        }
    }

    string function_name = id->getText();
    size_t line = id->getSymbol()->getLine();
    SymbolInfo *function = symbol_table.lookUpCurrent(function_name);

    if (function == nullptr){
        symbol_table.insert(function_name, "ID", return_type);
        function = symbol_table.lookUpCurrent(function_name);
        function->setIsFunction(true);
        function->setReturnType(return_type);
    }
    else if (!function->getIsFunction()){
        reportError(line, "Multiple declaration of " + function_name);
        function = nullptr;
    }
    else if (function->getFunctionDefined()){
        reportError(line, "Multiple definition of function " + function_name);
    }

    vector<string> parameter_types = collectParameterTypes(parameter_list.parameters);

    if (function != nullptr && function->getFunctionDeclared()){
        if (function->getReturnType() != return_type){
            reportError(line, "Return type mismatch with function declaration in function " + function_name);
        }
        else if (function->getParamTypes().size() != parameter_types.size()){
            reportError(line, "Total number of arguments mismatch with declaration in function " + function_name);
        }
        else{
            for (size_t i = 0; i < parameter_types.size(); i++){
                if (function->getParamTypes()[i] != parameter_types[i]){
                    reportError(line, to_string(i + 1) + "th parameter type mismatch with declaration in function " + function_name);
                    break;
                }
            }
        }
    }

    for (size_t i = 0; i < parameter_list.parameters.size(); i++){
        const ParameterInfo &parameter = parameter_list.parameters[i];

        if (!parameter.has_name){
            reportError(parameter.line, to_string(i + 1) + "th parameter's name not given in function definition of " + function_name);
        }
    }

    if (function != nullptr){
        function->setIsFunction(true);
        function->setFunctionDefined(true);

        if (!function->getFunctionDeclared()){
            function->setReturnType(return_type);
            function->setParamTypes(parameter_types);
        }
    }

    pending_parameters = parameter_list.parameters;
    next_compound_is_function_body = true;
    string compound_text = visitText(compound_ctx);
    string text = return_type + " " + function_name + "(" + parameter_list.text + ")" + compound_text;
    logRule(ctx, production, text);
    return text;
}

any CSubset::handleCompound(ParserRuleContext *ctx, CSubsetParser::StatementsContext *statements_ctx, const string &production){
    symbol_table.enterScope();

    if (next_compound_is_function_body){
        next_compound_is_function_body = false;

        for (const ParameterInfo &parameter : pending_parameters){
            if (!parameter.has_name){
                continue;
            }

            bool inserted = symbol_table.insert(parameter.name, "ID", parameter.type);

            if (!inserted){
                reportError(parameter.line, "Multiple declaration of " + parameter.name + " in parameter");
            }
        }

        pending_parameters.clear();
    }

    string text = "{}";

    if (statements_ctx != nullptr){
        string statements_text = visitText(statements_ctx);
        text = "{\n" + statements_text + "\n}";
    }

    logRule(ctx, production, text);
    log_file << '\n';
    symbol_table.printAllScopeTables(log_file);
    symbol_table.exitScope();
    return text;
}

// Start of the program, visit the program context and log the total lines and errors

any CSubset::visitStartProgram(CSubsetParser::StartProgramContext *ctx){
    string text = visitText(ctx->program());
    logRule(ctx, "start : program", "", false);
    symbol_table.printAllScopeTables(log_file);

    size_t total_lines = ctx->program()->getStop()->getLine();
    log_file << "Total lines: " << total_lines << '\n' << "Total errors: " << error_count << '\n';
    return text;
}

any CSubset::visitProgramSingleUnit(CSubsetParser::ProgramSingleUnitContext *ctx){
    string text = visitText(ctx->unit());
    
    logRule(ctx, "program : unit", text);
    return text;
}

any CSubset::visitProgramMultipleUnits(CSubsetParser::ProgramMultipleUnitsContext *ctx){
    string program_text = visitText(ctx->program());
    string unit_text = visitText(ctx->unit());
    
    string separator = !program_text.empty() && program_text.back() == '}' ? "\n\n" : "\n";
    string text = program_text + separator + unit_text;
    
    log_file << "Line " << ctx->unit()->getStart()->getLine() << ": program : program unit\n\n" << text << "\n\n";
    return text;
}

any CSubset::visitUnitVariableDeclaration(CSubsetParser::UnitVariableDeclarationContext *ctx){
    string text = visitText(ctx->var_declaration());
    
    logRule(ctx, "unit : var_declaration", text);
    return text;
}

any CSubset::visitUnitFunctionDeclaration(CSubsetParser::UnitFunctionDeclarationContext *ctx){
    string text = visitText(ctx->func_declaration());
    
    logRule(ctx, "unit : func_declaration", text);
    return text;
}

any CSubset::visitUnitFunctionDefinition(CSubsetParser::UnitFunctionDefinitionContext *ctx){
    string text = visitText(ctx->func_definition());
    
    logRule(ctx, "unit : func_definition", text);
    return text;
}

any CSubset::visitFunctionDeclarationWithParameters(CSubsetParser::FunctionDeclarationWithParametersContext *ctx){
    return handleFunctionDeclaration(ctx, ctx->type_specifier(), ctx->ID(), ctx->parameter_list(), "func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON");
}

any CSubset::visitFunctionDeclarationWithoutParameters(CSubsetParser::FunctionDeclarationWithoutParametersContext *ctx){
    return handleFunctionDeclaration(ctx, ctx->type_specifier(), ctx->ID(), nullptr, "func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON");
}

any CSubset::visitFunctionDefinitionWithParameters(CSubsetParser::FunctionDefinitionWithParametersContext *ctx){
    return handleFunctionDefinition(ctx, ctx->type_specifier(), ctx->ID(), ctx->parameter_list(), ctx->compound_statement(), "func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement");
}

any CSubset::visitFunctionDefinitionWithoutParameters(CSubsetParser::FunctionDefinitionWithoutParametersContext *ctx){
    return handleFunctionDefinition(ctx, ctx->type_specifier(), ctx->ID(), nullptr, ctx->compound_statement(), "func_definition : type_specifier ID LPAREN RPAREN compound_statement");
}

any CSubset::visitParameterSingleNamed(CSubsetParser::ParameterSingleNamedContext *ctx){
    ParameterInfo parameter;
    parameter.type = visitText(ctx->type_specifier());
    parameter.name = ctx->ID()->getText();
    parameter.has_name = true;
    parameter.line = ctx->ID()->getSymbol()->getLine();
    
    string text = parameter.type + " " + parameter.name;
    
    logRule(ctx, "parameter_list : type_specifier ID", text);
    return ParameterListInfo{text, {parameter}};
}

any CSubset::visitParameterAppendNamed(CSubsetParser::ParameterAppendNamedContext *ctx){
    // Visit child nodes to get the existing parameter list and the new parameter
    ParameterListInfo result = any_cast<ParameterListInfo>(visit(ctx->parameter_list()));
    ParameterInfo parameter;
    parameter.type = visitText(ctx->type_specifier());
    parameter.name = ctx->ID()->getText();
    parameter.has_name = true;
    parameter.line = ctx->ID()->getSymbol()->getLine();
    
    result.parameters.push_back(parameter);
    result.text += "," + parameter.type + " " + parameter.name;
    
    logRule(ctx, "parameter_list : parameter_list COMMA type_specifier ID", result.text);
    return result;
}

any CSubset::visitParameterAppendUnnamed(CSubsetParser::ParameterAppendUnnamedContext *ctx){
    // Visit child nodes to get the existing parameter list and the new parameter
    ParameterListInfo result = any_cast<ParameterListInfo>(visit(ctx->parameter_list()));
    ParameterInfo parameter;
    parameter.type = visitText(ctx->type_specifier());
    parameter.line = ctx->type_specifier()->getStart()->getLine();
    
    result.parameters.push_back(parameter);
    result.text += "," + parameter.type;
    
    logRule(ctx, "parameter_list : parameter_list COMMA type_specifier", result.text);
    return result;
}

any CSubset::visitParameterSingleInvalidName(CSubsetParser::ParameterSingleInvalidNameContext *ctx){
    ParameterInfo parameter;
    parameter.type = visitText(ctx->type_specifier());
    parameter.line = ctx->ADDOP()->getSymbol()->getLine();
    
    reportError(parameter.line, "syntax error, unexpected token(s) '" + ctx->ADDOP()->getText() + "' before ')'");
    logRule(ctx, "parameter_list : type_specifier", parameter.type);
    return ParameterListInfo{parameter.type, {parameter}};
}

any CSubset::visitParameterSingleUnnamed(CSubsetParser::ParameterSingleUnnamedContext *ctx){
    ParameterInfo parameter;
    parameter.type = visitText(ctx->type_specifier());
    parameter.line = ctx->type_specifier()->getStart()->getLine();
    
    logRule(ctx, "parameter_list : type_specifier", parameter.type);
    return ParameterListInfo{parameter.type, {parameter}};
}

any CSubset::visitCompoundWithStatements(CSubsetParser::CompoundWithStatementsContext *ctx){
    return handleCompound(ctx, ctx->statements(), "compound_statement : LCURL statements RCURL");
}

any CSubset::visitEmptyCompound(CSubsetParser::EmptyCompoundContext *ctx){
    return handleCompound(ctx, nullptr, "compound_statement : LCURL RCURL");
}

any CSubset::visitVariableDeclaration(CSubsetParser::VariableDeclarationContext *ctx){
    string data_type = visitText(ctx->type_specifier());
    DeclarationListInfo declaration_list = any_cast<DeclarationListInfo>(visit(ctx->declaration_list()));

    if (data_type == "void"){
        reportError(ctx->getStart()->getLine(), "Variable type cannot be void");
    }

    for (const DeclaratorInfo &declaration : declaration_list.declarations){
        // Since void variables are not allowed, we skip inserting them into the symbol table
        if (data_type == "void"){
            continue;
        }

        bool inserted = symbol_table.insert(declaration.name, "ID", data_type);

        if (!inserted){
            reportError(declaration.line, "Multiple declaration of " + declaration.name);
            continue;
        }

        // SymbolInfo now holds more info of symbol than that of offline 1
        SymbolInfo *symbol = symbol_table.lookUpCurrent(declaration.name);
        symbol->setDataType(data_type);
        symbol->setIsArray(declaration.is_array);
        symbol->setArraySize(declaration.array_size);
        symbol->setIsFunction(false);
    }

    string text = data_type + " " + declaration_list.text + ";";
    logRule(ctx, "var_declaration : type_specifier declaration_list SEMICOLON", text);
    return text;
}

any CSubset::visitIntegerType(CSubsetParser::IntegerTypeContext *ctx){
    string text = ctx->INT()->getText();
    logRule(ctx, "type_specifier : INT", text);
    return text;
}

any CSubset::visitFloatType(CSubsetParser::FloatTypeContext *ctx){
    string text = ctx->FLOAT()->getText();
    logRule(ctx, "type_specifier : FLOAT", text);
    return text;
}

any CSubset::visitVoidType(CSubsetParser::VoidTypeContext *ctx){
    string text = ctx->VOID()->getText();

    logRule(ctx, "type_specifier : VOID", text);
    return text;
}

any CSubset::visitDeclarationAppendArray(CSubsetParser::DeclarationAppendArrayContext *ctx){
    DeclarationListInfo result = any_cast<DeclarationListInfo>(visit(ctx->declaration_list()));

    string declarator_text = ctx->ID()->getText() + "[" + ctx->CONST_INT()->getText() + "]";
    result.text += "," + declarator_text;
    result.declarations.push_back({ctx->ID()->getText(), true, stoi(ctx->CONST_INT()->getText()), ctx->ID()->getSymbol()->getLine()});

    logRule(ctx, "declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD", result.text);
    return result;
}

any CSubset::visitDeclarationAppendScalar(CSubsetParser::DeclarationAppendScalarContext *ctx){
    DeclarationListInfo result = any_cast<DeclarationListInfo>(visit(ctx->declaration_list()));

    result.text += "," + ctx->ID()->getText();
    result.declarations.push_back({ctx->ID()->getText(), false, 0, ctx->ID()->getSymbol()->getLine()});

    logRule(ctx, "declaration_list : declaration_list COMMA ID", result.text);
    return result;
}

any CSubset::visitDeclarationInvalidSeparator(CSubsetParser::DeclarationInvalidSeparatorContext *ctx){
    DeclarationListInfo result = any_cast<DeclarationListInfo>(visit(ctx->declaration_list()));
    
    reportError(ctx->ADDOP()->getSymbol()->getLine(), "syntax error, unexpected token(s) '" + ctx->ADDOP()->getText() + " " + ctx->ID()->getText() + "' in declaration list");
    return result;
}

any CSubset::visitDeclarationSingleScalar(CSubsetParser::DeclarationSingleScalarContext *ctx){
    DeclaratorInfo declaration{ctx->ID()->getText(), false, 0, ctx->ID()->getSymbol()->getLine()};
    
    logRule(ctx, "declaration_list : ID", declaration.name);
    return DeclarationListInfo{declaration.name, {declaration}};
}

any CSubset::visitDeclarationSingleArray(CSubsetParser::DeclarationSingleArrayContext *ctx){
    DeclaratorInfo declaration{ctx->ID()->getText(), true, stoi(ctx->CONST_INT()->getText()), ctx->ID()->getSymbol()->getLine()};
    
    string text = declaration.name + "[" + ctx->CONST_INT()->getText() + "]";
    
    logRule(ctx, "declaration_list : ID LTHIRD CONST_INT RTHIRD", text);
    return DeclarationListInfo{text, {declaration}};
}

any CSubset::visitStatementsSingle(CSubsetParser::StatementsSingleContext *ctx){
    string text = visitText(ctx->statement());
    
    logRule(ctx, "statements : statement", text);
    return text;
}

any CSubset::visitStatementsAppend(CSubsetParser::StatementsAppendContext *ctx){
    string previous = visitText(ctx->statements());
    string current = visitText(ctx->statement());
    string text = previous + "\n" + current;
    
    log_file << "Line " << ctx->statement()->getStart()->getLine() << ": statements : statements statement\n\n" << text << "\n\n";
    return text;
}

any CSubset::visitStatementVariableDeclaration(CSubsetParser::StatementVariableDeclarationContext *ctx){
    string text = visitText(ctx->var_declaration());
    
    logRule(ctx, "statement : var_declaration", text);
    return text;
}

any CSubset::visitStatementExpression(CSubsetParser::StatementExpressionContext *ctx){
    string text = visitText(ctx->expression_statement());
    
    logRule(ctx, "statement : expression_statement", text);
    return text;
}

any CSubset::visitStatementCompound(CSubsetParser::StatementCompoundContext *ctx){
    string text = visitText(ctx->compound_statement());
    
    logRule(ctx, "statement : compound_statement", text);
    return text;
}

any CSubset::visitForStatement(CSubsetParser::ForStatementContext *ctx){
    string first = visitText(ctx->expression_statement(0));
    string second = visitText(ctx->expression_statement(1));
    string third = visitText(ctx->expression());
    string body = visitText(ctx->statement());
    string text = "for(" + first + second + third + ")" + body;
    
    logRule(ctx, "statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement", text);
    return text;
}

any CSubset::visitIfStatement(CSubsetParser::IfStatementContext *ctx){
    string expression = visitText(ctx->expression());
    string first_statement = visitText(ctx->statement(0));
    string text = "if (" + expression + ")" + first_statement;

    if (ctx->ELSE()){
        string second_statement = visitText(ctx->statement(1));
        text += "\nelse\n" + second_statement;
        logRule(ctx, "statement : IF LPAREN expression RPAREN statement ELSE statement", text);
    }
    else{
        logRule(ctx, "statement : IF LPAREN expression RPAREN statement", text);
    }

    return text;
}

any CSubset::visitWhileStatement(CSubsetParser::WhileStatementContext *ctx){
    string expression = visitText(ctx->expression());
    string body = visitText(ctx->statement());
    string text = "while (" + expression + ")" + body;
    logRule(ctx, "statement : WHILE LPAREN expression RPAREN statement", text);
    return text;
}

any CSubset::visitPrintlnStatement(CSubsetParser::PrintlnStatementContext *ctx){
    string text = "printf(" + ctx->ID()->getText() + ");";

    if (symbol_table.lookUpSymbolInfo(ctx->ID()->getText()) == nullptr){
        reportError(ctx->ID()->getSymbol()->getLine(), "Undeclared variable " + ctx->ID()->getText());
    }

    logRule(ctx, "statement : PRINTLN LPAREN ID RPAREN SEMICOLON", text);
    return text;
}

any CSubset::visitReturnStatement(CSubsetParser::ReturnStatementContext *ctx){
    string expression = visitText(ctx->expression());
    string text = "return " + expression + ";";
    
    logRule(ctx, "statement : RETURN expression SEMICOLON", text);
    return text;
}

any CSubset::visitEmptyExpressionStatement(CSubsetParser::EmptyExpressionStatementContext *ctx){
    string text = ";";
    
    logRule(ctx, "expression_statement : SEMICOLON", text);
    return text;
}

any CSubset::visitExpressionStatementWithExpression(CSubsetParser::ExpressionStatementWithExpressionContext *ctx){
    string expression = visitText(ctx->expression());
    string text = expression + ";";
    
    reportArrayExpression(ctx->getStart()->getLine(), getExpressionInfo(ctx->expression()));
    logRule(ctx, "expression_statement : expression SEMICOLON", text);
    return text;
}

any CSubset::visitInvalidOperandExpressionStatement(CSubsetParser::InvalidOperandExpressionStatementContext *ctx){
    string variable = visitText(ctx->variable());
    string expression = visitText(ctx->simple_expression());
    size_t line = ctx->ASSIGNOP(1)->getSymbol()->getLine();
    string text = variable + "=" + expression;
    
    reportError(line, "syntax error, invalid operand '" + ctx->ASSIGNOP(1)->getText() + "' after '" + ctx->ADDOP()->getText() + "'");
    logRule(ctx, "rel_expression : simple_expression", expression);
    logRule(ctx, "logic_expression : rel_expression", expression);
    logRule(ctx, "expression : variable ASSIGNOP logic_expression", text);
    reportError(line, "syntax error, missing ';' after expression '" + text + "'");
    logRule(ctx, "expression_statement : expression (missing SEMICOLON)", text);
    
    return text;
}

any CSubset::visitMissingSemicolonExpressionStatement(CSubsetParser::MissingSemicolonExpressionStatementContext *ctx){
    string text = visitText(ctx->expression());
    
    reportError(ctx->getStart()->getLine(), "syntax error, missing ';' after expression '" + text + "'");
    logRule(ctx, "expression_statement : expression (missing SEMICOLON)", text);
    return text;
}

any CSubset::visitScalarVariable(CSubsetParser::ScalarVariableContext *ctx){
    string text = ctx->ID()->getText();
    SymbolInfo *symbol = symbol_table.lookUpSymbolInfo(text);
    ExpressionInfo info;
    info.identifier = text;

    // If the symbol is not found or if it is a function, report an error for undeclared variable
    // Otherwise set the type and array status of the variable in the ExpressionInfo
    if (symbol == nullptr || symbol->getIsFunction()){
        reportError(ctx->ID()->getSymbol()->getLine(), "Undeclared variable " + text);
    }
    else{
        info.type = symbol->getDataType();
        info.is_array = symbol->getIsArray();
    }

    expression_info[ctx] = info;
    logRule(ctx, "variable : ID", text);
    return text;
}

any CSubset::visitArrayVariable(CSubsetParser::ArrayVariableContext *ctx){
    string expression = visitText(ctx->expression());
    string text = ctx->ID()->getText() + "[" + expression + "]";
    ExpressionInfo index = getExpressionInfo(ctx->expression());
    ExpressionInfo info;
    info.identifier = ctx->ID()->getText();
    SymbolInfo *symbol = symbol_table.lookUpSymbolInfo(info.identifier);

    if (index.is_array){
        reportError(ctx->RTHIRD()->getSymbol()->getLine(), "Type mismatch, " + index.identifier + " is an array");
    }
    else if (index.type != "int" && index.type != "error"){
        reportError(ctx->RTHIRD()->getSymbol()->getLine(), "Expression inside third brackets not an integer");
    }

    if (symbol == nullptr || symbol->getIsFunction()){
        reportError(ctx->ID()->getSymbol()->getLine(), "Undeclared variable " + info.identifier);
    }
    else{
        info.type = symbol->getDataType();

        if (!symbol->getIsArray()){
            reportError(ctx->RTHIRD()->getSymbol()->getLine(), info.identifier + " not an array");
        }
    }

    expression_info[ctx] = info;
    logRule(ctx, "variable : ID LTHIRD expression RTHIRD", text);
    return text;
}

any CSubset::visitLogicOnlyExpression(CSubsetParser::LogicOnlyExpressionContext *ctx){
    string text = visitText(ctx->logic_expression());
    expression_info[ctx] = getExpressionInfo(ctx->logic_expression());
    
    logRule(ctx, "expression : logic expression", text);
    return text;
}

any CSubset::visitAssignmentExpression(CSubsetParser::AssignmentExpressionContext *ctx){
    string variable = visitText(ctx->variable());
    string expression = visitText(ctx->logic_expression());
    string text = variable + ctx->ASSIGNOP()->getText() + expression;
    ExpressionInfo left = getExpressionInfo(ctx->variable());
    ExpressionInfo right = getExpressionInfo(ctx->logic_expression());

    if (!reportVoidExpression(ctx->ASSIGNOP()->getSymbol()->getLine(), right)){
        if (left.is_array){
            reportError(ctx->ASSIGNOP()->getSymbol()->getLine(), "Type mismatch, " + left.identifier + " is an array");
        }
        else if (right.is_array){
            reportError(ctx->ASSIGNOP()->getSymbol()->getLine(), "Type mismatch, " + right.identifier + " is an array");
        }
        else if (left.type == "int" && right.type == "float"){
            reportError(ctx->ASSIGNOP()->getSymbol()->getLine(), "Type Mismatch");
        }
    }

    ExpressionInfo info = left;
    info.is_array = false;
    info.contains_void_function = false;
    expression_info[ctx] = info;
    logRule(ctx, "expression : variable ASSIGNOP logic_expression", text);
    return text;
}

any CSubset::visitRelOnlyLogicExpression(CSubsetParser::RelOnlyLogicExpressionContext *ctx){
    string text = visitText(ctx->rel_expression());
    expression_info[ctx] = getExpressionInfo(ctx->rel_expression());
    logRule(ctx, "logic_expression : rel_expression", text);
    return text;
}

any CSubset::visitBinaryLogicExpression(CSubsetParser::BinaryLogicExpressionContext *ctx){
    string left = visitText(ctx->rel_expression(0));
    string right = visitText(ctx->rel_expression(1));
    string text = left + ctx->LOGICOP()->getText() + right;
    ExpressionInfo left_info = getExpressionInfo(ctx->rel_expression(0));
    ExpressionInfo right_info = getExpressionInfo(ctx->rel_expression(1));
    
    reportVoidExpression(ctx->LOGICOP()->getSymbol()->getLine(), left_info, right_info);
    reportArrayExpression(ctx->LOGICOP()->getSymbol()->getLine(), left_info, right_info);
    expression_info[ctx] = {"int"};
    
    logRule(ctx, "logic_expression : rel_expression LOGICOP rel_expression", text);
    return text;
}

any CSubset::visitSimpleOnlyRelExpression(CSubsetParser::SimpleOnlyRelExpressionContext *ctx){
    string text = visitText(ctx->simple_expression());
    expression_info[ctx] = getExpressionInfo(ctx->simple_expression());
    
    logRule(ctx, "rel_expression : simple_expression", text);
    return text;
}

any CSubset::visitBinaryRelExpression(CSubsetParser::BinaryRelExpressionContext *ctx){
    string left = visitText(ctx->simple_expression(0));
    string right = visitText(ctx->simple_expression(1));
    string text = left + ctx->RELOP()->getText() + right;
    ExpressionInfo left_info = getExpressionInfo(ctx->simple_expression(0));
    ExpressionInfo right_info = getExpressionInfo(ctx->simple_expression(1));
    
    reportVoidExpression(ctx->RELOP()->getSymbol()->getLine(), left_info, right_info);
    reportArrayExpression(ctx->RELOP()->getSymbol()->getLine(), left_info, right_info);
    expression_info[ctx] = {"int"};
    
    logRule(ctx, "rel_expression : simple_expression RELOP simple_expression", text);
    return text;
}

any CSubset::visitTermOnlySimpleExpression(CSubsetParser::TermOnlySimpleExpressionContext *ctx){
    string text = visitText(ctx->term());
    expression_info[ctx] = getExpressionInfo(ctx->term());
    logRule(ctx, "simple_expression : term", text);
    return text;
}

any CSubset::visitAdditiveExpression(CSubsetParser::AdditiveExpressionContext *ctx){
    string left = visitText(ctx->simple_expression());
    string right = visitText(ctx->term());
    string text = left + ctx->ADDOP()->getText() + right;
    ExpressionInfo left_info = getExpressionInfo(ctx->simple_expression());
    ExpressionInfo right_info = getExpressionInfo(ctx->term());
    
    reportVoidExpression(ctx->ADDOP()->getSymbol()->getLine(), left_info, right_info);
    reportArrayExpression(ctx->ADDOP()->getSymbol()->getLine(), left_info, right_info);
    expression_info[ctx] = {combinedNumericType(left_info, right_info)};
    
    logRule(ctx, "simple_expression : simple_expression ADDOP term", text);
    return text;
}

any CSubset::visitMultiplicativeTerm(CSubsetParser::MultiplicativeTermContext *ctx){
    string left = visitText(ctx->term());
    string right = visitText(ctx->unary_expression());
    string text = left + ctx->MULOP()->getText() + right;
    ExpressionInfo left_info = getExpressionInfo(ctx->term());
    ExpressionInfo right_info = getExpressionInfo(ctx->unary_expression());
    reportVoidExpression(ctx->MULOP()->getSymbol()->getLine(), left_info, right_info);
    reportArrayExpression(ctx->MULOP()->getSymbol()->getLine(), left_info, right_info);
    ExpressionInfo info;
    info.type = combinedNumericType(left_info, right_info);

    if (ctx->MULOP()->getText() == "%"){
        info.type = "int";

        if (left_info.type != "error" && right_info.type != "error" && (left_info.type != "int" || right_info.type != "int")){
            reportError(ctx->MULOP()->getSymbol()->getLine(), "Non-Integer operand on modulus operator");
        }

        if (right_info.is_zero){
            reportError(ctx->MULOP()->getSymbol()->getLine(), "Modulus by Zero");
        }
    }

    expression_info[ctx] = info;
    logRule(ctx, "term : term MULOP unary_expression", text);
    return text;
}

any CSubset::visitUnaryOnlyTerm(CSubsetParser::UnaryOnlyTermContext *ctx){
    string text = visitText(ctx->unary_expression());
    expression_info[ctx] = getExpressionInfo(ctx->unary_expression());
    logRule(ctx, "term : unary_expression", text);
    return text;
}

any CSubset::visitSignedUnary(CSubsetParser::SignedUnaryContext *ctx){
    string expression = visitText(ctx->unary_expression());
    string text = ctx->ADDOP()->getText() + expression;
    ExpressionInfo info = getExpressionInfo(ctx->unary_expression());
    reportVoidExpression(ctx->ADDOP()->getSymbol()->getLine(), info);
    reportArrayExpression(ctx->ADDOP()->getSymbol()->getLine(), info);
    info.is_array = false;
    info.contains_void_function = false;
    expression_info[ctx] = info;
    logRule(ctx, "unary_expression : ADDOP unary_expression", text);
    return text;
}

any CSubset::visitNotUnary(CSubsetParser::NotUnaryContext *ctx){
    string expression = visitText(ctx->unary_expression());
    string text = ctx->NOT()->getText() + expression;
    ExpressionInfo operand = getExpressionInfo(ctx->unary_expression());
    reportVoidExpression(ctx->NOT()->getSymbol()->getLine(), operand);
    reportArrayExpression(ctx->NOT()->getSymbol()->getLine(), operand);
    expression_info[ctx] = {"int"};
    logRule(ctx, "unary_expression : NOT unary expression", text);
    return text;
}

any CSubset::visitFactorUnary(CSubsetParser::FactorUnaryContext *ctx){
    string text = visitText(ctx->factor());
    expression_info[ctx] = getExpressionInfo(ctx->factor());
    logRule(ctx, "unary_expression : factor", text);
    return text;
}

any CSubset::visitVariableFactor(CSubsetParser::VariableFactorContext *ctx){
    string text = visitText(ctx->variable());
    expression_info[ctx] = getExpressionInfo(ctx->variable());
    logRule(ctx, "factor : variable", text);
    return text;
}

any CSubset::visitFunctionCallFactor(CSubsetParser::FunctionCallFactorContext *ctx){
    string arguments = visitText(ctx->argument_list());
    string text = ctx->ID()->getText() + "(" + arguments + ")";
    string function_name = ctx->ID()->getText();
    size_t line = ctx->ID()->getSymbol()->getLine();
    SymbolInfo *function = symbol_table.lookUpSymbolInfo(function_name);
    vector<ExpressionInfo> argument_types = getArgumentInfo(ctx->argument_list());
    ExpressionInfo info;

    if (function == nullptr){
        reportError(line, "Undeclared function " + function_name);
    }
    else if (!function->getIsFunction()){
        reportError(line, function_name + " is not a function");
    }
    else{
        info.type = function->getReturnType();
        info.contains_void_function = info.type == "void";
        const vector<string> &parameters = function->getParamTypes();

        if (parameters.size() != argument_types.size()){
            reportError(line, "Total number of arguments mismatch in function " + function_name);
        }
        else{
            for (size_t i = 0; i < parameters.size(); i++){
                if (argument_types[i].is_array){
                    reportError(line, "Type mismatch, " + argument_types[i].identifier + " is an array");
                    break;
                }

                if (argument_types[i].type != "error" && parameters[i] != argument_types[i].type){
                    reportError(line, to_string(i + 1) + "th argument mismatch in function " + function_name);
                    break;
                }
            }
        }
    }

    expression_info[ctx] = info;
    logRule(ctx, "factor : ID LPAREN argument_list RPAREN", text);
    return text;
}

any CSubset::visitParenthesizedFactor(CSubsetParser::ParenthesizedFactorContext *ctx){
    string expression = visitText(ctx->expression());
    string text = "(" + expression + ")";
    expression_info[ctx] = getExpressionInfo(ctx->expression());
    logRule(ctx, "factor : LPAREN expression RPAREN", text);
    return text;
}

any CSubset::visitIntegerConstantFactor(CSubsetParser::IntegerConstantFactorContext *ctx){
    string text = ctx->CONST_INT()->getText();
    ExpressionInfo info;
    info.type = "int";
    info.is_zero = text == "0";
    expression_info[ctx] = info;
    logRule(ctx, "factor : CONST_INT", text);
    return text;
}

any CSubset::visitFloatConstantFactor(CSubsetParser::FloatConstantFactorContext *ctx){
    string text = normalizeFloat(ctx->CONST_FLOAT()->getText());
    expression_info[ctx] = {"float"};
    logRule(ctx, "factor : CONST_FLOAT", text);
    return text;
}

any CSubset::visitPostIncrementFactor(CSubsetParser::PostIncrementFactorContext *ctx){
    string variable = visitText(ctx->variable());
    string text = variable + ctx->INCOP()->getText();
    ExpressionInfo info = getExpressionInfo(ctx->variable());

    if (info.is_array){
        reportError(ctx->INCOP()->getSymbol()->getLine(), "Type mismatch, " + info.identifier + " is an array");
    }

    info.is_array = false;
    expression_info[ctx] = info;
    logRule(ctx, "factor : variable INCOP", text);
    return text;
}

any CSubset::visitPostDecrementFactor(CSubsetParser::PostDecrementFactorContext *ctx){
    string variable = visitText(ctx->variable());
    string text = variable + ctx->DECOP()->getText();
    ExpressionInfo info = getExpressionInfo(ctx->variable());

    if (info.is_array){
        reportError(ctx->DECOP()->getSymbol()->getLine(), "Type mismatch, " + info.identifier + " is an array");
    }

    info.is_array = false;
    expression_info[ctx] = info;
    logRule(ctx, "factor : variable DECOP", text);
    return text;
}

any CSubset::visitNonEmptyArgumentList(CSubsetParser::NonEmptyArgumentListContext *ctx){
    string text = visitText(ctx->arguments());
    argument_info[ctx] = getArgumentInfo(ctx->arguments());
    logRule(ctx, "argument_list : arguments", text);
    return text;
}

any CSubset::visitEmptyArgumentList(CSubsetParser::EmptyArgumentListContext *ctx){
    string text;
    argument_info[ctx] = {};
    logRule(ctx, "argument_list :", text);
    return text;
}

any CSubset::visitArgumentSingle(CSubsetParser::ArgumentSingleContext *ctx){
    string text = visitText(ctx->logic_expression());
    ExpressionInfo argument = getExpressionInfo(ctx->logic_expression());

    if (reportVoidExpression(ctx->getStart()->getLine(), argument)){
        argument.type = "error";
        argument.contains_void_function = false;
    }

    argument_info[ctx] = {argument};
    logRule(ctx, "arguments : logic_expression", text);
    return text;
}

any CSubset::visitArgumentAppend(CSubsetParser::ArgumentAppendContext *ctx){
    string previous = visitText(ctx->arguments());
    string current = visitText(ctx->logic_expression());
    string text = previous + "," + current;
    vector<ExpressionInfo> arguments = getArgumentInfo(ctx->arguments());
    ExpressionInfo argument = getExpressionInfo(ctx->logic_expression());

    if (reportVoidExpression(ctx->logic_expression()->getStart()->getLine(), argument)){
        argument.type = "error";
        argument.contains_void_function = false;
    }

    arguments.push_back(argument);
    argument_info[ctx] = arguments;
    logRule(ctx, "arguments : arguments COMMA logic_expression", text);
    return text;
}
