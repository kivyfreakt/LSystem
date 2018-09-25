/*
* Simple test app, which use LSystem library
* to draw Sierpinski triangle
*/

#include "LSystem.cpp"
#include <string>
#include <map>

using namespace std;

const float step = 5;
const float angle = 120;
map<char, string> rules = {{'F', "F-G+F+G-F"}, {'G', "GG"}};
map<char, string> inter = {{'F', "move"}, {'G', "move"}, {'+', "turnLeft"}, {'-', "turnRight"}};

int main() {
  LSystem lsystem("F-G-G", rules);
  lsystem.setColor(0,0,255);
  lsystem.iter(6);
  lsystem.interpret(inter, step, angle);
  return 0;
}
