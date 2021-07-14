#include "DatalogProgram.h"

void DatalogProgram::toString(){
    cout << "Schemes(" << schemes.size() << "):" << endl;
    for(unsigned int i = 0; i < schemes.size(); i++){
        cout << "  ";
        schemes[i].toString();
        cout << endl;
    }
    cout << "Facts(" << facts.size() << "):" << endl;
    for(unsigned int i = 0; i < facts.size(); i++){
        cout << "  ";
        facts[i].toString();
        cout << "." << endl;
    }
    cout << "Rules(" << rules.size() << "):" << endl;
    for(unsigned int i = 0; i < rules.size(); i++){
        cout << "  ";
        rules[i].toString();
        cout << endl;
    }
    cout << "Queries(" << queries.size() << "):" << endl;
    for(unsigned int i = 0; i < queries.size(); i++){
        cout << "  ";
        queries[i].toString();
        cout << "?" << endl;
    }
}
void DatalogProgram::addSchemes(Predicate newPredicate){
    schemes.push_back(newPredicate);
}
void DatalogProgram::addFacts(Predicate newPredicate){
    facts.push_back(newPredicate);
}
void DatalogProgram::addQueries(Predicate newPredicate){
    queries.push_back(newPredicate);
}
void DatalogProgram::addRules(Rule newRule){
    rules.push_back(newRule);
}