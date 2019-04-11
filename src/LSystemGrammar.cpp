#pragma once
#include "LSystemGrammar.h"

LSystemGrammar::LSystemGrammar(string axiom, vector<string> rul):condition(axiom),rules(rul){}
LSystemGrammar::LSystemGrammar(vector<string> rul):rules(rul){}
LSystemGrammar::LSystemGrammar(string axiom):condition(axiom){}
LSystemGrammar::LSystemGrammar(){}

void LSystemGrammar::addRule(string rule){
    rules.push_back(rule);
}

void LSystemGrammar::setAxiom(const string &axiom){
    condition = axiom;
}

string LSystemGrammar::getResult(){
  return condition;
}
