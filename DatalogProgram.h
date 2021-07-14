#pragma once
#ifndef DATALOGPROGRAM_H
#define DATALOGPROGRAM_H
#include "Predicate.h"
#include "Rule.h"
#include "Parameter.h"

class DatalogProgram{
private:
    vector<Predicate> schemes;
    vector<Predicate> facts;
    vector<Predicate> queries;
    vector<Rule> rules;
public:
    DatalogProgram(){};
    ~DatalogProgram(){};
    void toString();
    void addSchemes(Predicate newPredicate);
    void addFacts(Predicate newPredicate);
    void addQueries(Predicate newPredicate);
    void addRules(Rule newRule);
};


#endif //DATALOGPROGRAM_H
