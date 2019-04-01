#include "LRule.cpp"
#include "LSystem.cpp"

using namespace std;

class StandartLSystem : public LSystem{
  public:
    StandartLSystem(string axiom, vector<string> &rul):LSystem(axiom,rul){}
    StandartLSystem(vector<string> &rul):LSystem(rul){}
    StandartLSystem(string axiom):LSystem(axiom){}
    StandartLSystem():LSystem(){}
    void iterate(const int &);
  private:
    vector<LRule> getRules(vector<string> &);
};
