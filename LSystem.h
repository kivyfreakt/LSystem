#include <string>
#include <map>

using namespace std;

class LSystem{
  public:
    LSystem(string axiom, map<string,string>rul){
      condition = axiom;
      rules = rul;
    }

    void iter(int n){
      int i = 1;
      while (i<=n) {
        for (map<string,string>::iterator it = rules.begin(); it != rules.end(); it++) {
          string s1 = (*it).first;
          string s2 = (*it).second;
          replaceString(condition, s1, s2);
        }
      }
    }

    string replaceString(string subject, const string& search,
                          const std::string& replace) {
    size_t pos = 0;
    while ((pos = subject.find(search, pos)) != string::npos) {
         subject.replace(pos, search.length(), replace);
         pos += replace.length();
    }
    return subject;
    }

    // void interpret(){
    //
    // }

  private:
    string condition;
    map<string,string> rules;
};
