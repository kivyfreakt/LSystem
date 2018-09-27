/*
* Simple test app, which use LSystem library
* to draw Sierpinski triangle
*/

#include "LSystem.cpp"
#include <string>
#include <map>

using namespace std;

const float step = 3.0;
const float angle = 120.0;
map<char, string> rules = {{'F', "F-G+F+G-F"}, {'G', "GG"}};
map<char, string> inter = {{'F', "move"}, {'+', "turnLeft"}, {'-', "turnRight"}, {'G', "move"}};

int main() {
  LSystem lsystem("F-G-G", rules);
  lsystem.setColor(120, 168, 93);
  lsystem.iter(5);
  lsystem.interpret(inter, step, angle);
  return 0;
}
