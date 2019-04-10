#include <string>

using namespace std;

class LRule{
public:
  LRule(string var, string rul):variable(var), rule(rul){}
  LRule(string var, string rul, float prob):variable(var), rule(rul), probability(prob){}
  string variable;
  string rule;
  float probability;
};
