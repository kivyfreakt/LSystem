#include "turtle.cpp"
#include <string>
#include <map>

using namespace std;

class LSystem : public Turtle{
  public:
    LSystem(string, map<char,string>);
    void iter(int);
    void interpret(map<char,string>, float, float);
  private:
    string condition;
    map<char,string> rules;
};
