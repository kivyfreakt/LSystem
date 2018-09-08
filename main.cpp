#include "LSystem.h"
#include <string>
#include <map>

using namespace std;

map<string, string> a = {{"F", "F-F++F-F"}};
map<string, string> b = {{"F", "turtle.move(5);\n"}, {"+", "turtle.turnRight(60);\n"}, {"-", "turtle.turnLeft(60);\n"}};

int main() {
  LSystem lsystem("F++F++F",a);
  lsystem.iter(2);
  lsystem.interpret(b);
  lsystem.getCondition();
  return 0;
}
