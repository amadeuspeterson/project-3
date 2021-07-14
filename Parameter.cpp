#include "Parameter.h"

string Parameter::getName(){
    return name;
}
void Parameter::setName(string newString){
    name = newString;
}

void Parameter::addParameter(string param) {
    domain.insert(param);
}

void Parameter::toString() {
    cout << "Domain(" << domain.size() << "):" << endl;
    for(auto i = domain.begin(); i != domain.end(); ++i){
        cout << "  ";
        cout << *i;
        cout << endl;
    }
}