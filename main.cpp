#include "LSystem.h"
#include <string>
#include <map>

using namespace std;

map<char, string> a = {{'A', "B-A-B"}, {'B', "A+B+A"}};
map<char, string> b = {{'A', "turtle.move(1);\n"}, {'B', "turtle.move(1);\n"}, {'+', "turtle.turnLeft(60);\n"}, {'-', "turtle.turnRight(60);\n"}};

int main() {
  LSystem lsystem("A",a);
  lsystem.iter(6);
  lsystem.interpret(b);
  return 0;
}
