
// Generated from CSubset.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "CSubsetVisitor.h"


/**
 * This class provides an empty implementation of CSubsetVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  CSubsetBaseVisitor : public CSubsetVisitor {
public:

  virtual std::any visitStartProgram(CSubsetParser::StartProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitProgramSingleUnit(CSubsetParser::ProgramSingleUnitContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitProgramMultipleUnits(CSubsetParser::ProgramMultipleUnitsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnitVariableDeclaration(CSubsetParser::UnitVariableDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnitFunctionDeclaration(CSubsetParser::UnitFunctionDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnitFunctionDefinition(CSubsetParser::UnitFunctionDefinitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunctionDeclarationWithParameters(CSubsetParser::FunctionDeclarationWithParametersContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunctionDeclarationWithoutParameters(CSubsetParser::FunctionDeclarationWithoutParametersContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunctionDefinitionWithParameters(CSubsetParser::FunctionDefinitionWithParametersContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunctionDefinitionWithoutParameters(CSubsetParser::FunctionDefinitionWithoutParametersContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParameterSingleNamed(CSubsetParser::ParameterSingleNamedContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParameterSingleInvalidName(CSubsetParser::ParameterSingleInvalidNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParameterAppendNamed(CSubsetParser::ParameterAppendNamedContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParameterAppendUnnamed(CSubsetParser::ParameterAppendUnnamedContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParameterSingleUnnamed(CSubsetParser::ParameterSingleUnnamedContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCompoundWithStatements(CSubsetParser::CompoundWithStatementsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEmptyCompound(CSubsetParser::EmptyCompoundContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVariableDeclaration(CSubsetParser::VariableDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIntegerType(CSubsetParser::IntegerTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFloatType(CSubsetParser::FloatTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVoidType(CSubsetParser::VoidTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDeclarationAppendArray(CSubsetParser::DeclarationAppendArrayContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDeclarationInvalidSeparator(CSubsetParser::DeclarationInvalidSeparatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDeclarationAppendScalar(CSubsetParser::DeclarationAppendScalarContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDeclarationSingleScalar(CSubsetParser::DeclarationSingleScalarContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDeclarationSingleArray(CSubsetParser::DeclarationSingleArrayContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatementsSingle(CSubsetParser::StatementsSingleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatementsAppend(CSubsetParser::StatementsAppendContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatementVariableDeclaration(CSubsetParser::StatementVariableDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatementExpression(CSubsetParser::StatementExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatementCompound(CSubsetParser::StatementCompoundContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitForStatement(CSubsetParser::ForStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIfStatement(CSubsetParser::IfStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitWhileStatement(CSubsetParser::WhileStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPrintlnStatement(CSubsetParser::PrintlnStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitReturnStatement(CSubsetParser::ReturnStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEmptyExpressionStatement(CSubsetParser::EmptyExpressionStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpressionStatementWithExpression(CSubsetParser::ExpressionStatementWithExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInvalidOperandExpressionStatement(CSubsetParser::InvalidOperandExpressionStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMissingSemicolonExpressionStatement(CSubsetParser::MissingSemicolonExpressionStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitScalarVariable(CSubsetParser::ScalarVariableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArrayVariable(CSubsetParser::ArrayVariableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLogicOnlyExpression(CSubsetParser::LogicOnlyExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssignmentExpression(CSubsetParser::AssignmentExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRelOnlyLogicExpression(CSubsetParser::RelOnlyLogicExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBinaryLogicExpression(CSubsetParser::BinaryLogicExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSimpleOnlyRelExpression(CSubsetParser::SimpleOnlyRelExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBinaryRelExpression(CSubsetParser::BinaryRelExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTermOnlySimpleExpression(CSubsetParser::TermOnlySimpleExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAdditiveExpression(CSubsetParser::AdditiveExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMultiplicativeTerm(CSubsetParser::MultiplicativeTermContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnaryOnlyTerm(CSubsetParser::UnaryOnlyTermContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSignedUnary(CSubsetParser::SignedUnaryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNotUnary(CSubsetParser::NotUnaryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFactorUnary(CSubsetParser::FactorUnaryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVariableFactor(CSubsetParser::VariableFactorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunctionCallFactor(CSubsetParser::FunctionCallFactorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParenthesizedFactor(CSubsetParser::ParenthesizedFactorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIntegerConstantFactor(CSubsetParser::IntegerConstantFactorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFloatConstantFactor(CSubsetParser::FloatConstantFactorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPostIncrementFactor(CSubsetParser::PostIncrementFactorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPostDecrementFactor(CSubsetParser::PostDecrementFactorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNonEmptyArgumentList(CSubsetParser::NonEmptyArgumentListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEmptyArgumentList(CSubsetParser::EmptyArgumentListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArgumentSingle(CSubsetParser::ArgumentSingleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArgumentAppend(CSubsetParser::ArgumentAppendContext *ctx) override {
    return visitChildren(ctx);
  }


};

