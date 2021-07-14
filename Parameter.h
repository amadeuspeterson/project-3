#ifndef PARAMETER_H
#define PARAMETER_H
#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Parameter {
public:
    Parameter(){};
    ~Parameter(){};
    string getName();
    void setName(string newString);
    void addParameter(string param);
    void toString();
private:
    string name;
    set<string> domain;
};

#endif //PARAMETER_H
