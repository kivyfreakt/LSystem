#include "SLRule.cpp"
#include "LSystem.cpp"
#include <ctime>
#include <map>

using namespace std;

class StochasticLSystem : public LSystem{
  public:
    StochasticLSystem(string axiom, vector<string> &rul):LSystem(axiom,rul){}
    StochasticLSystem(vector<string> &rul):LSystem(rul){}
    StochasticLSystem(string axiom):LSystem(axiom){}
    StochasticLSystem():LSystem(){}
    void iterate(const int &);
  private:
    vector<SLRule> getRules(vector<string> &);
    map<float, SLRule> buildRuleRange(vector<SLRule> rules);
};
