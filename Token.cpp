#include <iomanip>
#include "Token.h"

Token::Token(TokenType type, std::string description, int line) {
    // TODO: initialize all member variables
    this->type = type;
    this->description = description;
    this->line = line;
}

void Token::toString() {
    if(type == TokenType::COLON){
        cout << "(COLON," << quoted(description) << "," << line << ")" << endl;
    } else if(type == TokenType::COLON_DASH) {
        cout << "(COLON_DASH," << quoted(description) << "," << line << ")" << endl;
    } else if(type == TokenType::COMMA) {
        cout << "(COMMA," << quoted(description) << "," << line << ")" << endl;
    } else if(type == TokenType::PERIOD) {
        cout << "(PERIOD," << quoted(description) << "," << line << ")" << endl;
    } else if(type == TokenType::Q_MARK) {
        cout << "(Q_MARK," << quoted(description) << "," << line << ")" << endl;
    } else if(type == TokenType::LEFT_PAREN) {
        cout << "(LEFT_PAREN," << quoted(description) << "," << line << ")" << endl;
    } else if(type == TokenType::RIGHT_PAREN) {
        cout << "(RIGHT_PAREN," << quoted(description) << "," << line << ")" << endl;
    } else if(type == TokenType::MULTIPLY) {
        cout << "(MULTIPLY," << quoted(description) << "," << line << ")" << endl;
    } else if(type == TokenType::ADD) {
        cout << "(ADD," << quoted(description) << "," << line << ")" << endl;
    } else if(type == TokenType::SCHEMES) {
        cout << "(SCHEMES," << quoted(description) << "," << line << ")" << endl;
    } else if(type == TokenType::FACTS) {
        cout << "(FACTS," << quoted(description) << "," << line << ")" << endl;
    } else if(type == TokenType::RULES) {
        cout << "(RULES," << quoted(description) << "," << line << ")" << endl;
    } else if(type == TokenType::QUERIES) {
        cout << "(QUERIES," << quoted(description) << "," << line << ")" << endl;
    } else if(type == TokenType::ID) {
        cout << "(ID," << quoted(description) << "," << line << ")" << endl;
    } else if(type == TokenType::STRING) {
        cout << "(STRING," << quoted(description) << "," << line << ")" << endl;
    } else if(type == TokenType::COMMENT) {
        cout << "(COMMENT," << quoted(description) << "," << line << ")" << endl;
    } else if(type == TokenType::END) {
        cout << "(EOF," << quoted(description) << "," << line << ")" << endl;
    } else if(type == TokenType::UNDEFINED) {
        cout << "(UNDEFINED," << "\"" << description << "\"" << "," << line << ")" << endl;
    }
}

TokenType Token::getType() {
    return type;
}

string Token::getDescription() {
    return description;
}