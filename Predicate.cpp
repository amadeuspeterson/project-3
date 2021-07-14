#include "Predicate.h"

void Predicate::clear() {
    params.clear();
}

string Predicate::getName() {
    return name;
}

vector<Parameter> Predicate::getParams(){
    return params;
}

void Predicate::setName(string newName) {
    name = newName;
}

void Predicate::addToParams(Parameter param) {
    params.push_back(param);
}

void Predicate::toString() {
    cout << name;
    for(unsigned int i = 0; i < params.size(); i++){
        if ((params.size() - 1) == 0) {
            cout << "(" << params[i].getName() << ")";
        } else if(i == 0) {
            cout << "(" << params[i].getName();
        } else if (i == (params.size() - 1)){
            cout << "," << params[i].getName() << ")";
        } else {
            cout << "," << params[i].getName();
        }
    }
}