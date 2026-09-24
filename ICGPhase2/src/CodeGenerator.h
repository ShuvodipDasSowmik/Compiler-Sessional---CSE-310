#pragma once

#include <bits/stdc++.h>
using namespace std;

#include "CSubsetBaseVisitor.h"
#include "headers/2205150_SymbolTable.hpp"

using namespace antlr4;

class CodeGenerator : public CSubsetBaseVisitor{
private:
    SymbolTable symbol_table;
    vector<string> global_names;
    ostringstream code_out;

    bool in_function = false;
    string current_function_name;
    bool current_function_is_main = false;
    int current_function_param_bytes = 0;
    int label_counter = 0;
    int next_local_offset = -4;

    void emit(const string &instruction);
    void emitLabel(const string &label);
    void emitBlank();
    void emitSourceLine(ParserRuleContext *ctx, const string &description);
    void declareGlobal(const string &name, bool is_array = false, int array_size = 0);
    void declareLocal(const string &name, bool is_array = false, int array_size = 0);
    string operandFor(SymbolInfo *symbol);
    string arrayElementOperand(SymbolInfo *symbol, CSubsetParser::ExpressionContext *indexExpr);
    string resolveVariableOperand(CSubsetParser::VariableContext *ctx);
    int nextLabelIndex();

public:
    void write(ostream &out);

    any visitStartProgram(CSubsetParser::StartProgramContext *ctx) override;
    any visitProgramSingleUnit(CSubsetParser::ProgramSingleUnitContext *ctx) override;
    any visitProgramMultipleUnits(CSubsetParser::ProgramMultipleUnitsContext *ctx) override;
    any visitUnitVariableDeclaration(CSubsetParser::UnitVariableDeclarationContext *ctx) override;
    any visitUnitFunctionDefinition(CSubsetParser::UnitFunctionDefinitionContext *ctx) override;

    any visitFunctionDefinitionWithoutParameters(CSubsetParser::FunctionDefinitionWithoutParametersContext *ctx) override;
    any visitFunctionDefinitionWithParameters(CSubsetParser::FunctionDefinitionWithParametersContext *ctx) override;

    any visitParameterSingleNamed(CSubsetParser::ParameterSingleNamedContext *ctx) override;
    any visitParameterSingleUnnamed(CSubsetParser::ParameterSingleUnnamedContext *ctx) override;
    any visitParameterAppendNamed(CSubsetParser::ParameterAppendNamedContext *ctx) override;
    any visitParameterAppendUnnamed(CSubsetParser::ParameterAppendUnnamedContext *ctx) override;

    any visitCompoundWithStatements(CSubsetParser::CompoundWithStatementsContext *ctx) override;
    any visitEmptyCompound(CSubsetParser::EmptyCompoundContext *ctx) override;

    any visitVariableDeclaration(CSubsetParser::VariableDeclarationContext *ctx) override;
    any visitDeclarationSingleScalar(CSubsetParser::DeclarationSingleScalarContext *ctx) override;
    any visitDeclarationAppendScalar(CSubsetParser::DeclarationAppendScalarContext *ctx) override;
    any visitDeclarationSingleArray(CSubsetParser::DeclarationSingleArrayContext *ctx) override;
    any visitDeclarationAppendArray(CSubsetParser::DeclarationAppendArrayContext *ctx) override;

    any visitStatementsSingle(CSubsetParser::StatementsSingleContext *ctx) override;
    any visitStatementsAppend(CSubsetParser::StatementsAppendContext *ctx) override;
    any visitStatementVariableDeclaration(CSubsetParser::StatementVariableDeclarationContext *ctx) override;
    any visitStatementExpression(CSubsetParser::StatementExpressionContext *ctx) override;
    any visitStatementCompound(CSubsetParser::StatementCompoundContext *ctx) override;
    any visitPrintlnStatement(CSubsetParser::PrintlnStatementContext *ctx) override;
    any visitReturnStatement(CSubsetParser::ReturnStatementContext *ctx) override;
    any visitIfStatement(CSubsetParser::IfStatementContext *ctx) override;
    any visitWhileStatement(CSubsetParser::WhileStatementContext *ctx) override;
    any visitForStatement(CSubsetParser::ForStatementContext *ctx) override;

    any visitEmptyExpressionStatement(CSubsetParser::EmptyExpressionStatementContext *ctx) override;
    any visitExpressionStatementWithExpression(CSubsetParser::ExpressionStatementWithExpressionContext *ctx) override;

    any visitLogicOnlyExpression(CSubsetParser::LogicOnlyExpressionContext *ctx) override;
    any visitAssignmentExpression(CSubsetParser::AssignmentExpressionContext *ctx) override;

    any visitRelOnlyLogicExpression(CSubsetParser::RelOnlyLogicExpressionContext *ctx) override;
    any visitBinaryLogicExpression(CSubsetParser::BinaryLogicExpressionContext *ctx) override;

    any visitSimpleOnlyRelExpression(CSubsetParser::SimpleOnlyRelExpressionContext *ctx) override;
    any visitBinaryRelExpression(CSubsetParser::BinaryRelExpressionContext *ctx) override;

    any visitTermOnlySimpleExpression(CSubsetParser::TermOnlySimpleExpressionContext *ctx) override;
    any visitAdditiveExpression(CSubsetParser::AdditiveExpressionContext *ctx) override;

    any visitUnaryOnlyTerm(CSubsetParser::UnaryOnlyTermContext *ctx) override;
    any visitMultiplicativeTerm(CSubsetParser::MultiplicativeTermContext *ctx) override;

    any visitSignedUnary(CSubsetParser::SignedUnaryContext *ctx) override;
    any visitNotUnary(CSubsetParser::NotUnaryContext *ctx) override;
    any visitFactorUnary(CSubsetParser::FactorUnaryContext *ctx) override;

    any visitVariableFactor(CSubsetParser::VariableFactorContext *ctx) override;
    any visitParenthesizedFactor(CSubsetParser::ParenthesizedFactorContext *ctx) override;
    any visitIntegerConstantFactor(CSubsetParser::IntegerConstantFactorContext *ctx) override;
    any visitFloatConstantFactor(CSubsetParser::FloatConstantFactorContext *ctx) override;
    any visitPostIncrementFactor(CSubsetParser::PostIncrementFactorContext *ctx) override;
    any visitPostDecrementFactor(CSubsetParser::PostDecrementFactorContext *ctx) override;
    any visitFunctionCallFactor(CSubsetParser::FunctionCallFactorContext *ctx) override;

    any visitArgumentSingle(CSubsetParser::ArgumentSingleContext *ctx) override;
    any visitArgumentAppend(CSubsetParser::ArgumentAppendContext *ctx) override;
};
