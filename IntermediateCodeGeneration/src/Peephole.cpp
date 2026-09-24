#include "Peephole.h"

#include <bits/stdc++.h>
using namespace std;

namespace{

string trimText(const string &text){
    size_t start = text.find_first_not_of(" \t");

    if (start == string::npos){
        return "";
    }

    size_t end = text.find_last_not_of(" \t");
    return text.substr(start, end - start + 1);
}

// Drops a trailing "; comment" and surrounding whitespace, leaving just the instruction.
string stripComment(const string &line){
    size_t semicolon = line.find(';');
    string code = semicolon == string::npos ? line : line.substr(0, semicolon);
    return trimText(code);
}

bool isLabelLine(const string &trimmed_line, string &label_name){
    if (trimmed_line.empty() || trimmed_line.back() != ':'){
        return false;
    }

    string candidate = trimmed_line.substr(0, trimmed_line.size() - 1);

    if (candidate.empty()){
        return false;
    }

    for (char c : candidate){
        if (!isalnum(static_cast<unsigned char>(c)) && c != '_' && c != '.'){
            return false;
        }
    }

    label_name = candidate;
    return true;
}

bool isBlankOrCommentOnly(const string &trimmed_line){
    return trimmed_line.empty() || trimmed_line[0] == ';';
}

bool parseInstruction(const string &code, string &mnemonic, string &operands){
    string text = trimText(code);

    if (text.empty()){
        return false;
    }

    size_t space = text.find_first_of(" \t");

    if (space == string::npos){
        mnemonic = text;
        operands = "";
        return true;
    }

    mnemonic = text.substr(0, space);
    operands = trimText(text.substr(space + 1));
    return true;
}

vector<string> splitOperands(const string &operands){
    vector<string> parts;
    string current;

    for (char c : operands){
        if (c == ','){
            parts.push_back(trimText(current));
            current.clear();
        }
        else{
            current += c;
        }
    }

    parts.push_back(trimText(current));
    return parts;
}

string toUpper(string text){
    for (char &c : text){
        c = static_cast<char>(toupper(static_cast<unsigned char>(c)));
    }

    return text;
}

// Whole-word replacement so renaming label "L1" doesn't also touch "L10" or "gL1".
void replaceWholeWord(string &text, const string &from, const string &to){
    size_t pos = 0;

    while ((pos = text.find(from, pos)) != string::npos){
        bool left_ok = pos == 0 || !(isalnum(static_cast<unsigned char>(text[pos - 1])) || text[pos - 1] == '_');
        size_t end = pos + from.size();
        bool right_ok = end >= text.size() || !(isalnum(static_cast<unsigned char>(text[end])) || text[end] == '_' || text[end] == ':');

        if (left_ok && right_ok){
            text.replace(pos, from.size(), to);
            pos += to.size();
        }
        else{
            pos += from.size();
        }
    }
}

// (iv) Consecutive label definitions collapse to the last label in the run;
// every reference to an earlier label in the run is rewritten to point there.
void mergeConsecutiveLabels(vector<string> &lines){
    unordered_map<string, string> rename;
    vector<bool> drop(lines.size(), false);

    for (size_t i = 0; i < lines.size();){
        string label;
        string trimmed = trimText(lines[i]);

        if (!isLabelLine(trimmed, label)){
            ++i;
            continue;
        }

        vector<size_t> group_indices = {i};
        vector<string> group_labels = {label};
        size_t j = i + 1;

        while (j < lines.size()){
            string next_trimmed = trimText(lines[j]);
            string next_label;

            if (isLabelLine(next_trimmed, next_label)){
                group_indices.push_back(j);
                group_labels.push_back(next_label);
                ++j;
                continue;
            }

            if (isBlankOrCommentOnly(next_trimmed)){
                ++j;
                continue;
            }

            break;
        }

        if (group_labels.size() > 1){
            const string &canonical = group_labels.back();

            for (size_t k = 0; k + 1 < group_labels.size(); ++k){
                rename[group_labels[k]] = canonical;
                drop[group_indices[k]] = true;
            }
        }

        i = j;
    }

    if (rename.empty()){
        return;
    }

    // Resolve chains (a label renamed to another label that was itself renamed).
    for (auto &entry : rename){
        string target = entry.second;
        unordered_set<string> seen;

        while (rename.count(target) && !seen.count(target)){
            seen.insert(target);
            target = rename[target];
        }

        entry.second = target;
    }

    for (size_t i = 0; i < lines.size(); ++i){
        if (drop[i]){
            continue;
        }

        for (const auto &entry : rename){
            replaceWholeWord(lines[i], entry.first, entry.second);
        }
    }

    vector<string> kept;

    for (size_t i = 0; i < lines.size(); ++i){
        if (!drop[i]){
            kept.push_back(lines[i]);
        }
    }

    lines = kept;
}

// (i), (ii), (iii): redundant load/store pairs, redundant push/pop pairs, and
// redundant arithmetic identities. Comment and blank lines are transparent
// when looking for the "next" instruction, but a label is a hard barrier.
void removeRedundantInstructions(vector<string> &lines){
    vector<bool> remove(lines.size(), false);

    auto nextSignificant = [&](size_t from) -> long{
        for (size_t k = from; k < lines.size(); ++k){
            if (remove[k]){
                continue;
            }

            string trimmed = trimText(stripComment(lines[k]));

            if (trimmed.empty()){
                continue;
            }

            string label;

            if (isLabelLine(trimmed, label)){
                return -1;
            }

            return static_cast<long>(k);
        }

        return -1;
    };

    for (size_t i = 0; i < lines.size(); ++i){
        if (remove[i]){
            continue;
        }

        string mnemonic, operands;

        if (!parseInstruction(stripComment(lines[i]), mnemonic, operands)){
            continue;
        }

        string upper_mnemonic = toUpper(mnemonic);
        long j = nextSignificant(i + 1);

        // (i) MOV a, b  immediately followed by  MOV b, a
        if (upper_mnemonic == "MOV" && j >= 0){
            vector<string> ops1 = splitOperands(operands);
            string mnemonic2, operands2;

            if (ops1.size() == 2 && parseInstruction(stripComment(lines[j]), mnemonic2, operands2) && toUpper(mnemonic2) == "MOV"){
                vector<string> ops2 = splitOperands(operands2);

                if (ops2.size() == 2 && ops1[0] == ops2[1] && ops1[1] == ops2[0]){
                    remove[j] = true;
                }
            }
        }

        // (ii) PUSH r immediately followed by POP r (same operand)
        if (upper_mnemonic == "PUSH" && j >= 0){
            string mnemonic2, operands2;

            if (parseInstruction(stripComment(lines[j]), mnemonic2, operands2) && toUpper(mnemonic2) == "POP"){
                if (trimText(operands) == trimText(operands2)){
                    remove[i] = true;
                    remove[j] = true;
                }
            }
        }

        // (iii) redundant arithmetic identities
        if (upper_mnemonic == "ADD" || upper_mnemonic == "SUB"){
            vector<string> ops1 = splitOperands(operands);

            if (ops1.size() == 2 && ops1[1] == "0"){
                remove[i] = true;
            }
        }

        if (upper_mnemonic == "MUL" || upper_mnemonic == "IMUL"){
            vector<string> ops1 = splitOperands(operands);

            if (ops1.size() == 2 && ops1[1] == "1"){
                remove[i] = true;
            }
        }
    }

    vector<string> kept;

    for (size_t i = 0; i < lines.size(); ++i){
        if (!remove[i]){
            kept.push_back(lines[i]);
        }
    }

    lines = kept;
}

}

void Peephole::optimize(const string &input_path, const string &output_path){
    ifstream in(input_path);
    vector<string> lines;
    string line;

    while (getline(in, line)){
        lines.push_back(line);
    }

    in.close();

    mergeConsecutiveLabels(lines);
    removeRedundantInstructions(lines);

    ofstream out(output_path);

    for (const string &out_line : lines){
        out << out_line << "\n";
    }
}
