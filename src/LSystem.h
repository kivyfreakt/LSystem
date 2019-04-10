/*
* The class that produces the development
* of the lsystem in accordance with its rules.
*/
#include "Turtle.cpp"
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class LSystem : public Turtle{
  public:
    LSystem(string, vector<string>);
    LSystem(vector<string>);
    LSystem(string);
    LSystem();
    void addRule(string);
    void setAxiom(const string &);
    void addConstant(char);
    void interpret(const float &, const float &);
  protected:
    string condition; // condition of the lsystem
    vector<string> rules; // rules of the lsystem
    vector<char> constants; // constants of the lsystem
};
