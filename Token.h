#pragma once
#ifndef TOKEN_H
#define TOKEN_H
#include <string>
#include <iostream>

using namespace std;

enum class TokenType {
    COLON,
    COLON_DASH,
    COMMA,
    PERIOD,
    Q_MARK,
    LEFT_PAREN,
    RIGHT_PAREN,
    MULTIPLY,
    ADD,
    SCHEMES,
    FACTS,
    RULES,
    QUERIES,
    ID,
    STRING,
    COMMENT,
    UNDEFINED,
    END
};

class Token
{
private:
    // TODO: add member variables for information needed by Token
    unsigned int line = 0;
    string description;
    TokenType type;
public:
    Token(TokenType type, string description, int line);

    // TODO: add other needed methods
    void toString();

    TokenType getType();
    string getDescription();
};

#endif // TOKEN_H

