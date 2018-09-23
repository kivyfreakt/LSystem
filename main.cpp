#include "LSystem.cpp"
#include <string>
#include <map>

using namespace std;

float step = 5;
float angle = 120;
map<char, string> rules = {{'F', "F-G+F+G-F"}, {'G', "GG"}};
map<char, string> inter = {{'F', "move"}, {'G', "move"}, {'+', "turnLeft"}, {'-', "turnRight"}};

int main() {
  LSystem lsystem("F-G-G", rules);
  lsystem.setColor(0,0,255);
  lsystem.iter(6);
  lsystem.interpret(inter, step, angle);
  return 0;
}
