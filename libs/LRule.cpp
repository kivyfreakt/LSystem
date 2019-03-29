#include <string>

using namespace std;

class LRule{
public:
  LRule(char var, string rul){
    variable = var;
    rule = rul;
  };
  char variable;
  string rule;
};
