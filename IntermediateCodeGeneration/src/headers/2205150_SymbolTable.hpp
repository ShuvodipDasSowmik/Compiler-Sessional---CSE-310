#pragma once

#include <bits/stdc++.h>
using namespace std;

#include "2205150_ScopeTable.hpp"

class SymbolTable {
private:
    ScopeTable *current_scope;
    int bucket_numbers;
    int hash_function;

    ScopeTable *generateNewScope(ScopeTable *parent_scope) {
        string uid = "1";

        if (parent_scope != nullptr) {
            parent_scope->incrementChildCount();
            uid = parent_scope->getScopeTableUid()
                + "." + to_string(parent_scope->getChildCount());
        }

        return new ScopeTable(
            uid,
            bucket_numbers,
            parent_scope,
            hash_function
        );
    }

public:
    SymbolTable(int bucket_numbers = 30, int hash_function = 1) {
        this->bucket_numbers = bucket_numbers;
        this->hash_function = hash_function;
        current_scope = generateNewScope(nullptr);
    }

    ~SymbolTable() {
        while (current_scope != nullptr) {
            ScopeTable *temporary = current_scope;
            current_scope = current_scope->getParentScope();
            delete temporary;
        }
    }

    SymbolTable(const SymbolTable &) = delete;
    SymbolTable &operator=(const SymbolTable &) = delete;

    void enterScope() {
        current_scope = generateNewScope(current_scope);
    }

    void exitScope() {
        if (current_scope->getParentScope() == nullptr) {
            return;
        }

        ScopeTable *temporary = current_scope;
        current_scope = current_scope->getParentScope();
        delete temporary;
    }

    void deleteAllScope() {
        while (current_scope != nullptr) {
            ScopeTable *temporary = current_scope;
            current_scope = current_scope->getParentScope();
            delete temporary;
        }
    }

    bool insert(
        const string &symbol_name,
        const string &symbol_type,
        const string &data_type = ""
    ) {
        return current_scope->insertSymbol(
            symbol_name,
            symbol_type,
            data_type
        );
    }

    bool remove(const string &symbol_name) {
        return current_scope->deleteSymbol(symbol_name);
    }

    SymbolInfo *lookUpCurrent(const string &symbol_name) const {
        return current_scope->lookUp(symbol_name);
    }

    SymbolInfo *lookUpSymbolInfo(const string &symbol_name) const {
        ScopeTable *scope = current_scope;

        while (scope != nullptr) {
            SymbolInfo *symbol = scope->lookUp(symbol_name);

            if (symbol != nullptr) {
                return symbol;
            }

            scope = scope->getParentScope();
        }

        return nullptr;
    }

    bool lookUp(const string &symbol_name) const {
        return lookUpSymbolInfo(symbol_name) != nullptr;
    }

    void printCurrentScopeTable(ostream &output = cout) const {
        current_scope->printScopeTable(output);
        output << '\n';
    }

    void printAllScopeTables(ostream &output = cout) const {
        ScopeTable *scope = current_scope;

        while (scope != nullptr) {
            scope->printScopeTable(output);
            output << '\n';
            scope = scope->getParentScope();
        }
    }

    bool isAtRootScope() const {
        return current_scope->getParentScope() == nullptr;
    }
};
