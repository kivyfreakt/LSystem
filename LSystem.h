#include <string>
#include <map>
#include <fstream>

using namespace std;

ofstream end_file ("test_app.cpp");

class LSystem {
  public:
    LSystem(string axiom, map<string,string>rul){
      condition = axiom;
      rules = rul;
    }

    void iter(int n){
      int i = 0;
      while (i<=n) {
        for (map<string,string>::iterator it = rules.begin(); it != rules.end(); it++) {
          string s1 = (*it).first;
          string s2 = (*it).second;
          condition = replaceString(condition, s1, s2);
        }
        i++;
      }
    }

    void interpret(map<string,string> actions){
        for (map<string,string>::iterator it = actions.begin(); it != actions.end(); it++) {
          string s1 = (*it).first;
          string s2 = (*it).second;
          condition = replaceString(condition, s1, s2);
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

    void getCondition(){
      end_file << condition;
    }


  private:
    string condition;
    map<string,string> rules;
};
