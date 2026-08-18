#pragma once

#include <bits/stdc++.h>
using namespace std;

#include "CSubsetBaseVisitor.h"
#include "headers/2205150_SymbolTable.hpp"

using namespace antlr4;
using namespace antlr4::tree;

struct DeclaratorInfo{
    string name;
    bool is_array = false;
    int array_size = 0;
    size_t line = 0;
};

struct ParameterInfo{
    string name;
    string type;
    bool has_name = false;
    size_t line = 0;
};

struct DeclarationListInfo{
    string text;
    vector<DeclaratorInfo> declarations;
};

struct ParameterListInfo{
    string text;
    vector<ParameterInfo> parameters;
};

struct ExpressionInfo{
    string type = "error";
    string identifier;
    bool is_array = false;
    bool contains_void_function = false;
    bool is_zero = false;
};

class CSubset : public CSubsetBaseVisitor{
private:
    SymbolTable symbol_table;
    ofstream &log_file;
    ofstream &error_file;
    int &error_count;
    // Flag to indicate if the next compound statement is a function body
    bool next_compound_is_function_body = false;
    // List of parameters for the next function definition
    vector<ParameterInfo> pending_parameters;
    // Map to store expression information for each parse tree node
    unordered_map<const ParseTree *, ExpressionInfo> expression_info;
    // Map to store argument information for each parse tree node
    unordered_map<const ParseTree *, vector<ExpressionInfo>> argument_info;

    void logRule(ParserRuleContext *ctx, const string &production, const string &text = "", bool include_text = true);
    void reportError(size_t line, const string &message);
    vector<string> collectParameterTypes(const vector<ParameterInfo> &parameters);
    // Converts a float literal string to two decimal places (2.5 becomes 2.50)
    string normalizeFloat(const string &text);
    string visitText(ParseTree *node);
    ExpressionInfo getExpressionInfo(ParseTree *node) const;
    vector<ExpressionInfo> getArgumentInfo(ParseTree *node) const;
    string combinedNumericType(const ExpressionInfo &left, const ExpressionInfo &right) const;
    bool reportVoidExpression(size_t line, const ExpressionInfo &left, const ExpressionInfo &right = {});
    bool reportArrayExpression(size_t line, const ExpressionInfo &left, const ExpressionInfo &right = {});
    any handleFunctionDeclaration(ParserRuleContext *ctx, CSubsetParser::Type_specifierContext *type_ctx, TerminalNode *id, CSubsetParser::Parameter_listContext *parameter_ctx, const string &production);
    any handleFunctionDefinition(ParserRuleContext *ctx, CSubsetParser::Type_specifierContext *type_ctx, TerminalNode *id, CSubsetParser::Parameter_listContext *parameter_ctx, CSubsetParser::Compound_statementContext *compound_ctx, const string &production);
    any handleCompound(ParserRuleContext *ctx, CSubsetParser::StatementsContext *statements_ctx, const string &production);

public:
    CSubset(ofstream &log_file, ofstream &error_file, int &error_count);

    any visitStartProgram(CSubsetParser::StartProgramContext *ctx) override;
    any visitProgramSingleUnit(CSubsetParser::ProgramSingleUnitContext *ctx) override;
    any visitProgramMultipleUnits(CSubsetParser::ProgramMultipleUnitsContext *ctx) override;
    any visitUnitVariableDeclaration(CSubsetParser::UnitVariableDeclarationContext *ctx) override;
    any visitUnitFunctionDeclaration(CSubsetParser::UnitFunctionDeclarationContext *ctx) override;
    any visitUnitFunctionDefinition(CSubsetParser::UnitFunctionDefinitionContext *ctx) override;
    any visitFunctionDeclarationWithParameters(CSubsetParser::FunctionDeclarationWithParametersContext *ctx) override;
    any visitFunctionDeclarationWithoutParameters(CSubsetParser::FunctionDeclarationWithoutParametersContext *ctx) override;
    any visitFunctionDefinitionWithParameters(CSubsetParser::FunctionDefinitionWithParametersContext *ctx) override;
    any visitFunctionDefinitionWithoutParameters(CSubsetParser::FunctionDefinitionWithoutParametersContext *ctx) override;
    any visitParameterSingleNamed(CSubsetParser::ParameterSingleNamedContext *ctx) override;
    any visitParameterAppendNamed(CSubsetParser::ParameterAppendNamedContext *ctx) override;
    any visitParameterAppendUnnamed(CSubsetParser::ParameterAppendUnnamedContext *ctx) override;
    any visitParameterSingleInvalidName(CSubsetParser::ParameterSingleInvalidNameContext *ctx) override;
    any visitParameterSingleUnnamed(CSubsetParser::ParameterSingleUnnamedContext *ctx) override;
    any visitCompoundWithStatements(CSubsetParser::CompoundWithStatementsContext *ctx) override;
    any visitEmptyCompound(CSubsetParser::EmptyCompoundContext *ctx) override;
    any visitVariableDeclaration(CSubsetParser::VariableDeclarationContext *ctx) override;
    any visitIntegerType(CSubsetParser::IntegerTypeContext *ctx) override;
    any visitFloatType(CSubsetParser::FloatTypeContext *ctx) override;
    any visitVoidType(CSubsetParser::VoidTypeContext *ctx) override;
    any visitDeclarationAppendArray(CSubsetParser::DeclarationAppendArrayContext *ctx) override;
    any visitDeclarationAppendScalar(CSubsetParser::DeclarationAppendScalarContext *ctx) override;
    any visitDeclarationInvalidSeparator(CSubsetParser::DeclarationInvalidSeparatorContext *ctx) override;
    any visitDeclarationSingleScalar(CSubsetParser::DeclarationSingleScalarContext *ctx) override;
    any visitDeclarationSingleArray(CSubsetParser::DeclarationSingleArrayContext *ctx) override;
    any visitStatementsSingle(CSubsetParser::StatementsSingleContext *ctx) override;
    any visitStatementsAppend(CSubsetParser::StatementsAppendContext *ctx) override;
    any visitStatementVariableDeclaration(CSubsetParser::StatementVariableDeclarationContext *ctx) override;
    any visitStatementExpression(CSubsetParser::StatementExpressionContext *ctx) override;
    any visitStatementCompound(CSubsetParser::StatementCompoundContext *ctx) override;
    any visitForStatement(CSubsetParser::ForStatementContext *ctx) override;
    any visitIfStatement(CSubsetParser::IfStatementContext *ctx) override;
    any visitWhileStatement(CSubsetParser::WhileStatementContext *ctx) override;
    any visitPrintlnStatement(CSubsetParser::PrintlnStatementContext *ctx) override;
    any visitReturnStatement(CSubsetParser::ReturnStatementContext *ctx) override;
    any visitEmptyExpressionStatement(CSubsetParser::EmptyExpressionStatementContext *ctx) override;
    any visitExpressionStatementWithExpression(CSubsetParser::ExpressionStatementWithExpressionContext *ctx) override;
    any visitInvalidOperandExpressionStatement(CSubsetParser::InvalidOperandExpressionStatementContext *ctx) override;
    any visitMissingSemicolonExpressionStatement(CSubsetParser::MissingSemicolonExpressionStatementContext *ctx) override;
    any visitScalarVariable(CSubsetParser::ScalarVariableContext *ctx) override;
    any visitArrayVariable(CSubsetParser::ArrayVariableContext *ctx) override;
    any visitLogicOnlyExpression(CSubsetParser::LogicOnlyExpressionContext *ctx) override;
    any visitAssignmentExpression(CSubsetParser::AssignmentExpressionContext *ctx) override;
    any visitRelOnlyLogicExpression(CSubsetParser::RelOnlyLogicExpressionContext *ctx) override;
    any visitBinaryLogicExpression(CSubsetParser::BinaryLogicExpressionContext *ctx) override;
    any visitSimpleOnlyRelExpression(CSubsetParser::SimpleOnlyRelExpressionContext *ctx) override;
    any visitBinaryRelExpression(CSubsetParser::BinaryRelExpressionContext *ctx) override;
    any visitTermOnlySimpleExpression(CSubsetParser::TermOnlySimpleExpressionContext *ctx) override;
    any visitAdditiveExpression(CSubsetParser::AdditiveExpressionContext *ctx) override;
    any visitMultiplicativeTerm(CSubsetParser::MultiplicativeTermContext *ctx) override;
    any visitUnaryOnlyTerm(CSubsetParser::UnaryOnlyTermContext *ctx) override;
    any visitSignedUnary(CSubsetParser::SignedUnaryContext *ctx) override;
    any visitNotUnary(CSubsetParser::NotUnaryContext *ctx) override;
    any visitFactorUnary(CSubsetParser::FactorUnaryContext *ctx) override;
    any visitVariableFactor(CSubsetParser::VariableFactorContext *ctx) override;
    any visitFunctionCallFactor(CSubsetParser::FunctionCallFactorContext *ctx) override;
    any visitParenthesizedFactor(CSubsetParser::ParenthesizedFactorContext *ctx) override;
    any visitIntegerConstantFactor(CSubsetParser::IntegerConstantFactorContext *ctx) override;
    any visitFloatConstantFactor(CSubsetParser::FloatConstantFactorContext *ctx) override;
    any visitPostIncrementFactor(CSubsetParser::PostIncrementFactorContext *ctx) override;
    any visitPostDecrementFactor(CSubsetParser::PostDecrementFactorContext *ctx) override;
    any visitNonEmptyArgumentList(CSubsetParser::NonEmptyArgumentListContext *ctx) override;
    any visitEmptyArgumentList(CSubsetParser::EmptyArgumentListContext *ctx) override;
    any visitArgumentSingle(CSubsetParser::ArgumentSingleContext *ctx) override;
    any visitArgumentAppend(CSubsetParser::ArgumentAppendContext *ctx) override;
};
