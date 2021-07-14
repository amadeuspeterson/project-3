#include "Parser.h"

void Parser::setTokens(vector<Token *> tokens) {
    Parser::tokens = tokens;
}

void Parser::parse() {
    try{
        parseDatalogProgram();
    } catch(Token* error) {
        cout << "Failure!" << endl;
        error->toString();
    }
}

void Parser::parseDatalogProgram(){
    if(tokens[index]->getType() == TokenType::SCHEMES) {
        index++;
    } else {
        throw tokens[index];
    }
    if(tokens[index]->getType() == TokenType::COLON) {
        index++;
    } else {
        throw tokens[index];
    }
    parseScheme();
    parseSchemeList();
    if(tokens[index]->getType() == TokenType::FACTS) {
        index++;
    } else {
        throw tokens[index];
    }
    if(tokens[index]->getType() == TokenType::COLON) {
        index++;
    } else {
        throw tokens[index];
    }
    parseFactList();
    if(tokens[index]->getType() == TokenType::RULES) {
        index++;
    } else {
        throw tokens[index];
    }
    if(tokens[index]->getType() == TokenType::COLON) {
        index++;
    } else {
        throw tokens[index];
    }
    parseRuleList();
    if(tokens[index]->getType() == TokenType::QUERIES) {
        index++;
    } else {
        throw tokens[index];
    }
    if(tokens[index]->getType() == TokenType::COLON) {
        index++;
    } else {
        throw tokens[index];
    }
    parseQuery();
    parseQueryList();
    if(tokens[index]->getType() == TokenType::END) {
        cout << "Success!" << endl;
        datalog.toString();
        currParam.toString();
    }
}
void Parser::parseSchemeList(){
    while(tokens[index]->getType() != TokenType::FACTS){
        parseScheme();
        parseSchemeList();
    }
}
void Parser::parseFactList(){
    while(tokens[index]->getType() != TokenType::RULES){
        parseFact();
        parseFactList();
    }
}
void Parser::parseRuleList(){
    while(tokens[index]->getType() != TokenType::QUERIES){
        parseRule();
        parseRuleList();
    }
}
void Parser::parseQueryList(){
    while(tokens[index]->getType() != TokenType::END){
        parseQuery();
        parseQueryList();
    }
}
void Parser::parseScheme(){
    if(tokens[index]->getType() == TokenType::ID) {
        currPred.clear();
        currPred.setName(tokens[index]->getDescription());
        index++;
    } else {
        throw tokens[index];
    }
    if(tokens[index]->getType() == TokenType::LEFT_PAREN){
        index++;
    } else {
        throw tokens[index];
    }
    if(tokens[index]->getType() == TokenType::ID) {
        currParam.setName(tokens[index]->getDescription());
        currPred.addToParams(currParam);
        index++;
    } else {
        throw tokens[index];
    }
    parseIDList();
    if(tokens[index]->getType() == TokenType::RIGHT_PAREN){
        datalog.addSchemes(currPred);
        index++;
    } else {
        throw tokens[index];
    }
}
void Parser::parseFact(){
    if(tokens[index]->getType() == TokenType::ID) {
        currPred.clear();
        currPred.setName(tokens[index]->getDescription());
        index++;
    } else {
        throw tokens[index];
    }
    if(tokens[index]->getType() == TokenType::LEFT_PAREN){
        index++;
    } else {
        throw tokens[index];
    }
    if(tokens[index]->getType() == TokenType::STRING) {
        currParam.setName(tokens[index]->getDescription());
        currPred.addToParams(currParam);
        currParam.addParameter(tokens[index]->getDescription());
        index++;
    } else {
        throw tokens[index];
    }
    parseStringList();
    if(tokens[index]->getType() == TokenType::RIGHT_PAREN){
        index++;
    } else {
        throw tokens[index];
    }
    if(tokens[index]->getType() == TokenType::PERIOD){
        datalog.addFacts(currPred);
        index++;
    } else {
        throw tokens[index];
    }
}
void Parser::parseRule(){
    parseHeadPredicate();
    currRule.setHeadPredicate(currPred);
    if(tokens[index]->getType() == TokenType::COLON_DASH){
        index++;
    } else {
        throw tokens[index];
    }
    parsePredicate();
    parsePredicateList();
    datalog.addRules(currRule);
    if(tokens[index]->getType() == TokenType::PERIOD){
        index++;
    } else {
        throw tokens[index];
    }
}
void Parser::parseQuery(){
    parsePredicate();
    if(tokens[index]->getType() == TokenType::Q_MARK){
        datalog.addQueries(currPred);
        index++;
    } else {
        throw tokens[index];
    }
}
void Parser::parseHeadPredicate(){
    if(tokens[index]->getType() == TokenType::ID){
        currRule.clear();
        currPred.clear();
        currPred.setName(tokens[index]->getDescription());
        index++;
    } else {
        throw tokens[index];
    }
    if(tokens[index]->getType() == TokenType::LEFT_PAREN){
        index++;
    } else {
        throw tokens[index];
    }
    if(tokens[index]->getType() == TokenType::ID){
        currParam.setName(tokens[index]->getDescription());
        currPred.addToParams(currParam);
        index++;
    } else {
        throw tokens[index];
    }
    parseIDList();
    if(tokens[index]->getType() == TokenType::RIGHT_PAREN){
        index++;
    } else {
        throw tokens[index];
    }
}
void Parser::parsePredicate(){
    if(tokens[index]->getType() == TokenType::ID){
        currPred.clear();
        currPred.setName(tokens[index]->getDescription());
        index++;
    } else {
        throw tokens[index];
    }
    if(tokens[index]->getType() == TokenType::LEFT_PAREN){
        index++;
    } else {
        throw tokens[index];
    }
    parseParameter();
    parseParameterList();
    if(tokens[index]->getType() == TokenType::RIGHT_PAREN){
        currRule.addToBodyPredicates(currPred);
        index++;
    } else {
        throw tokens[index];
    }
}
void Parser::parsePredicateList() {
    while (tokens[index]->getType() != TokenType::PERIOD) {
        if (tokens[index]->getType() == TokenType::COMMA) {
            index++;
        } else {
            throw tokens[index];
        }
        parsePredicate();
        parsePredicateList();
    }
}
void Parser::parseParameterList(){
    while (tokens[index]->getType() != TokenType::RIGHT_PAREN) {
        if (tokens[index]->getType() == TokenType::COMMA) {
            index++;
        } else {
            throw tokens[index];
        }
        parseParameter();
        parseParameterList();
    }
}
void Parser::parseStringList(){
    while (tokens[index]->getType() != TokenType::RIGHT_PAREN) {
        if (tokens[index]->getType() == TokenType::COMMA) {
            index++;
        } else {
            throw tokens[index];
        }
        if (tokens[index]->getType() == TokenType::STRING) {
            currParam.setName(tokens[index]->getDescription());
            currPred.addToParams(currParam);
            currParam.addParameter(tokens[index]->getDescription());
            index++;
        } else {
            throw tokens[index];
        }
        parseStringList();
    }
}
void Parser::parseIDList(){
    while (tokens[index]->getType() != TokenType::RIGHT_PAREN) {
        if (tokens[index]->getType() == TokenType::COMMA) {
            index++;
        } else {
            throw tokens[index];
        }
        if (tokens[index]->getType() == TokenType::ID) {
            currParam.setName(tokens[index]->getDescription());
            currPred.addToParams(currParam);
            index++;
        } else {
            throw tokens[index];
        }
        parseIDList();
    }
}
void Parser::parseParameter(){
    if (tokens[index]->getType() == TokenType::STRING) {
        currParam.setName(tokens[index]->getDescription());
        currPred.addToParams(currParam);
        index++;
    } else if (tokens[index]->getType() == TokenType::ID) {
        currParam.setName(tokens[index]->getDescription());
        currPred.addToParams(currParam);
        index++;
    } else {
        throw tokens[index];
    }
}