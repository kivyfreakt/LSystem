#include <string>
#include <map>

using namespace std;

class LSystem{
  public:
    LSystem(string, map<char,string>);
    void iter(int n);
    void interpret(map<char,string>);
    string replaceString(string, const string&,const string&);
    ~LSystem();

  private:
    string condition;
    map<char,string> rules;
};
