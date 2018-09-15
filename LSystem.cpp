#include <fstream>
#include <libconfig.h++>

using namespace std;
using namespace libconfig;

ofstream end_file ("test_app.cpp");

#include "LSystem.h"

LSystem::LSystem(){
    end_file << "#include \"turtle.cpp\" \nTurtle turtle; \nint main(){\nturtle.penDown();\nturtle.moveto(500,500);\n";
    config();
}

void LSystem::iter(){
    int i = 0;
    while (i<=iterations) {
      string new_cond;
      for (unsigned int j = 0, size = condition.size(); j < size ; ++j) {
        if(rules.find(condition[j]) != rules.end())
          new_cond += rules[condition[j]];
        else
          new_cond += condition[j];
      }
        condition = new_cond;
      ++i;
    }
}

void LSystem::interpret(){
    for (unsigned int j = 0, size = condition.size(); j < size ; ++j) {
      if(actions.find(condition[j]) != actions.end())
        end_file << actions[condition[j]];
    }
}

LSystem::~LSystem(){
    end_file << "return 0;\n}";
}
