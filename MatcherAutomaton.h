#pragma once
#ifndef MATCHERAUTOMATON_H
#define MATCHERAUTOMATON_H
#include "Automaton.h"
#include <iostream>
using namespace std;

//This will be used for COMMA, PERIOD, Q_MARK, LEFT_PAREN, RIGHT_PAREN, MULTIPLY, ADD, SCHEMES, FACTS, RULES, QUERIES
class MatcherAutomaton :
        public Automaton
{
private:
    string toMatch;
public:
    MatcherAutomaton(string toMatch, TokenType tokenType);
    void S0(const string& input);
};

#endif
