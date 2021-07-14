#include "MatcherAutomaton.h"

MatcherAutomaton::MatcherAutomaton(string toMatch, TokenType tokenType) {
    this->toMatch = toMatch;
    this->type = tokenType;
}

void MatcherAutomaton::S0(const string& input) {
    bool isMatch = true;
    inputRead = 0; // member variable inherited from Automaton class
    for (int i = 0; i < (int)toMatch.size() && isMatch; i++) {
        if (input[i] != toMatch[i]) {
            isMatch = false;
        }
    }
    if (isMatch) {
        inputRead = toMatch.size();
    }
}