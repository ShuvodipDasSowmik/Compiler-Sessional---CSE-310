#include "2205150_SymbolTable.hpp"
#include <fstream>
#include <sstream>

class IOHandler{
    private:
        ifstream input_file;
        ofstream output_file;
        SymbolTable *symbol_table;

        string *tokens;
        int token_count;
        int cmd_number;

        string normalizeLine(const string &str){
            size_t start = str.find_first_not_of(" \t\r\n");
            if(start == string::npos) return "";
            size_t end = str.find_last_not_of(" \t\r\n");
            string trimmed = str.substr(start, end - start + 1);

            string result;
            bool in_space = false;

            for(char c : trimmed){
                if(c == ' ' || c == '\t' || c == '\r' || c == '\n'){
                    if(!in_space){
                        result += ' ';
                        in_space = true;
                    }
                }
                else{
                    result += c;
                    in_space = false;
                }
            }

            return result;
        }

        int countTokens(const string &str){
            int count = 0;
            bool in_word = false;

            for(char c : str){
                if(c == ' '){
                    if(in_word){
                        count++;
                        in_word = false;
                    }
                }
                else{
                    in_word = true;
                }
            }

            if(in_word) count++;
            return count;
        }

        void clearTokens(){
            delete[] tokens;
            tokens = nullptr;
            token_count = 0;
        }

        void splitLine(const string &normalized_line){
            clearTokens();
            token_count = countTokens(normalized_line);

            if(token_count == 0) return;

            tokens = new string[token_count];

            istringstream iss(normalized_line);
            for(int i = 0; i < token_count; i++){
                iss >> tokens[i];
            }
        }

        string buildInsertType(){
            string type_token = tokens[2];

            if(type_token == "FUNCTION"){
                string return_type = tokens[3];
                string arguments = "";

                for(int i = 4; i < token_count; i++){
                    if(!arguments.empty()) arguments += ",";
                    arguments += tokens[i];
                }

                return "FUNCTION," + return_type + "<==(" + arguments + ")";
            }
            else if(type_token == "STRUCT" || type_token == "UNION"){
                string members = "";

                for(int i = 3; i < token_count; i += 2){
                    if(!members.empty()) members += ",";
                    members += "(" + tokens[i] + "," + tokens[i + 1] + ")";
                }

                return type_token + ",{" + members + "}";
            }
            else{
                return type_token;
            }
        }

        void handleInsert(){
            if(token_count < 3){
                cout << "\t" << "Number of parameters mismatch for the command I" << endl;
                return;
            }

            if((tokens[2] == "STRUCT" || tokens[2] == "UNION") && token_count % 2 == 0){
                cout << "\t" << "Number of parameters mismatch for the command I" << endl;
                return;
            }

            if(tokens[2] == "FUNCTION" && token_count < 4){
                cout << "\t" << "Number of parameters mismatch for the command I" << endl;
                return;
            }

            string symbol_name = tokens[1];
            string symbol_type = buildInsertType();

            symbol_table->insert(symbol_name, symbol_type);
        }

        void handleLookup(){
            if(token_count != 2){
                cout << "\t" << "Number of parameters mismatch for the command L" << endl;
                return;
            }
            symbol_table->lookUp(tokens[1]);
        }

        void handleDelete(){
            if(token_count != 2){
                cout << "\t" << "Number of parameters mismatch for the command D" << endl;
                return;
            }
            symbol_table->remove(tokens[1]);
        }

        // P A / P C are pre-validated in isValidCommand(),
        // so only valid cases reach here.
        void handlePrint(){
            if(tokens[1] == "A"){
                symbol_table->printAllScopeTables();
            }
            else{
                symbol_table->printCurrentScopeTable();
            }
        }

        void handleEnterScope(){
            if(token_count != 1){
                cout << "\t" << "Number of parameters mismatch for the command S" << endl;
                return;
            }
            symbol_table->enterScope();
        }

        // Root scope case is pre-filtered in isValidCommand(),
        // so exitScope() is only called when it's safe to do so.
        void handleExitScope(){
            symbol_table->exitScope();
        }

        void handleQuit(){
            symbol_table->deleteAllScope();
        }

        // Rule 1: opcode must be one of the 7 known letters.
        bool isValidOpcode(){
            if(token_count == 0) return false;
            string cmd = tokens[0];
            return cmd == "I" || cmd == "L" || cmd == "D" ||
                   cmd == "P" || cmd == "S" || cmd == "E" || cmd == "Q";
        }

        // Rules 2 and 3: further validity checks beyond the opcode.
        // Called BEFORE cmd_number increments, so invalid commands
        // are silently skipped with no output at all.
        bool isValidCommand(){
            if(!isValidOpcode()) return false;

            string cmd = tokens[0];

            // Rule 2: P must be followed by exactly A or C
            if(cmd == "P"){
                if(token_count != 2) return false;
                if(tokens[1] != "A" && tokens[1] != "C") return false;
            }

            // Rule 3: E on the root scope is silently skipped
            if(cmd == "E"){
                if(symbol_table->isAtRootScope()) return false;
            }

            return true;
        }

        

        void dispatch(){
            string command = tokens[0];

            if(command == "I")      handleInsert();
            else if(command == "L") handleLookup();
            else if(command == "D") handleDelete();
            else if(command == "P") handlePrint();
            else if(command == "S") handleEnterScope();
            else if(command == "E") handleExitScope();
            else if(command == "Q") handleQuit();
        }

    public:
        streambuf *original_cout_buf;

        // IO Handler initializes the symbol table with the bucket number
        // from the first line of the input file in its constructor
        IOHandler(const string &input_filename, const string &output_filename){
            tokens = nullptr;
            token_count = 0;
            cmd_number = 0;

            input_file.open(input_filename);
            output_file.open(output_filename);

            if(!input_file.is_open()){
                cerr << "Error: could not open input file: " << input_filename << endl;
                exit(1);
            }
            if(!output_file.is_open()){
                cerr << "Error: could not open output file: " << output_filename << endl;
                exit(1);
            }

            original_cout_buf = cout.rdbuf();
            cout.rdbuf(output_file.rdbuf());

            string first_line;
            getline(input_file, first_line);
            int bucket_numbers = stoi(normalizeLine(first_line));

            symbol_table = new SymbolTable(bucket_numbers);
        }

        ~IOHandler(){
            cout.rdbuf(original_cout_buf);

            delete[] tokens;
            delete symbol_table;

            if(input_file.is_open()) input_file.close();
            if(output_file.is_open()) output_file.close();
        }

        void run(){
            string line;
            bool quit = false;

            while(!quit && getline(input_file, line)){
                string normalized = normalizeLine(line);
                if(normalized.empty()) continue;

                // Split first so isValidCommand() can inspect tokens
                splitLine(normalized);

                if(token_count == 0){
                    clearTokens();
                    continue;
                }

                // Rules 1, 2, 3: silently skip without printing Cmd N:
                if(!isValidCommand()){
                    clearTokens();
                    continue;
                }

                // Rule 4: Q is still printed and executed, then loop stops
                if(tokens[0] == "Q") quit = true;

                cmd_number++;
                cout << "Cmd " << cmd_number << ": " << normalized << endl;

                dispatch();
                clearTokens();
            }
        }
};