#include "CodeGenerator.h"

static const char *PRINT_INT_PROCEDURE =
"print_number:\n"
"    PUSH EAX\n"
"    PUSH EBX\n"
"    PUSH ECX\n"
"    PUSH EDX\n"
"    PUSH ESI\n"
"    PUSH EDI\n"
"\n"
"    SUB ESP, 32             ; local buffer\n"
"\n"
"    TEST EAX, EAX\n"
"    JNS .positive\n"
"\n"
"    ; print '-'\n"
"    PUSH EAX\n"
"\n"
"    SUB ESP, 1\n"
"    MOV byte [ESP], '-'\n"
"\n"
"    MOV EAX, 4              ; sys_write\n"
"    MOV EBX, 1              ; stdout\n"
"    MOV ECX, ESP\n"
"    MOV EDX, 1\n"
"    INT 0x80\n"
"\n"
"    ADD ESP, 1\n"
"    POP EAX\n"
"\n"
"    NEG EAX\n"
"\n"
".positive:\n"
"    MOV EBX, 10\n"
"\n"
"    LEA ESI, [ESP + 31]\n"
"    MOV byte [ESI], 10\n"
"    DEC ESI\n"
"\n"
".convert:\n"
"    XOR EDX, EDX\n"
"    DIV EBX\n"
"\n"
"    ADD DL, '0'\n"
"    MOV [ESI], DL\n"
"    DEC ESI\n"
"\n"
"    TEST EAX, EAX\n"
"    JNZ .convert\n"
"\n"
"    INC ESI\n"
"\n"
"    LEA EDX, [ESP + 32]\n"
"    SUB EDX, ESI\n"
"\n"
"    MOV EAX, 4              ; sys_write\n"
"    MOV EBX, 1              ; stdout\n"
"    MOV ECX, ESI\n"
"    INT 0x80\n"
"\n"
"    ADD ESP, 32\n"
"\n"
"    POP EDI\n"
"    POP ESI\n"
"    POP EDX\n"
"    POP ECX\n"
"    POP EBX\n"
"    POP EAX\n"
"    RET\n";

void CodeGenerator::emit(const string &instruction){
    code_out << "    " << instruction << "\n";
}

void CodeGenerator::emitLabel(const string &label){
    code_out << label << ":\n";
}

void CodeGenerator::emitBlank(){
    code_out << "\n";
}

void CodeGenerator::emitSourceLine(ParserRuleContext *ctx, const string &description){
    code_out << "    ; Line " << ctx->getStart()->getLine() << ": " << description << "\n";
}

// register the global variable g_{name}
void CodeGenerator::declareGlobal(const string &name, bool is_array, int array_size){
    if (!symbol_table.insert(name, "ID", "int")){
        return;
    }

    SymbolInfo *symbol = symbol_table.lookUpCurrent(name);
    symbol->setIsGlobalVariable(true);
    symbol->setAsmLabel("g_" + name);
    symbol->setIsArray(is_array);
    symbol->setArraySize(array_size);
    global_names.push_back(name);
}

// Has a local offset
void CodeGenerator::declareLocal(const string &name, bool is_array, int array_size){
    if (!symbol_table.insert(name, "ID", "int")){
        return;
    }

    SymbolInfo *symbol = symbol_table.lookUpCurrent(name);
    symbol->setIsGlobalVariable(false);
    symbol->setIsArray(is_array);
    symbol->setArraySize(array_size);
    symbol->setStackOffset(next_local_offset);

    int slots = is_array ? array_size : 1;
    next_local_offset -= 4 * slots;
}

// Generates [EBP +/- offset] for some variable
string CodeGenerator::operandFor(SymbolInfo *symbol){
    if (symbol->getIsGlobalVariable()){
        return "[" + symbol->getAsmLabel() + "]";
    }

    int offset = symbol->getStackOffset();
    string sign = offset >= 0 ? "+" : "";
    return "[EBP" + sign + to_string(offset) + "]";
}

// Evaluates the index expression, then returns an operand string addressing
// element [index] of an int array (global or local).
string CodeGenerator::arrayElementOperand(SymbolInfo *symbol, CSubsetParser::ExpressionContext *indexExpr){
    // Saves the expression result in EAX
    visit(indexExpr);
    emit("MOV EBX, 4");
    emit("IMUL EBX");

    // For global array 
    if (symbol->getIsGlobalVariable()){
        emit("MOV EBX, EAX");
        return "[" + symbol->getAsmLabel() + "+EBX]";
    }

    emit("MOV EBX, " + to_string(symbol->getStackOffset()));
    emit("SUB EBX, EAX");
    return "[EBP+EBX]";
}

string CodeGenerator::resolveVariableOperand(CSubsetParser::VariableContext *ctx){
    if (auto arrayCtx = dynamic_cast<CSubsetParser::ArrayVariableContext *>(ctx)){
        SymbolInfo *symbol = symbol_table.lookUpSymbolInfo(arrayCtx->ID()->getText());
        return arrayElementOperand(symbol, arrayCtx->expression());
    }

    auto scalarCtx = dynamic_cast<CSubsetParser::ScalarVariableContext *>(ctx);
    SymbolInfo *symbol = symbol_table.lookUpSymbolInfo(scalarCtx->ID()->getText());
    return operandFor(symbol);
}

int CodeGenerator::nextLabelIndex(){
    return label_counter++;
}

void CodeGenerator::write(ostream &out){
    out << "format ELF executable 3\n";
    out << "entry main\n\n";

    out << "segment readable writeable\n";

    if (global_names.empty()){
        out << "    ; (no global variables)\n";
    }

    for (const string &name : global_names){
        SymbolInfo *symbol = symbol_table.lookUpCurrent(name);

        if (symbol->getIsArray()){
            out << "    g_" << name << " dd " << symbol->getArraySize()
                << " dup (0)   ; int " << name << "[" << symbol->getArraySize() << "]\n";
        }
        else{
            out << "    g_" << name << " dd 1 dup (0)   ; int " << name << "\n";
        }
    }

    out << "\nsegment readable executable\n";
    out << code_out.str();

    out << "\n; ---- print_number: print EAX as a signed decimal integer, then newline ----\n";
    out << PRINT_INT_PROCEDURE;
}

any CodeGenerator::visitStartProgram(CSubsetParser::StartProgramContext *ctx){
    visit(ctx->program());
    return {};
}

any CodeGenerator::visitProgramSingleUnit(CSubsetParser::ProgramSingleUnitContext *ctx){
    visit(ctx->unit());
    return {};
}

any CodeGenerator::visitProgramMultipleUnits(CSubsetParser::ProgramMultipleUnitsContext *ctx){
    visit(ctx->program());
    visit(ctx->unit());
    return {};
}

any CodeGenerator::visitUnitVariableDeclaration(CSubsetParser::UnitVariableDeclarationContext *ctx){
    visit(ctx->var_declaration());
    return {};
}

any CodeGenerator::visitUnitFunctionDefinition(CSubsetParser::UnitFunctionDefinitionContext *ctx){
    visit(ctx->func_definition());
    return {};
}

any CodeGenerator::visitFunctionDefinitionWithoutParameters(CSubsetParser::FunctionDefinitionWithoutParametersContext *ctx){
    string function_name = ctx->ID()->getText();
    bool is_main = function_name == "main";

    next_local_offset = -4;
    current_function_name = function_name;
    current_function_is_main = is_main;

    emitBlank();
    emitSourceLine(ctx, "function " + function_name + "()");
    emitLabel(function_name);
    
    // Save callers frame pointer
    emit("PUSH EBP");
    emit("MOV  EBP, ESP");

    // VisitVariable refers to this whether current variable is global or local
    bool previous_in_function = in_function;
    in_function = true;
    visit(ctx->compound_statement());
    in_function = previous_in_function;
    // restore previous state

    emitLabel(function_name + "_exit");

    if (is_main){
        // EAX = 1 exit syscall
        emit("MOV EAX, 1");
        // EBX = 0 -> Exit status
        emit("XOR EBX, EBX");
        emit("INT 0x80");
    }

    emit("MOV ESP, EBP");
    emit("POP EBP");
    emit("RET");

    return {};
}

any CodeGenerator::visitFunctionDefinitionWithParameters(CSubsetParser::FunctionDefinitionWithParametersContext *ctx){
    string function_name = ctx->ID()->getText();
    bool is_main = function_name == "main";

    
    vector<pair<string, string>> params =
        any_cast<vector<pair<string, string>>>(visit(ctx->parameter_list()));

    next_local_offset = -4;

    current_function_name = function_name;
    current_function_is_main = is_main;
    // how many bytes does the parameters require 
    current_function_param_bytes = static_cast<int>(params.size()) * 4;

    emitBlank();
    emitSourceLine(ctx, "function " + function_name + "(" + ctx->parameter_list()->getText() + ")");
    emitLabel(function_name);
    emit("PUSH EBP");
    emit("MOV  EBP, ESP");

    // Enter a scope and insert params variables
    symbol_table.enterScope();

    int offset = 8;
    for (const auto &[type, name] : params){
        if (!name.empty()){
            symbol_table.insert(name, "ID", "int");
            SymbolInfo *symbol = symbol_table.lookUpCurrent(name);
            symbol->setIsGlobalVariable(false);
            symbol->setStackOffset(offset);
        }
        offset += 4;
    }

    bool previous_in_function = in_function;
    in_function = true;
    // Enter another scope, so it's now like a nested scope
    visit(ctx->compound_statement());
    in_function = previous_in_function;

    symbol_table.exitScope();

    emitLabel(function_name + "_exit");

    if (is_main){
        emit("MOV EAX, 1");
        emit("XOR EBX, EBX");
        emit("INT 0x80");
    }

    emit("MOV ESP, EBP");
    emit("POP EBP");

    if (!is_main && current_function_param_bytes > 0){
        emit("RET " + to_string(current_function_param_bytes));
    }
    else{
        emit("RET");
    }

    return {};
}

any CodeGenerator::visitParameterSingleNamed(CSubsetParser::ParameterSingleNamedContext *ctx){
    return vector<pair<string, string>>{{"int", ctx->ID()->getText()}};
}

any CodeGenerator::visitParameterSingleUnnamed(CSubsetParser::ParameterSingleUnnamedContext *ctx){
    return vector<pair<string, string>>{{"int", ""}};
}

any CodeGenerator::visitParameterAppendNamed(CSubsetParser::ParameterAppendNamedContext *ctx){
    vector<pair<string, string>> params =
        any_cast<vector<pair<string, string>>>(visit(ctx->parameter_list()));
    params.push_back({"int", ctx->ID()->getText()});
    return params;
}

any CodeGenerator::visitParameterAppendUnnamed(CSubsetParser::ParameterAppendUnnamedContext *ctx){
    vector<pair<string, string>> params =
        any_cast<vector<pair<string, string>>>(visit(ctx->parameter_list()));
    params.push_back({"int", ""});
    return params;
}

any CodeGenerator::visitCompoundWithStatements(CSubsetParser::CompoundWithStatementsContext *ctx){
    symbol_table.enterScope();
    visit(ctx->statements());
    symbol_table.exitScope();
    return {};
}

any CodeGenerator::visitEmptyCompound(CSubsetParser::EmptyCompoundContext *ctx){
    return {};
}

any CodeGenerator::visitVariableDeclaration(CSubsetParser::VariableDeclarationContext *ctx){
    // second = 0 for a scalar, or the array size for an array declaration.
    vector<pair<string, int>> declarations =
        any_cast<vector<pair<string, int>>>(visit(ctx->declaration_list()));

    for (const auto &[name, array_size] : declarations){
        bool is_array = array_size > 0;

        if (in_function){
            declareLocal(name, is_array, array_size);
            int slots = is_array ? array_size : 1;
            emitSourceLine(ctx, "int " + name + (is_array ? "[" + to_string(array_size) + "]" : ""));
            emit("SUB ESP, " + to_string(4 * slots));
        }
        else{
            declareGlobal(name, is_array, array_size);
        }
    }

    return {};
}

any CodeGenerator::visitDeclarationSingleScalar(CSubsetParser::DeclarationSingleScalarContext *ctx){
    return vector<pair<string, int>>{{ctx->ID()->getText(), 0}};
}

any CodeGenerator::visitDeclarationAppendScalar(CSubsetParser::DeclarationAppendScalarContext *ctx){
    vector<pair<string, int>> declarations =
        any_cast<vector<pair<string, int>>>(visit(ctx->declaration_list()));
    declarations.push_back({ctx->ID()->getText(), 0});
    return declarations;
}

any CodeGenerator::visitDeclarationSingleArray(CSubsetParser::DeclarationSingleArrayContext *ctx){
    int array_size = stoi(ctx->CONST_INT()->getText());
    return vector<pair<string, int>>{{ctx->ID()->getText(), array_size}};
}

any CodeGenerator::visitDeclarationAppendArray(CSubsetParser::DeclarationAppendArrayContext *ctx){
    vector<pair<string, int>> declarations =
        any_cast<vector<pair<string, int>>>(visit(ctx->declaration_list()));
    int array_size = stoi(ctx->CONST_INT()->getText());
    declarations.push_back({ctx->ID()->getText(), array_size});
    return declarations;
}

any CodeGenerator::visitStatementsSingle(CSubsetParser::StatementsSingleContext *ctx){
    visit(ctx->statement());
    return {};
}

any CodeGenerator::visitStatementsAppend(CSubsetParser::StatementsAppendContext *ctx){
    visit(ctx->statements());
    visit(ctx->statement());
    return {};
}

any CodeGenerator::visitStatementVariableDeclaration(CSubsetParser::StatementVariableDeclarationContext *ctx){
    visit(ctx->var_declaration());
    return {};
}

any CodeGenerator::visitStatementExpression(CSubsetParser::StatementExpressionContext *ctx){
    visit(ctx->expression_statement());
    return {};
}

any CodeGenerator::visitStatementCompound(CSubsetParser::StatementCompoundContext *ctx){
    visit(ctx->compound_statement());
    return {};
}

any CodeGenerator::visitPrintlnStatement(CSubsetParser::PrintlnStatementContext *ctx){
    string name = ctx->ID()->getText();
    SymbolInfo *symbol = symbol_table.lookUpSymbolInfo(name);

    emitSourceLine(ctx, "printf(" + name + ");");
    emit("MOV EAX, " + operandFor(symbol));
    emit("CALL print_number");
    return {};
}

any CodeGenerator::visitReturnStatement(CSubsetParser::ReturnStatementContext *ctx){
    emitSourceLine(ctx, "return " + ctx->expression()->getText() + ";");
    visit(ctx->expression());
    emit("JMP " + current_function_name + "_exit");
    return {};
}

any CodeGenerator::visitIfStatement(CSubsetParser::IfStatementContext *ctx){
    int index = nextLabelIndex();
    bool has_else = ctx->ELSE() != nullptr;
    string else_label = "L" + to_string(index) + "_if_else";
    string end_label = "L" + to_string(index) + "_if_end";

    emitSourceLine(ctx, "if (" + ctx->expression()->getText() + ")");
    visit(ctx->expression());
    emit("TEST EAX, EAX");
    emit("JE " + (has_else ? else_label : end_label));

    visit(ctx->statement(0));

    if (has_else){
        emit("JMP " + end_label);
        emitLabel(else_label);
        visit(ctx->statement(1));
    }

    emitLabel(end_label);
    return {};
}

any CodeGenerator::visitWhileStatement(CSubsetParser::WhileStatementContext *ctx){
    int index = nextLabelIndex();
    string start_label = "L" + to_string(index) + "_while_start";
    string end_label = "L" + to_string(index) + "_while_end";

    emitLabel(start_label);
    emitSourceLine(ctx, "while (" + ctx->expression()->getText() + ")");
    visit(ctx->expression());
    emit("TEST EAX, EAX");
    emit("JE " + end_label);

    visit(ctx->statement());
    emit("JMP " + start_label);

    emitLabel(end_label);
    return {};
}

any CodeGenerator::visitForStatement(CSubsetParser::ForStatementContext *ctx){
    int index = nextLabelIndex();
    string start_label = "L" + to_string(index) + "_for_start";
    string end_label = "L" + to_string(index) + "_for_end";

    emitSourceLine(ctx, "for (...)");
    visit(ctx->expression_statement(0));

    emitLabel(start_label);

    auto condition = ctx->expression_statement(1);
    
    if (auto withExpr = dynamic_cast<CSubsetParser::ExpressionStatementWithExpressionContext *>(condition)){
        visit(withExpr->expression());
        emit("TEST EAX, EAX");
        emit("JE " + end_label);
    }

    visit(ctx->statement());
    visit(ctx->expression());

    emit("JMP " + start_label);
    emitLabel(end_label);
    return {};
}

any CodeGenerator::visitEmptyExpressionStatement(CSubsetParser::EmptyExpressionStatementContext *ctx){
    return {};
}

any CodeGenerator::visitExpressionStatementWithExpression(CSubsetParser::ExpressionStatementWithExpressionContext *ctx){
    emitSourceLine(ctx, ctx->expression()->getText() + ";");
    visit(ctx->expression());
    return {};
}

any CodeGenerator::visitLogicOnlyExpression(CSubsetParser::LogicOnlyExpressionContext *ctx){
    visit(ctx->logic_expression());
    return {};
}

any CodeGenerator::visitAssignmentExpression(CSubsetParser::AssignmentExpressionContext *ctx){
    visit(ctx->logic_expression());

    emit("PUSH EAX");
    string operand = resolveVariableOperand(ctx->variable());
    emit("POP EAX");

    emit("MOV " + operand + ", EAX");
    return {};
}

any CodeGenerator::visitRelOnlyLogicExpression(CSubsetParser::RelOnlyLogicExpressionContext *ctx){
    visit(ctx->rel_expression());
    return {};
}

any CodeGenerator::visitBinaryLogicExpression(CSubsetParser::BinaryLogicExpressionContext *ctx){
    string op = ctx->LOGICOP()->getText();
    int index = nextLabelIndex();

    if (op == "&&"){
        string false_label = "L" + to_string(index) + "_and_false";
        string true_label = "L" + to_string(index) + "_and_true";
        string end_label = "L" + to_string(index) + "_and_end";

        visit(ctx->rel_expression(0));
        emit("TEST EAX, EAX");
        emit("JE " + false_label);

        visit(ctx->rel_expression(1));
        emit("TEST EAX, EAX");
        emit("JE " + false_label);
        emit("JMP " + true_label);

        emitLabel(false_label);
        emit("MOV EAX, 0");
        emit("JMP " + end_label);

        emitLabel(true_label);
        emit("MOV EAX, 1");

        emitLabel(end_label);
    }
    else{
        string false_label = "L" + to_string(index) + "_or_false";
        string true_label = "L" + to_string(index) + "_or_true";
        string end_label = "L" + to_string(index) + "_or_end";

        visit(ctx->rel_expression(0));
        emit("TEST EAX, EAX");
        emit("JNE " + true_label);

        visit(ctx->rel_expression(1));
        emit("TEST EAX, EAX");
        emit("JNE " + true_label);
        emit("JMP " + false_label);

        emitLabel(true_label);
        emit("MOV EAX, 1");
        emit("JMP " + end_label);

        emitLabel(false_label);
        emit("MOV EAX, 0");

        emitLabel(end_label);
    }

    return {};
}

any CodeGenerator::visitSimpleOnlyRelExpression(CSubsetParser::SimpleOnlyRelExpressionContext *ctx){
    visit(ctx->simple_expression());
    return {};
}

any CodeGenerator::visitBinaryRelExpression(CSubsetParser::BinaryRelExpressionContext *ctx){
    string op = ctx->RELOP()->getText();
    string jump;

    if (op == "<") jump = "JL";
    else if (op == ">") jump = "JG";
    else if (op == "==") jump = "JE";
    else if (op == "!=") jump = "JNE";
    else if (op == "<=") jump = "JLE";
    else jump = "JGE";

    int index = nextLabelIndex();
    string true_label = "L" + to_string(index) + "_true";
    string end_label = "L" + to_string(index) + "_end";

    visit(ctx->simple_expression(1));
    emit("PUSH EAX");
    visit(ctx->simple_expression(0));
    emit("POP EBX");
    emit("CMP EAX, EBX");
    emit(jump + " " + true_label);
    emit("MOV EAX, 0");
    emit("JMP " + end_label);
    emitLabel(true_label);
    emit("MOV EAX, 1");
    emitLabel(end_label);
    return {};
}

any CodeGenerator::visitTermOnlySimpleExpression(CSubsetParser::TermOnlySimpleExpressionContext *ctx){
    visit(ctx->term());
    return {};
}

any CodeGenerator::visitAdditiveExpression(CSubsetParser::AdditiveExpressionContext *ctx){
    string op = ctx->ADDOP()->getText();

    visit(ctx->term());
    emit("PUSH EAX");
    visit(ctx->simple_expression());
    emit("POP EBX");
    emit(op == "+" ? "ADD EAX, EBX" : "SUB EAX, EBX");
    return {};
}

any CodeGenerator::visitUnaryOnlyTerm(CSubsetParser::UnaryOnlyTermContext *ctx){
    visit(ctx->unary_expression());
    return {};
}

any CodeGenerator::visitMultiplicativeTerm(CSubsetParser::MultiplicativeTermContext *ctx){
    string op = ctx->MULOP()->getText();

    visit(ctx->unary_expression());
    emit("PUSH EAX");
    visit(ctx->term());
    emit("POP EBX");

    if (op == "*"){
        emit("IMUL EBX");
    }
    else{
        emit("CDQ");
        emit("IDIV EBX");

        if (op == "%"){
            emit("MOV EAX, EDX");
        }
    }

    return {};
}

any CodeGenerator::visitSignedUnary(CSubsetParser::SignedUnaryContext *ctx){
    string op = ctx->ADDOP()->getText();
    visit(ctx->unary_expression());

    if (op == "-"){
        emit("NEG EAX");
    }

    return {};
}

any CodeGenerator::visitNotUnary(CSubsetParser::NotUnaryContext *ctx){
    int index = nextLabelIndex();
    string true_label = "L" + to_string(index) + "_not_true";
    string end_label = "L" + to_string(index) + "_not_end";

    visit(ctx->unary_expression());
    emit("TEST EAX, EAX");
    emit("JNE " + true_label);
    emit("MOV EAX, 1");
    emit("JMP " + end_label);
    emitLabel(true_label);
    emit("MOV EAX, 0");
    emitLabel(end_label);
    return {};
}

any CodeGenerator::visitFactorUnary(CSubsetParser::FactorUnaryContext *ctx){
    visit(ctx->factor());
    return {};
}

any CodeGenerator::visitVariableFactor(CSubsetParser::VariableFactorContext *ctx){
    string operand = resolveVariableOperand(ctx->variable());
    emit("MOV EAX, " + operand);
    return {};
}

any CodeGenerator::visitParenthesizedFactor(CSubsetParser::ParenthesizedFactorContext *ctx){
    visit(ctx->expression());
    return {};
}

any CodeGenerator::visitIntegerConstantFactor(CSubsetParser::IntegerConstantFactorContext *ctx){
    emit("MOV EAX, " + ctx->CONST_INT()->getText());
    return {};
}

any CodeGenerator::visitFloatConstantFactor(CSubsetParser::FloatConstantFactorContext *ctx){
    int truncated = static_cast<int>(stod(ctx->CONST_FLOAT()->getText()));
    emit("MOV EAX, " + to_string(truncated));
    return {};
}

any CodeGenerator::visitPostIncrementFactor(CSubsetParser::PostIncrementFactorContext *ctx){
    string address = resolveVariableOperand(ctx->variable());

    emit("PUSH dword " + address);
    emit("INC  dword " + address);
    emit("POP  EAX");
    return {};
}

any CodeGenerator::visitPostDecrementFactor(CSubsetParser::PostDecrementFactorContext *ctx){
    string address = resolveVariableOperand(ctx->variable());

    emit("PUSH dword " + address);
    emit("DEC  dword " + address);
    emit("POP  EAX");
    return {};
}

any CodeGenerator::visitFunctionCallFactor(CSubsetParser::FunctionCallFactorContext *ctx){
    string function_name = ctx->ID()->getText();

    vector<CSubsetParser::Logic_expressionContext *> arguments;
    if (auto nonEmpty = dynamic_cast<CSubsetParser::NonEmptyArgumentListContext *>(ctx->argument_list())){
        arguments = any_cast<vector<CSubsetParser::Logic_expressionContext *>>(visit(nonEmpty->arguments()));
    }

    emitSourceLine(ctx, "call " + function_name + "(" + ctx->argument_list()->getText() + ")");

    // Push arguments right-to-left so the leftmost argument ends up at [EBP+8].
    for (auto it = arguments.rbegin(); it != arguments.rend(); ++it){
        visit(*it);
        emit("PUSH EAX");
    }

    emit("CALL " + function_name);
    return {};
}

any CodeGenerator::visitArgumentSingle(CSubsetParser::ArgumentSingleContext *ctx){
    return vector<CSubsetParser::Logic_expressionContext *>{ctx->logic_expression()};
}

any CodeGenerator::visitArgumentAppend(CSubsetParser::ArgumentAppendContext *ctx){
    vector<CSubsetParser::Logic_expressionContext *> arguments =
        any_cast<vector<CSubsetParser::Logic_expressionContext *>>(visit(ctx->arguments()));
    arguments.push_back(ctx->logic_expression());
    return arguments;
}
