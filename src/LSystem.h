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
    void addRule(string);
    void setAxiom(const string &);
    void interpret(const float &, const float &);
  protected:
    string condition; // condition of the lsystem
    vector<string> rules; // rules of the lsystem
};
