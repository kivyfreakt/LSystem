#include <fstream>

using namespace std;

ofstream end_file ("test_app.cpp");

#include "LSystem.h"

LSystem::LSystem(string axiom, map<char,string>rul){
    condition = axiom;
    rules = rul;

    end_file << "#include'turtle.cpp' \nTurtle turtle; \nint main(){\nturtle.penDown();\nturtle.moveto(500,500);\n";
}

void LSystem::iter(int n){
  int i = 0;
  while (i<=n) {
    string new_cond;
    for (int j = 0; j < condition.size(); j++) {
      if(rules.find(condition[j]) != rules.end())
        new_cond += rules[condition[j]];
      else
        new_cond +=  condition[j];
    }
      condition = new_cond;
    i++;
  }
}

void LSystem::interpret(map<char,string> actions){
    string new_cond;
    for (int j = 0; j < condition.size(); j++) {
      if(actions.find(condition[j]) != actions.end())
        end_file << actions[condition[j]];
    }
}

string LSystem::replaceString(string subject, const string& search,
                      const std::string& replace) {
    size_t pos = 0;
    while ((pos = subject.find(search, pos)) != string::npos) {
         subject.replace(pos, search.length(), replace);
         pos += replace.length();
    }
    return subject;
}

LSystem::~LSystem(){
  end_file << "return 0;\n}";
}
