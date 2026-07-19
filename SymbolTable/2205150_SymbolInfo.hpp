#include <bits/stdc++.h>
using namespace std;

class SymbolInfo{
    private:
        string symbol_name;
        string symbol_type;

    public:
        SymbolInfo *next;

    SymbolInfo(string symbol_name = "", string symbol_type = ""){
        this->symbol_name = symbol_name;
        this->symbol_type = symbol_type;
        this->next = nullptr;
    }

    ~SymbolInfo(){
        // cout << "Destructing a SymbolInfo" << endl;
    }

    void setSymbolName(string symbol_name){
        this->symbol_name = symbol_name;
    }

    void setSymbolType(string symbol_type){
        this->symbol_type = symbol_type;
    }

    string getSymbolName(){
        return symbol_name;
    }

    string getSymbolType(){
        return symbol_type;
    }

    void printSymbolInfo(){
        cout << "<" << this->symbol_name << "," << this->symbol_type << ">" << endl;
    }
};