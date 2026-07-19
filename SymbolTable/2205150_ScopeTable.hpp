#include "2205150_SymbolInfo.hpp"
#include "2205150_HashFunction.hpp"

#define ui unsigned int
#define ull unsigned long long

class ScopeTable{

    private:
        ui bucket_numbers, scope_table_uid;
        SymbolInfo **hash_table;
        ScopeTable *parent_scope;
        HashFunction *hash_function;

    public:
        ScopeTable(int scope_table_uid, ui bucket_numbers, ScopeTable *parent_scope, int hash_function = 1){
            this->scope_table_uid = scope_table_uid;
            this->bucket_numbers = bucket_numbers;
            this->parent_scope = parent_scope;

            this->hash_function = HashFunctionFactory::createHashFunction(hash_function);

            // allocate memory for the hash table
            hash_table = new SymbolInfo*[bucket_numbers];

            for(ui i=0; i < bucket_numbers; i++){
                hash_table[i] = NULL;
            }
        }

        ~ScopeTable(){
            // delete all the SymbolInfo objects in the hash table
            for(ui i=0; i < bucket_numbers; i++){
                SymbolInfo *current = hash_table[i];

                while(current != NULL){
                    SymbolInfo *temp = current;
                    current = current->next;
                    delete temp;
                }
            }
            // delete the hash table itself
            delete[] hash_table;
            delete hash_function;
        }

        ui getBucket(const string &str){
            ull hash_value = hash_function->calculateHash(str, bucket_numbers);
            return hash_value % bucket_numbers;
        }

        bool insertSymbol(const string &symbol_name, const string &symbol_type){
            ui row_index = getBucket(symbol_name);
            ui col_index = 1;

            // If the bucket is empty, insert the new symbol at the head of the linked list
            if(hash_table[row_index] == NULL){
                SymbolInfo *new_symbol_info = new SymbolInfo(symbol_name, symbol_type);
                hash_table[row_index] = new_symbol_info;
            }
            else{
                SymbolInfo *current = hash_table[row_index];
                SymbolInfo *prev = nullptr;
                
                // Traverse the linked list to check for duplicates and find the end of the list
                while(current != NULL){
                    if(current->getSymbolName() == symbol_name){
                        cout << "\t" << "'" << symbol_name << "'" << " already exists in the current ScopeTable" << endl;
                        return false; // already exists in the current scope - reject duplicate
                    }
                    prev = current;
                    current = current->next;

                    col_index++;
                }

                SymbolInfo *new_symbol_info = new SymbolInfo(symbol_name, symbol_type);
                prev->next = new_symbol_info;
            }

            cout << "\t" << "Inserted in ScopeTable# " << this->scope_table_uid << " at position " << row_index + 1 << ", " << col_index << endl;
            return true;
        }

        SymbolInfo* lookUp(const string &str){
            ui row_index = getBucket(str);
            ui col_index = 1;

            SymbolInfo *current = hash_table[row_index];

            while(current != NULL){
                if(current->getSymbolName() == str){
                    cout << "\t" << "'" << str << "'" << " found in ScopeTable# " << this->scope_table_uid << " at position " << row_index + 1 << ", " << col_index << endl;
                    return current;
                }

                current = current->next;
                col_index++;
            }

            return NULL;
        }

        bool deleteSymbol(const string &str){
            ui row_index = getBucket(str);
            ui col_index = 1;

            SymbolInfo *current = hash_table[row_index];

            // If current node is the target
            if(current != NULL && current->getSymbolName() == str){
                hash_table[row_index] = current->next;

                cout << "\t" << "Deleted " << "'" << str << "'" << " from ScopeTable# " << this->scope_table_uid << " at position " << row_index + 1 << ", " << col_index << endl;
                
                delete current;
                return true;
            }
            else{
                SymbolInfo *prev = nullptr;

                while(current != NULL){
                    if(current->getSymbolName() == str){
                        prev->next = current->next;
                        cout << "\t" << "Deleted " << "'" << str << "'" << " from ScopeTable# " << this->scope_table_uid << " at position " << row_index + 1 << ", " << col_index << endl;
                        
                        delete current;
                        return true;
                    }

                    prev = current;
                    current = current->next;
                    col_index++;
                }
            }

            cout << "\t" << "Not found in the current ScopeTable" << endl;
            return false;
        }

        string getScopeTableUid(){
            return to_string(scope_table_uid);
        }

        void printScopeTable(int tab = 1){
            // Print indentation (for nested scopes)
            for (int i = 0; i < tab; i++)
                cout << "\t";
            
            cout << "ScopeTable# " << this->getScopeTableUid() << endl;
            
            // Print each bucket
            for (ui i = 0; i < bucket_numbers; i++)
            {
                for (int i = 0; i < tab; i++)
                    cout << "\t";
                cout << i + 1 << "--> ";
                
                if (hash_table[i] != NULL)
                {
                    SymbolInfo *temp = hash_table[i];
                    while (temp != NULL)
                    {
                        cout << "<" << temp->getSymbolName() << "," 
                            << temp->getSymbolType() << "> ";
                        temp = temp->next;
                    }
                }
                cout << endl;
            }
        }

        ScopeTable* getParentScope(){
            return parent_scope;
        }
};