#pragma once
#ifndef LEXER_H
#define LEXER_H
#include <vector>
#include <cctype>
#include <iostream>
#include "Automaton.h"
#include "Token.h"
using namespace std;

class Lexer
{
private:
    vector<Automaton*> automata;
    vector<Token*> tokens;

    void CreateAutomata();

    // TODO: add any other private methods here (if needed)

public:
    Lexer();
    ~Lexer();

    void Run(string& input);

    // TODO: add other public methods here
    void printTokens();
    vector<Token*> getTokens();
};

#endif // LEXER_H

