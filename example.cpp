/*
* Simple test app, which use LSystem library
* to draw Sierpinski triangle
*/

#include "libs/LSystem.cpp"
#include <string>
#include <map>

using namespace std;

const float step = 3.0;
const float angle = 120.0;
map<char, string> rules = {{'F', "F-G+F+G-F"}, {'G', "GG"}};
map<char, string> inter = {{'F', "move"}, {'+', "turnLeft"}, {'-', "turnRight"}, {'G', "move"}};

int main() {
  LSystem sierpinski("F-G-G", rules);
  sierpinski.setColor(120, 168, 93);
  sierpinski.iter(5);
  sierpinski.interpret(inter, step, angle);
  return 0;
}
