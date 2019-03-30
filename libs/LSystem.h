/*
* The class that produces the development
* of the lsystem in accordance with its rules.
*/
#include "LRule.cpp"
#include "turtle.cpp"
#include <string>
#include <vector>

using namespace std;

class LSystem : public Turtle{
  public:
    LSystem(string, vector<string> &);
    LSystem(vector<string> &);
    LSystem(string);
    LSystem();
    void addRule(string, string);
    void setAxiom(const string &);
    void iterate(const int &);
    string getCondition();
    void interpret(const float &, const float &);
  private:
    void getRules(vector<string> &);
    string condition; // condition of the lsystem
    vector<LRule> rules; // rules of the lsystem
};
