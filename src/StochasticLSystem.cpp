#include "StochasticLSystem.h"

void StochasticLSystem::iterate(const int &iterations = 1){
    vector<SLRule> rul = getRules(rules);
    for (unsigned int i = 0; i < iterations ; ++i){
        string new_cond;
        for (int j = 0; j < condition.size(); ++j){
            string cur;
            cur += condition[j];
            string replacement = cur;
            for (auto r : rul){
                bool OK = false;
                if(cur == r.variable && r.probability < 1.0){
                  float random = ((float)rand()/(float)RAND_MAX);
                  OK = random <= r.probability;
                }else if(r.probability == 1.0){
                  OK = true;
                }
                if(OK){
                  replacement = r.rule;
                  break;
                }
            }
            new_cond += replacement;
          }
        condition = new_cond;
    }
}


vector<SLRule> StochasticLSystem::getRules(vector<string> &rul){
  vector<SLRule> v;
  for (auto r : rul){
      auto pos1 = r.find(" => ");
      auto pos2 = r.find(" (");
      auto pos3 = r.find(")");
      if (pos1 != -1 && pos2 != -1){
        string p = r.substr(pos2+2, pos3);
        SLRule n(r.substr(0,pos1), r.substr(pos1+4, pos2), stof(p));
        v.push_back(n);
      }
  }
  return v;
}
