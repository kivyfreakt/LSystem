/*
* The class that produces the development
* of the lsystem in accordance with its rules.
*/

#include "LRule.cpp"
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class LSystemGrammar{
  public:
    LSystemGrammar(string, vector<string>);
    LSystemGrammar(vector<string>);
    LSystemGrammar(string);
    LSystemGrammar();
    void addRule(string);
    void setAxiom(const string &);
    string getResult();
  protected:
    string condition; // condition of the lsystem
    vector<string> rules; // rules of the lsystem
};
