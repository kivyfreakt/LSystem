#include "StochasticLSystem.h"

void StochasticLSystem::iterate(const int &iterations = 1){
    vector<LRule> rul = getRules(rules);
    for (unsigned int i = 0; i < iterations ; ++i){
        string new_cond;
    }
}


vector<LRule> StochasticLSystem::getRules(vector<string> &rul){
  vector<LRule> v;
  for (auto r : rul){
      auto pos1 = r.find(" => ");
      auto pos2 = r.find(" (");
      auto pos3 = r.find(")");
      if (pos1 != -1 && pos2 != -1){
        string p = r.substr(pos2+2, pos3);
        LRule n(r.substr(0,pos), r.substr(pos+4, pos2), atof(p.c_str()));
        v.push_back(n);
      }
  }
  return v;
}
