#pragma once

#include <bits/stdc++.h>
using namespace std;

#include "2205150_HashFunction.hpp"
#include "2205150_SymbolInfo.hpp"

class ScopeTable {
private:
    ui bucket_numbers;
    string scope_table_uid;
    int child_count;
    SymbolInfo **hash_table;
    ScopeTable *parent_scope;
    HashFunction *hash_function;

public:
    ScopeTable(
        string scope_table_uid,
        ui bucket_numbers,
        ScopeTable *parent_scope,
        int hash_function = 1
    ) {
        this->scope_table_uid = scope_table_uid;
        this->bucket_numbers = bucket_numbers;
        this->parent_scope = parent_scope;
        this->child_count = 0;
        this->hash_function =
            HashFunctionFactory::createHashFunction(hash_function);

        hash_table = new SymbolInfo *[bucket_numbers]();
    }

    ~ScopeTable() {
        for (ui i = 0; i < bucket_numbers; i++) {
            SymbolInfo *current = hash_table[i];

            while (current != nullptr) {
                SymbolInfo *temporary = current;
                current = current->next;
                delete temporary;
            }
        }

        delete[] hash_table;
        delete hash_function;
    }

    ui getBucket(const string &str) const {
        return hash_function->calculateHash(str, bucket_numbers)
            % bucket_numbers;
    }

    bool insertSymbol(
        const string &symbol_name,
        const string &symbol_type,
        const string &data_type = ""
    ) {
        ui row_index = getBucket(symbol_name);

        if (hash_table[row_index] == nullptr) {
            hash_table[row_index] =
                new SymbolInfo(symbol_name, symbol_type, data_type);
            return true;
        }

        SymbolInfo *current = hash_table[row_index];
        SymbolInfo *previous = nullptr;

        while (current != nullptr) {
            if (current->getSymbolName() == symbol_name) {
                return false;
            }

            previous = current;
            current = current->next;
        }

        previous->next =
            new SymbolInfo(symbol_name, symbol_type, data_type);
        return true;
    }

    SymbolInfo *lookUp(const string &symbol_name) const {
        ui row_index = getBucket(symbol_name);
        SymbolInfo *current = hash_table[row_index];

        while (current != nullptr) {
            if (current->getSymbolName() == symbol_name) {
                return current;
            }

            current = current->next;
        }

        return nullptr;
    }

    bool deleteSymbol(const string &symbol_name) {
        ui row_index = getBucket(symbol_name);
        SymbolInfo *current = hash_table[row_index];
        SymbolInfo *previous = nullptr;

        while (current != nullptr) {
            if (current->getSymbolName() == symbol_name) {
                if (previous == nullptr) {
                    hash_table[row_index] = current->next;
                } else {
                    previous->next = current->next;
                }

                delete current;
                return true;
            }

            previous = current;
            current = current->next;
        }

        return false;
    }

    const string &getScopeTableUid() const {
        return scope_table_uid;
    }

    int getChildCount() const {
        return child_count;
    }

    void incrementChildCount() {
        child_count++;
    }

    ScopeTable *getParentScope() const {
        return parent_scope;
    }

    void printScopeTable(ostream &output = cout) const {
        output << "ScopeTable # " << scope_table_uid << '\n';

        for (ui i = 0; i < bucket_numbers; i++) {
            if (hash_table[i] == nullptr) {
                continue;
            }

            output << " " << i << " --> ";
            SymbolInfo *current = hash_table[i];
            bool first = true;

            while (current != nullptr) {
                if (!first) {
                    output << ' ';
                }

                current->printSymbolInfo(output);
                first = false;
                current = current->next;
            }

            output << '\n';
        }
    }
};
