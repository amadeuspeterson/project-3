#include "Rule.h"

void Rule::clear(){
    bodyPredicates.clear();
}
Predicate Rule::getHeadPredicate(){
    return headPredicate;
}
vector<Predicate> Rule::getBodyPredicates(){
    return bodyPredicates;
}
void Rule::setHeadPredicate(Predicate newHead){
    headPredicate = newHead;
}
void Rule::addToBodyPredicates(Predicate pred){
    bodyPredicates.push_back(pred);
}
void Rule::toString(){
    headPredicate.toString();
    cout << " :- ";
    for (unsigned int i = 0; i < bodyPredicates.size(); i++){
        if(i == (bodyPredicates.size() - 1)){
            bodyPredicates[i].toString();
            cout << ".";
        } else {
            bodyPredicates[i].toString();
            cout << ",";
        }
    }
}