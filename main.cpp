#include "LSystem.h"
#include <string>
#include <map>

using namespace std;

map<string, string> a = {{"F", "F-F++F-F"}};
map<string, string> b = {{"F", "move(50)"}, {"+", "turnRight(60)"}, {"-", "turnLeft(60)"}};

int main() {
  LSystem lsystem("F++F++F",a);
  lsystem.iter(1);
  lsystem.getCondition();
  lsystem.interpret(b);
  lsystem.getCondition();
  return 0;
}
