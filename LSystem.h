/*
* The class that produces the development
* of the lsystem in accordance with its rules.
*/

#include "turtle.cpp"
#include <string>
#include <map>

using namespace std;

class LSystem : public Turtle{
  public:
    LSystem(string, const map<char,string> &);
    void iter(const int &);
    void interpret(map<char,string> &, const float &, const float &);
  private:
    string condition; // condition of the lsystem
    map<char,string> rules; // rules of the lsystem
};
