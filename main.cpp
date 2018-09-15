#include "LSystem.cpp"

using namespace std;

map<char, string> a = {{'F', "F-G+F+G-F)"}, {'G', "GG"}};
map<char, string> b = {{'F', "turtle.move(5);\n"}, {'G', "turtle.move(5);\n"}, {'+', "turtle.turnRight(120);\n"}, {'-', "turtle.turnLeft(120);\n"}};

int main() {
  LSystem lsystem("F-G-G",a);
  lsystem.iter(5);
  lsystem.interpret(b);
  return 0;
}
