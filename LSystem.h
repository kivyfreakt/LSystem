#include <string>
#include <map>
#include <fstream>

using namespace std;

ofstream end_file ("test_app.cpp");

class LSystem{
  public:
    LSystem(string, map<char,string>);
    void iter(int);
    void interpret(map<char,string>);
    ~LSystem();
  private:
    string condition;
    map<char,string> rules;
};
