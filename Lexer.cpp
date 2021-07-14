#include "Lexer.h"
#include "ColonAutomaton.h"
#include "ColonDashAutomaton.h"
#include "MatcherAutomaton.h"
#include "LineCommentAutomaton.h"
#include "BlockCommentAutomaton.h"
#include "IDAutomaton.h"
#include "StringAutomaton.h"

Lexer::Lexer() {
    CreateAutomata();
}

Lexer::~Lexer() {
    // TODO: need to clean up the memory in `automata` and `tokens`
    for(unsigned int i = 0; i < tokens.size(); i++){
        delete tokens.at(i);
    }
    for(unsigned int j = 0; j < automata.size(); j++){
        //delete automata.at(j);
    }
    /*for(unsigned int i = 0; i < automata.size(); i++){
        delete automata.at(i);
    }*/
}

void Lexer::CreateAutomata() {
    automata.push_back(new ColonAutomaton());
    automata.push_back(new ColonDashAutomaton());
    automata.push_back(new LineCommentAutomaton());
    automata.push_back(new BlockCommentAutomaton());
    automata.push_back(new StringAutomaton());
    automata.push_back(new MatcherAutomaton(",", TokenType::COMMA));
    automata.push_back(new MatcherAutomaton(".", TokenType::PERIOD));
    automata.push_back(new MatcherAutomaton("?", TokenType::Q_MARK));
    automata.push_back(new MatcherAutomaton("(", TokenType::LEFT_PAREN));
    automata.push_back(new MatcherAutomaton(")", TokenType::RIGHT_PAREN));
    automata.push_back(new MatcherAutomaton("*", TokenType::MULTIPLY));
    automata.push_back(new MatcherAutomaton("+", TokenType::ADD));
    automata.push_back(new MatcherAutomaton("Schemes", TokenType::SCHEMES));
    automata.push_back(new MatcherAutomaton("Facts", TokenType::FACTS));
    automata.push_back(new MatcherAutomaton("Rules", TokenType::RULES));
    automata.push_back(new MatcherAutomaton("Queries", TokenType::QUERIES));
    automata.push_back(new IDAutomaton());
}

void Lexer::printTokens() {
    for(unsigned int i = 0; i < tokens.size(); i++){
        tokens[i]->toString();
    }
    cout << "Total Tokens = " << tokens.size();
}

void Lexer::Run(std::string& input) {
    // TODO: convert this pseudo-code with the algorithm into actual C++ code

    //set lineNumber to 1
    unsigned int lineNumber = 1;
    // While there are more characters to tokenize
    while (input.size() > 0) {
        int maxRead = 0;
        Automaton *maxAutomaton = automata[0];
        while (isspace(input[0])) {
            if (input[0] == '\n') {
                lineNumber++;
            }
            input.erase(0, 1);
        }
        for (unsigned int i = 0; i < automata.size(); i++) {
            unsigned int inputRead = automata[i]->Start(input);
            if ((int)inputRead > maxRead) {
                maxRead = inputRead;
                maxAutomaton = automata[i];
            }
        }
        if (maxRead > 0) {
            Token *newToken = maxAutomaton->CreateToken(input.substr(0, maxRead), lineNumber);
            lineNumber = lineNumber + maxAutomaton->NewLinesRead();
            if(input.substr(0, 1) != "#"){
                tokens.push_back(newToken);
            }
        } else {
            maxRead = 1;
            if ((int)input.size() > 0) {
                Token *undefinedToken = new Token(TokenType::UNDEFINED, input.substr(0, maxRead), lineNumber);
                tokens.push_back(undefinedToken);
            }
        }
        input.erase(0, maxRead);
    }
    Token *endOfFile = new Token(TokenType::END, input.substr(0, 1), lineNumber);
    tokens.push_back(endOfFile);
}

vector<Token*> Lexer::getTokens() {
    return tokens;
}
/*loop while input.size() > 0 {
    set maxRead to 0
    set maxAutomaton to the first automaton in automata

    // TODO: you need to handle whitespace in between tokens(\t,\n,' ')

    // Here is the "Parallel" part of the algorithm
    //   Each automaton runs with the same input
    foreach automaton in automata {
        inputRead = automaton.Start(input)
        if (inputRead > maxRead) {
            set maxRead to inputRead
            set maxAutomaton to automaton
        }
    }
    // Here is the "Max" part of the algorithm
    if maxRead > 0 {
        set newToken to maxAutomaton.CreateToken(...)
            increment lineNumber by maxAutomaton.NewLinesRead()
            add newToken to collection of all tokens
    }
    // No automaton accepted input
    // Create single character undefined token
    else {
        set maxRead to 1
            set newToken to a  new undefined Token
            (with first character of input)
            add newToken to collection of all tokens
    }
    // Update `input` by removing characters read to create Token
    remove maxRead characters from input
}
add end of file token to all tokens
*/
