#include "BlockCommentAutomaton.h"

void BlockCommentAutomaton::S0(const std::string& input) {
    if (input[index] == '#') {
        inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void BlockCommentAutomaton::S1(const std::string& input) {
    if (input[index] == '|') {
        inputRead++;
        index++;
        S2(input);
    }
    else {
        Serr();
    }
}

void BlockCommentAutomaton::S2(const std::string& input) {
    while(index < (int)input.size() && input[index] != '|'){
        if (input[index] == '\n') {
            newLines++;
        }
        inputRead++;
        index++;
    }
    if(index < (int)input.size()){
        index++;
        inputRead++;
        S3(input);
    } else {
        badComment(input);
    }
}

void BlockCommentAutomaton::S3(const std::string& input) {
    while (input[index] == '|') {
        inputRead++;
        index++;
    }
    if(input[index] != '#') {
        if (input[index] == '\n'){
            newLines++;
        }
        index++;
        inputRead++;
        S2(input);
    }
    else {
        S4(input);
    }
}

void BlockCommentAutomaton::S4(const std::string& input) {
    inputRead++;
    index++;
    this->type = TokenType::COMMENT;
}

void BlockCommentAutomaton::badComment(const std::string &input){
    this->type = TokenType::UNDEFINED;
}