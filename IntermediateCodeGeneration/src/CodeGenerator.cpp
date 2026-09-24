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

void CodeGenerator::declareGlobal(const string &name, bool is_array, int size){
    if (!symbol_table.insert(name, "ID", "int")){
        return;
    }

    SymbolInfo *symbol = symbol_table.lookUpCurrent(name);
    symbol->setIsGlobalVariable(true);
    symbol->setAsmLabel("g_" + name);
    symbol->setIsArray(is_array);
    symbol->setArraySize(size);
    global_names.push_back({name, size});
}

void CodeGenerator::declareLocal(const string &name, bool is_array, int size){
    if (!symbol_table.insert(name, "ID", "int")){
        return;
    }

    SymbolInfo *symbol = symbol_table.lookUpCurrent(name);
    symbol->setIsGlobalVariable(false);
    symbol->setIsArray(is_array);
    symbol->setArraySize(size);

    symbol->setStackOffset(next_local_offset);
    next_local_offset -= 4 * size;
}

void CodeGenerator::declareParameter(const string &name){

    if (!name.empty() && symbol_table.insert(name, "ID", "int")){
        SymbolInfo *symbol = symbol_table.lookUpCurrent(name);
        symbol->setIsGlobalVariable(false);
        symbol->setStackOffset(next_param_offset);
    }

    next_param_offset += 4;
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

int CodeGenerator::nextLabelIndex(){
    return label_counter++;
}


string CodeGenerator::resolveVariableAddress(CSubsetParser::VariableContext *ctx){
    
    if (auto *array_ctx = dynamic_cast<CSubsetParser::ArrayVariableContext *>(ctx)){
        SymbolInfo *symbol = symbol_table.lookUpSymbolInfo(array_ctx->ID()->getText());

        visit(array_ctx->expression());
        emit("SHL EAX, 2");

        if (symbol->getIsGlobalVariable()){
            emit("MOV EBX, EAX");
            return "[" + symbol->getAsmLabel() + "+EBX]";
        }

        emit("NEG EAX");
        emit("MOV EBX, EAX");
        int offset = symbol->getStackOffset();
        string sign = offset >= 0 ? "+" : "";
        return "[EBP+EBX" + sign + to_string(offset) + "]";
    }

    SymbolInfo *symbol = symbol_table.lookUpSymbolInfo(ctx->getText());
    return operandFor(symbol);
}

void CodeGenerator::write(ostream &out){
    out << "format ELF executable 3\n";
    out << "entry main\n\n";

    out << "segment readable writeable\n";

    if (global_names.empty()){
        out << "    ; (no global variables)\n";
    }

    for (const auto &global : global_names){
        out << "    g_" << global.first << " dd " << global.second << " dup (0)   ; int " << global.first << "\n";
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
    string previous_function_name = current_function_name;
    bool previous_function_is_main = current_function_is_main;
    current_function_name = function_name;
    current_function_is_main = is_main;

    emitBlank();
    emitSourceLine(ctx, "function " + function_name + "()");
    emitLabel(function_name);
    emit("PUSH EBP");
    emit("MOV  EBP, ESP");

    if (is_main){
        for (const auto &pending : pending_global_initializers){
            const string &name = pending.first;
            emitSourceLine(ctx, "int " + name + " = ...;");
            visit(pending.second);
            SymbolInfo *symbol = symbol_table.lookUpSymbolInfo(name);
            emit("MOV " + operandFor(symbol) + ", EAX");
        }
    }

    bool previous_in_function = in_function;
    in_function = true;
    visit(ctx->compound_statement());
    in_function = previous_in_function;

    emitLabel(function_name + "_exit");

    if (is_main){
        emit("MOV EAX, 1");
        emit("XOR EBX, EBX");
        emit("INT 0x80");
    }

    emit("MOV ESP, EBP");
    emit("POP EBP");
    emit("RET");

    current_function_name = previous_function_name;
    current_function_is_main = previous_function_is_main;
    return {};
}

any CodeGenerator::visitFunctionDefinitionWithParameters(CSubsetParser::FunctionDefinitionWithParametersContext *ctx){
    string function_name = ctx->ID()->getText();
    bool is_main = function_name == "main";

    next_local_offset = -4;
    next_param_offset = 8;
    string previous_function_name = current_function_name;
    bool previous_function_is_main = current_function_is_main;
    current_function_name = function_name;
    current_function_is_main = is_main;

    emitBlank();
    emitSourceLine(ctx, "function " + function_name + "(...)");
    emitLabel(function_name);
    emit("PUSH EBP");
    emit("MOV  EBP, ESP");

    if (is_main){
        for (const auto &pending : pending_global_initializers){
            const string &name = pending.first;
            emitSourceLine(ctx, "int " + name + " = ...;");
            visit(pending.second);
            SymbolInfo *symbol = symbol_table.lookUpSymbolInfo(name);
            emit("MOV " + operandFor(symbol) + ", EAX");
        }
    }

    symbol_table.enterScope();
    vector<string> param_names = any_cast<vector<string>>(visit(ctx->parameter_list()));

    for (const string &name : param_names){
        declareParameter(name);
    }

    bool previous_in_function = in_function;
    in_function = true;
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
    emit("RET " + to_string(param_names.size() * 4));

    current_function_name = previous_function_name;
    current_function_is_main = previous_function_is_main;
    return {};
}

any CodeGenerator::visitParameterSingleNamed(CSubsetParser::ParameterSingleNamedContext *ctx){
    return vector<string>{ctx->ID()->getText()};
}

any CodeGenerator::visitParameterAppendNamed(CSubsetParser::ParameterAppendNamedContext *ctx){
    vector<string> names = any_cast<vector<string>>(visit(ctx->parameter_list()));
    names.push_back(ctx->ID()->getText());
    return names;
}

any CodeGenerator::visitParameterSingleUnnamed(CSubsetParser::ParameterSingleUnnamedContext *ctx){
    return vector<string>{""};
}

any CodeGenerator::visitParameterAppendUnnamed(CSubsetParser::ParameterAppendUnnamedContext *ctx){
    vector<string> names = any_cast<vector<string>>(visit(ctx->parameter_list()));
    names.push_back("");
    return names;
}

any CodeGenerator::visitCompoundWithStatements(CSubsetParser::CompoundWithStatementsContext *ctx){
    symbol_table.enterScope();
    int scope_entry_offset = next_local_offset;
    visit(ctx->statements());
    int bytes_allocated = scope_entry_offset - next_local_offset;

    if (bytes_allocated > 0){
        emit("ADD ESP, " + to_string(bytes_allocated));
    }

    next_local_offset = scope_entry_offset;
    symbol_table.exitScope();
    return {};
}

any CodeGenerator::visitEmptyCompound(CSubsetParser::EmptyCompoundContext *ctx){
    return {};
}

any CodeGenerator::visitVariableDeclaration(CSubsetParser::VariableDeclarationContext *ctx){
    vector<Declarator> declarators = any_cast<vector<Declarator>>(visit(ctx->declaration_list()));

    for (const Declarator &decl : declarators){
        if (in_function){
            declareLocal(decl.name, decl.is_array, decl.array_size);

            if (decl.is_array){
                emitSourceLine(ctx, "int " + decl.name + "[" + to_string(decl.array_size) + "]");
                emit("SUB ESP, " + to_string(4 * decl.array_size));
            }
            else{
                emitSourceLine(ctx, "int " + decl.name);
                emit("SUB ESP, 4");
            }

            if (decl.initializer != nullptr){
                visit(decl.initializer);
                SymbolInfo *symbol = symbol_table.lookUpSymbolInfo(decl.name);
                emit("MOV " + operandFor(symbol) + ", EAX");
            }
        }
        else{
            declareGlobal(decl.name, decl.is_array, decl.array_size);

            if (decl.initializer != nullptr){
                pending_global_initializers.push_back({decl.name, decl.initializer});
            }
        }
    }

    return {};
}

any CodeGenerator::visitDeclarationSingleScalar(CSubsetParser::DeclarationSingleScalarContext *ctx){
    return vector<Declarator>{Declarator{ctx->ID()->getText(), nullptr}};
}

any CodeGenerator::visitDeclarationAppendScalar(CSubsetParser::DeclarationAppendScalarContext *ctx){
    vector<Declarator> declarators = any_cast<vector<Declarator>>(visit(ctx->declaration_list()));
    declarators.push_back(Declarator{ctx->ID()->getText(), nullptr});
    return declarators;
}

any CodeGenerator::visitDeclarationSingleScalarWithInit(CSubsetParser::DeclarationSingleScalarWithInitContext *ctx){
    return vector<Declarator>{Declarator{ctx->ID()->getText(), ctx->logic_expression()}};
}

any CodeGenerator::visitDeclarationAppendScalarWithInit(CSubsetParser::DeclarationAppendScalarWithInitContext *ctx){
    vector<Declarator> declarators = any_cast<vector<Declarator>>(visit(ctx->declaration_list()));
    declarators.push_back(Declarator{ctx->ID()->getText(), ctx->logic_expression()});
    return declarators;
}

any CodeGenerator::visitDeclarationSingleArray(CSubsetParser::DeclarationSingleArrayContext *ctx){
    Declarator decl;
    decl.name = ctx->ID()->getText();
    decl.is_array = true;
    decl.array_size = stoi(ctx->CONST_INT()->getText());
    return vector<Declarator>{decl};
}

any CodeGenerator::visitDeclarationAppendArray(CSubsetParser::DeclarationAppendArrayContext *ctx){
    vector<Declarator> declarators = any_cast<vector<Declarator>>(visit(ctx->declaration_list()));

    Declarator decl;
    decl.name = ctx->ID()->getText();
    decl.is_array = true;
    decl.array_size = stoi(ctx->CONST_INT()->getText());
    declarators.push_back(decl);
    return declarators;
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
    emitSourceLine(ctx, "printf(....)");
    visit(ctx->print_list());
    return {};
}

any CodeGenerator::visitSinglePrint(CSubsetParser::SinglePrintContext *ctx){
    visit(ctx->logic_expression());
    emit("CALL print_number");
    return {};
}

any CodeGenerator::visitPrintList(CSubsetParser::PrintListContext *ctx){
    visit(ctx->print_list());
    visit(ctx->logic_expression());

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
    string end_label = "L" + to_string(index) + "_if_end";
    bool has_else = ctx->statement(1) != nullptr;

    emitSourceLine(ctx, "if (" + ctx->expression()->getText() + ")");
    visit(ctx->expression());
    emit("TEST EAX, EAX");

    if (has_else){
        string else_label = "L" + to_string(index) + "_if_else";
        emit("JE " + else_label);
        visit(ctx->statement(0));
        emit("JMP " + end_label);
        emitLabel(else_label);
        visit(ctx->statement(1));
    }
    else{
        emit("JE " + end_label);
        visit(ctx->statement(0));
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

    emitSourceLine(ctx, "for (" + ctx->expression_statement(0)->getText() + " " + ctx->expression_statement(1)->getText() + " " + ctx->expression()->getText() + ")");
    visit(ctx->expression_statement(0));

    emitLabel(start_label);

    bool condition_is_empty = dynamic_cast<CSubsetParser::EmptyExpressionStatementContext *>(ctx->expression_statement(1)) != nullptr;

    if (!condition_is_empty){
        visit(ctx->expression_statement(1));
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
    CSubsetParser::VariableContext *variable_ctx = ctx->variable();

    if (dynamic_cast<CSubsetParser::ArrayVariableContext *>(variable_ctx) != nullptr){
        string address = resolveVariableAddress(variable_ctx);
        emit("PUSH EBX");
        visit(ctx->expression());
        emit("POP EBX");
        emit("MOV " + address + ", EAX");
    }
    else{
        visit(ctx->expression());
        SymbolInfo *symbol = symbol_table.lookUpSymbolInfo(variable_ctx->getText());
        emit("MOV " + operandFor(symbol) + ", EAX");
    }

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
        string true_label  = "L" + to_string(index) + "_and_true";
        string end_label   = "L" + to_string(index) + "_and_end";

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
        string true_label  = "L" + to_string(index) + "_or_true";
        string end_label   = "L" + to_string(index) + "_or_end";

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
    string address = resolveVariableAddress(ctx->variable());
    emit("MOV EAX, " + address);
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
    string address = resolveVariableAddress(ctx->variable());

    emit("PUSH dword " + address);
    emit("INC  dword " + address);
    emit("POP  EAX");
    return {};
}

any CodeGenerator::visitPostDecrementFactor(CSubsetParser::PostDecrementFactorContext *ctx){
    string address = resolveVariableAddress(ctx->variable());

    emit("PUSH dword " + address);
    emit("DEC  dword " + address);
    emit("POP  EAX");
    return {};
}

any CodeGenerator::visitFunctionCallFactor(CSubsetParser::FunctionCallFactorContext *ctx){
    string function_name = ctx->ID()->getText();
    vector<CSubsetParser::Logic_expressionContext *> args =
        any_cast<vector<CSubsetParser::Logic_expressionContext *>>(visit(ctx->argument_list()));

    for (auto it = args.rbegin(); it != args.rend(); ++it){
        visit(*it);
        emit("PUSH EAX");
    }

    emit("CALL " + function_name);
    return {};
}

any CodeGenerator::visitNonEmptyArgumentList(CSubsetParser::NonEmptyArgumentListContext *ctx){
    return visit(ctx->arguments());
}

any CodeGenerator::visitEmptyArgumentList(CSubsetParser::EmptyArgumentListContext *ctx){
    return vector<CSubsetParser::Logic_expressionContext *>{};
}

any CodeGenerator::visitArgumentSingle(CSubsetParser::ArgumentSingleContext *ctx){
    return vector<CSubsetParser::Logic_expressionContext *>{ctx->logic_expression()};
}

any CodeGenerator::visitArgumentAppend(CSubsetParser::ArgumentAppendContext *ctx){
    vector<CSubsetParser::Logic_expressionContext *> args =
        any_cast<vector<CSubsetParser::Logic_expressionContext *>>(visit(ctx->arguments()));
    args.push_back(ctx->logic_expression());
    return args;
}
