cmake_minimum_required(VERSION 3.10.2)
project(project_2)

set(CMAKE_CXX_STANDARD 17)

add_executable(project_2 main.cpp
        Automaton.h
        BlockCommentAutomaton.cpp
        BlockCommentAutomaton.h
        ColonAutomaton.cpp
        ColonAutomaton.h
        ColonDashAutomaton.cpp
        ColonDashAutomaton.h
        DatalogProgram.cpp
        DatalogProgram.h
        IDAutomaton.cpp
        IDAutomaton.h
        Lexer.cpp
        Lexer.h
        LineCommentAutomaton.cpp
        LineCommentAutomaton.h
        MatcherAutomaton.cpp
        MatcherAutomaton.h
        Parameter.cpp
        Parameter.h
        Parser.cpp
        Parser.h
        Predicate.cpp
        Predicate.h
        Rule.cpp
        Rule.h
        StringAutomaton.cpp
        StringAutomaton.h
        Token.cpp
        Token.h
        )