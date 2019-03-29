/*
* The class that produces the development
* of the lsystem in accordance with its rules.
*/
#include "LRule.cpp"
#include "turtle.cpp"
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class LSystem : public Turtle{
  public:
    LSystem(string, vector<LRule> &);
    void iterate(const int &);
    void interpret(unordered_map<char,string> &, const float &, const float &);
  private:
    string condition; // condition of the lsystem
    vector<LRule> rules; // rules of the lsystem
};
