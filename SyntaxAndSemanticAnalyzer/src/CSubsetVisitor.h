
// Generated from CSubset.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "CSubsetParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by CSubsetParser.
 */
class  CSubsetVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by CSubsetParser.
   */
    virtual std::any visitStartProgram(CSubsetParser::StartProgramContext *context) = 0;

    virtual std::any visitProgramSingleUnit(CSubsetParser::ProgramSingleUnitContext *context) = 0;

    virtual std::any visitProgramMultipleUnits(CSubsetParser::ProgramMultipleUnitsContext *context) = 0;

    virtual std::any visitUnitVariableDeclaration(CSubsetParser::UnitVariableDeclarationContext *context) = 0;

    virtual std::any visitUnitFunctionDeclaration(CSubsetParser::UnitFunctionDeclarationContext *context) = 0;

    virtual std::any visitUnitFunctionDefinition(CSubsetParser::UnitFunctionDefinitionContext *context) = 0;

    virtual std::any visitFunctionDeclarationWithParameters(CSubsetParser::FunctionDeclarationWithParametersContext *context) = 0;

    virtual std::any visitFunctionDeclarationWithoutParameters(CSubsetParser::FunctionDeclarationWithoutParametersContext *context) = 0;

    virtual std::any visitFunctionDefinitionWithParameters(CSubsetParser::FunctionDefinitionWithParametersContext *context) = 0;

    virtual std::any visitFunctionDefinitionWithoutParameters(CSubsetParser::FunctionDefinitionWithoutParametersContext *context) = 0;

    virtual std::any visitParameterSingleNamed(CSubsetParser::ParameterSingleNamedContext *context) = 0;

    virtual std::any visitParameterSingleInvalidName(CSubsetParser::ParameterSingleInvalidNameContext *context) = 0;

    virtual std::any visitParameterAppendNamed(CSubsetParser::ParameterAppendNamedContext *context) = 0;

    virtual std::any visitParameterAppendUnnamed(CSubsetParser::ParameterAppendUnnamedContext *context) = 0;

    virtual std::any visitParameterSingleUnnamed(CSubsetParser::ParameterSingleUnnamedContext *context) = 0;

    virtual std::any visitCompoundWithStatements(CSubsetParser::CompoundWithStatementsContext *context) = 0;

    virtual std::any visitEmptyCompound(CSubsetParser::EmptyCompoundContext *context) = 0;

    virtual std::any visitVariableDeclaration(CSubsetParser::VariableDeclarationContext *context) = 0;

    virtual std::any visitIntegerType(CSubsetParser::IntegerTypeContext *context) = 0;

    virtual std::any visitFloatType(CSubsetParser::FloatTypeContext *context) = 0;

    virtual std::any visitVoidType(CSubsetParser::VoidTypeContext *context) = 0;

    virtual std::any visitDeclarationAppendArray(CSubsetParser::DeclarationAppendArrayContext *context) = 0;

    virtual std::any visitDeclarationInvalidSeparator(CSubsetParser::DeclarationInvalidSeparatorContext *context) = 0;

    virtual std::any visitDeclarationAppendScalar(CSubsetParser::DeclarationAppendScalarContext *context) = 0;

    virtual std::any visitDeclarationSingleScalar(CSubsetParser::DeclarationSingleScalarContext *context) = 0;

    virtual std::any visitDeclarationSingleArray(CSubsetParser::DeclarationSingleArrayContext *context) = 0;

    virtual std::any visitStatementsSingle(CSubsetParser::StatementsSingleContext *context) = 0;

    virtual std::any visitStatementsAppend(CSubsetParser::StatementsAppendContext *context) = 0;

    virtual std::any visitStatementVariableDeclaration(CSubsetParser::StatementVariableDeclarationContext *context) = 0;

    virtual std::any visitStatementExpression(CSubsetParser::StatementExpressionContext *context) = 0;

    virtual std::any visitStatementCompound(CSubsetParser::StatementCompoundContext *context) = 0;

    virtual std::any visitForStatement(CSubsetParser::ForStatementContext *context) = 0;

    virtual std::any visitIfStatement(CSubsetParser::IfStatementContext *context) = 0;

    virtual std::any visitWhileStatement(CSubsetParser::WhileStatementContext *context) = 0;

    virtual std::any visitPrintlnStatement(CSubsetParser::PrintlnStatementContext *context) = 0;

    virtual std::any visitReturnStatement(CSubsetParser::ReturnStatementContext *context) = 0;

    virtual std::any visitEmptyExpressionStatement(CSubsetParser::EmptyExpressionStatementContext *context) = 0;

    virtual std::any visitExpressionStatementWithExpression(CSubsetParser::ExpressionStatementWithExpressionContext *context) = 0;

    virtual std::any visitInvalidOperandExpressionStatement(CSubsetParser::InvalidOperandExpressionStatementContext *context) = 0;

    virtual std::any visitMissingSemicolonExpressionStatement(CSubsetParser::MissingSemicolonExpressionStatementContext *context) = 0;

    virtual std::any visitScalarVariable(CSubsetParser::ScalarVariableContext *context) = 0;

    virtual std::any visitArrayVariable(CSubsetParser::ArrayVariableContext *context) = 0;

    virtual std::any visitLogicOnlyExpression(CSubsetParser::LogicOnlyExpressionContext *context) = 0;

    virtual std::any visitAssignmentExpression(CSubsetParser::AssignmentExpressionContext *context) = 0;

    virtual std::any visitRelOnlyLogicExpression(CSubsetParser::RelOnlyLogicExpressionContext *context) = 0;

    virtual std::any visitBinaryLogicExpression(CSubsetParser::BinaryLogicExpressionContext *context) = 0;

    virtual std::any visitSimpleOnlyRelExpression(CSubsetParser::SimpleOnlyRelExpressionContext *context) = 0;

    virtual std::any visitBinaryRelExpression(CSubsetParser::BinaryRelExpressionContext *context) = 0;

    virtual std::any visitTermOnlySimpleExpression(CSubsetParser::TermOnlySimpleExpressionContext *context) = 0;

    virtual std::any visitAdditiveExpression(CSubsetParser::AdditiveExpressionContext *context) = 0;

    virtual std::any visitMultiplicativeTerm(CSubsetParser::MultiplicativeTermContext *context) = 0;

    virtual std::any visitUnaryOnlyTerm(CSubsetParser::UnaryOnlyTermContext *context) = 0;

    virtual std::any visitSignedUnary(CSubsetParser::SignedUnaryContext *context) = 0;

    virtual std::any visitNotUnary(CSubsetParser::NotUnaryContext *context) = 0;

    virtual std::any visitFactorUnary(CSubsetParser::FactorUnaryContext *context) = 0;

    virtual std::any visitVariableFactor(CSubsetParser::VariableFactorContext *context) = 0;

    virtual std::any visitFunctionCallFactor(CSubsetParser::FunctionCallFactorContext *context) = 0;

    virtual std::any visitParenthesizedFactor(CSubsetParser::ParenthesizedFactorContext *context) = 0;

    virtual std::any visitIntegerConstantFactor(CSubsetParser::IntegerConstantFactorContext *context) = 0;

    virtual std::any visitFloatConstantFactor(CSubsetParser::FloatConstantFactorContext *context) = 0;

    virtual std::any visitPostIncrementFactor(CSubsetParser::PostIncrementFactorContext *context) = 0;

    virtual std::any visitPostDecrementFactor(CSubsetParser::PostDecrementFactorContext *context) = 0;

    virtual std::any visitNonEmptyArgumentList(CSubsetParser::NonEmptyArgumentListContext *context) = 0;

    virtual std::any visitEmptyArgumentList(CSubsetParser::EmptyArgumentListContext *context) = 0;

    virtual std::any visitArgumentSingle(CSubsetParser::ArgumentSingleContext *context) = 0;

    virtual std::any visitArgumentAppend(CSubsetParser::ArgumentAppendContext *context) = 0;


};

