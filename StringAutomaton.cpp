#include "StringAutomaton.h"

void StringAutomaton::S0(const std::string& input) {
    if (input[index] == '\'') {
        inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void StringAutomaton::S1(const std::string& input) {
    while (input[index] != '\'') {
        if (input[index] == '\n') {
            newLines++;
        }
        inputRead++;
        index++;
        if(index > (int)input.size()){
            badString(input);
        }
    }
    S2(input);
}

void StringAutomaton::S2(const std::string& input) {
    if (input[index] == '\'') {
        inputRead++;
        index++;
        if (input[index] == '\'') {
            inputRead++;
            index++;
            S1(input);
        }
    }
    else {
        Serr();
    }
}

void StringAutomaton::badString(const std::string &input){
    this->type = TokenType::UNDEFINED;
}

