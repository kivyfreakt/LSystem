#pragma once

#include "LSystemGrammar.cpp"
#include <ctime>
#include <map>

using namespace std;

class StochasticGrammar : public LSystemGrammar{
  public:
    StochasticGrammar(string axiom, vector<string> rul):LSystemGrammar(axiom,rul){}
    void iterate(int);
  private:
    vector<LRule> getRules(vector<string> &);
    map<float, LRule> buildRuleRange(const vector<LRule> &rules);
};
