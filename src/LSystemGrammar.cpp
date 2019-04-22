#pragma once
#include "LSystemGrammar.hpp"

LSystemGrammar::LSystemGrammar(string axiom, vector<string> rul):condition(axiom),rules(rul){}

void LSystemGrammar::addRule(string rule){
    rules.push_back(rule);
}

void LSystemGrammar::setAxiom(const string &axiom){
    condition = axiom;
}

string LSystemGrammar::getResult(){
  return condition;
}
