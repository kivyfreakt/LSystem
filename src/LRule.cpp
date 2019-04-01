#include <string>

using namespace std;

class LRule{
public:
  LRule(string var, string rul){
    variable = var;
    rule = rul;
  };
  string variable;
  string rule;
};
