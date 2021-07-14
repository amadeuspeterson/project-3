#ifndef RULE_H
#define RULE_H
#include <iostream>
#include <vector>
#include "Predicate.h"

class Rule {
public:
    Rule(){};
    ~Rule(){};
    void clear();
    Predicate getHeadPredicate();
    vector<Predicate> getBodyPredicates();
    void setHeadPredicate(Predicate newHead);
    void addToBodyPredicates(Predicate pred);
    void toString();
private:
    Predicate headPredicate;
    vector<Predicate> bodyPredicates;
};

#endif //RULE_H
