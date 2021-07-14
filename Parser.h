#pragma once
#ifndef PARSER_H
#define PARSER_H
#include <iostream>
#include <vector>
#include "Token.h"
#include "DatalogProgram.h"
#include "Parameter.h"
#include "Predicate.h"
#include "Rule.h"

using namespace std;

class Parser
{
private:
    vector<Token*> tokens;
    int index = 0;
    Predicate currPred;
    Parameter currParam;
    Rule currRule;
    DatalogProgram datalog;

    // TODO: add any other private methods here (if needed)

public:
    Parser(){};
    ~Parser(){};
    void setTokens(vector<Token *> tokens);
    void parse();
    void parseDatalogProgram();
    void parseSchemeList();
    void parseFactList();
    void parseRuleList();
    void parseQueryList();
    void parseScheme();
    void parseFact();
    void parseRule();
    void parseQuery();
    void parseHeadPredicate();
    void parsePredicate();
    void parsePredicateList();
    void parseParameterList();
    void parseStringList();
    void parseIDList();
    void parseParameter();

    // TODO: add other public methods here
};
#endif //PARSER_H
