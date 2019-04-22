#pragma once

#include "LSystemGrammar.cpp"

using namespace std;

class StandartGrammar : public LSystemGrammar{
  public:
    StandartGrammar(string axiom, vector<string> rul):LSystemGrammar(axiom,rul){}
    void iterate(const int);
  private:
    vector<LRule> getRules(vector<string> &);
};
