/*
* The class that produces the development
* of the lsystem in accordance with its rules.
*/

#include "LRule.cpp"
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class LSystem{
  public:
    LSystem(string, vector<string>);
    LSystem(vector<string>);
    LSystem(string);
    LSystem();
    void addRule(string);
    void setAxiom(const string &);
    void addConstant(char);
    string getResult();
  protected:
    string condition; // condition of the lsystem
    vector<string> rules; // rules of the lsystem
    vector<char> constants; // constants of the lsystem
};
