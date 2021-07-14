#ifndef PREDICATE_H
#define PREDICATE_H
#include <iostream>
#include "Parameter.h"

using namespace std;

class Predicate {
public:
    Predicate(){};
    ~Predicate(){};
    void clear();
    string getName();
    vector<Parameter> getParams();
    void setName(string newName);
    void addToParams(Parameter param);
    void toString();
private:
    string name;
    vector<Parameter> params;
};

#endif //PREDICATE_H
