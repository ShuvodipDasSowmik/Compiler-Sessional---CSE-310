#pragma once

#include <bits/stdc++.h>
using namespace std;

class SymbolInfo {
private:
    string symbol_name;
    string symbol_type;
    string data_type;

    bool is_array;
    int array_size;

    bool is_function;
    bool function_declared;
    bool function_defined;
    string return_type;
    vector<string> parameter_types;

    // Code generation bookkeeping: where this variable actually lives once
    // compiled, as opposed to the semantic-analysis fields above.
    bool is_global_variable;
    int stack_offset;
    string asm_label;

public:
    SymbolInfo *next;

    SymbolInfo(
        string symbol_name = "",
        string symbol_type = "",
        string data_type = ""
    ) {
        this->symbol_name = symbol_name;
        this->symbol_type = symbol_type;
        this->data_type = data_type;

        this->is_array = false;
        this->array_size = 0;

        this->is_function = false;
        this->function_declared = false;
        this->function_defined = false;
        this->return_type = "";

        this->is_global_variable = false;
        this->stack_offset = 0;

        this->next = nullptr;
    }

    void setSymbolName(const string &symbol_name) {
        this->symbol_name = symbol_name;
    }

    void setSymbolType(const string &symbol_type) {
        this->symbol_type = symbol_type;
    }

    void setDataType(const string &data_type) {
        this->data_type = data_type;
    }

    void setIsArray(bool is_array) {
        this->is_array = is_array;
    }

    void setArraySize(int array_size) {
        this->array_size = array_size;
    }

    void setIsFunction(bool is_function) {
        this->is_function = is_function;
    }

    void setFunctionDeclared(bool function_declared) {
        this->function_declared = function_declared;
        if (function_declared) {
            this->is_function = true;
        }
    }

    void setFunctionDefined(bool function_defined) {
        this->function_defined = function_defined;
        if (function_defined) {
            this->is_function = true;
        }
    }

    void setReturnType(const string &return_type) {
        this->return_type = return_type;
        this->data_type = return_type;
        this->is_function = true;
    }

    void setParamTypes(const vector<string> &parameter_types) {
        this->parameter_types = parameter_types;
    }

    void addParamType(const string &parameter_type) {
        this->parameter_types.push_back(parameter_type);
    }

    void setIsGlobalVariable(bool is_global_variable) {
        this->is_global_variable = is_global_variable;
    }

    void setStackOffset(int stack_offset) {
        this->stack_offset = stack_offset;
    }

    void setAsmLabel(const string &asm_label) {
        this->asm_label = asm_label;
    }

    const string &getSymbolName() const {
        return symbol_name;
    }

    const string &getSymbolType() const {
        return symbol_type;
    }

    const string &getDataType() const {
        return data_type;
    }

    bool getIsArray() const {
        return is_array;
    }

    int getArraySize() const {
        return array_size;
    }

    bool getIsFunction() const {
        return is_function;
    }

    bool getFunctionDeclared() const {
        return function_declared;
    }

    bool getFunctionDefined() const {
        return function_defined;
    }

    const string &getReturnType() const {
        return return_type;
    }

    const vector<string> &getParamTypes() const {
        return parameter_types;
    }

    bool getIsGlobalVariable() const {
        return is_global_variable;
    }

    int getStackOffset() const {
        return stack_offset;
    }

    const string &getAsmLabel() const {
        return asm_label;
    }

    void printSymbolInfo(ostream &output = cout) const {
        output << "< " << symbol_name << " , " << symbol_type << " >";
    }
};
