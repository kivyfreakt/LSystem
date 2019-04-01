#include <string>

using namespace std;

class SLRule{
public:
  SLRule(string var, string rul, float prob){
    variable = var;
    rule = rul;
    probability = prob;
  };
  SLRule(string var, string rul){
    variable = var;
    rule = rul;
    probability = 1.0;
  };
  string variable;
  string rule;
  float probability;
};
