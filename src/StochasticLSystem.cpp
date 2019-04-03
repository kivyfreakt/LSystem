#include "StochasticLSystem.h"

void StochasticLSystem::iterate(const int &iterations = 1){
    vector<SLRule> r = getRules(rules);
    auto rul = buildRuleRange(r);
    for (unsigned int i = 0; i < iterations ; ++i){
        string new_cond;
        float random = ((float)rand()/(float)RAND_MAX);
        auto randomRule = rul.lower_bound(random);
        for (int j = 0; j < condition.size(); ++j){
            string cur;
            cur += condition[j];
            string replacement = cur;
            if(randomRule->second.variable == cur){
              replacement = randomRule->second.rule;
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


map<float, SLRule> StochasticLSystem::buildRuleRange(vector<SLRule> rules){
    map<float, SLRule> rulesWithProbability;
    float probability = 0.0;
    for (auto r : rules){
        probability += r.probability;
        rulesWithProbability.insert(make_pair(probability,r));
    }
    return rulesWithProbability;
}
