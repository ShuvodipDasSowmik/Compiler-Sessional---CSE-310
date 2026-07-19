#include "2205150_ScopeTable.hpp"

class SymbolTable{
    private:
        ScopeTable *current_scope;
        int bucket_numbers, hash_function, scope_table_uid;

        ScopeTable* generateNewScope(ScopeTable *parent_scope){
            ScopeTable *new_scope = new ScopeTable(scope_table_uid, bucket_numbers, parent_scope, hash_function);
            
            cout << "\t" << "ScopeTable# " << new_scope->getScopeTableUid() << " created" << endl;
            this->scope_table_uid++;
            
            return new_scope;
        }

    public:
        SymbolTable(int bucket_numbers, int hash_function = 1){
            
            this->bucket_numbers = bucket_numbers;
            this->hash_function = hash_function;
            this->scope_table_uid = 1;

            current_scope = generateNewScope(nullptr);
        }

        ~SymbolTable(){
            while(current_scope != nullptr){
                ScopeTable *temp_scope = current_scope;
                current_scope = temp_scope->getParentScope();
                delete temp_scope;
            }
        }

        void enterScope(){
            ScopeTable *new_scope = generateNewScope(current_scope);
            current_scope = new_scope;
        }

        void exitScope(){
            // Update the current scope to its parent and delete the current scope
            if(current_scope->getParentScope() != NULL){
                ScopeTable *temp_scope = current_scope;
                current_scope = temp_scope->getParentScope();

                cout << "\t" << "ScopeTable# " << temp_scope->getScopeTableUid() << " removed" << endl;
                delete temp_scope;
            }
            else{
                cout << "\t" << "Sorry we cant remove the main scope! " << endl;
            }
        }

        void deleteAllScope(){
            // Delete all scopes starting from the current scope
            while(current_scope != nullptr){
                ScopeTable *temp_scope = current_scope;
                current_scope = temp_scope->getParentScope();
                
                cout << "\t" << "ScopeTable# " << temp_scope->getScopeTableUid() << " removed" << endl;
                delete temp_scope;
            }
        }

        bool insert(string symbol_name, string symbol_type){
            if(current_scope->insertSymbol(symbol_name, symbol_type)){
                return true;
            }
            return false;
        }

        bool remove(string symbol_name){
            if(current_scope->deleteSymbol(symbol_name)){
                return true;
            }
            return false;
        }

        // If the symbol doesn't exist in the current scope,
        // then look for it in the parent scopes recursively
        bool lookUp(string symbol_name){
            ScopeTable *temp_scope = current_scope;

            while(temp_scope != nullptr){
                SymbolInfo *symbol_info = temp_scope->lookUp(symbol_name);

                if(symbol_info != nullptr){
                    return true;
                }

                temp_scope = temp_scope->getParentScope();
            }

            cout << "\t" << "'" << symbol_name << "'" << " not found in any of the ScopeTables" << endl;
            return false;
        }

        void printCurrentScopeTable(){
            current_scope->printScopeTable();
        }

        void printAllScopeTables(){
            ScopeTable *temp_scope = current_scope;
            int tab = 1;

            while(temp_scope != nullptr){
                temp_scope->printScopeTable(tab);
                temp_scope = temp_scope->getParentScope();
                tab++;
            }
        }

        bool isAtRootScope(){
            return current_scope->getParentScope() == nullptr;
        }
};
