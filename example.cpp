/*
* Simple test app, which use LSystem library
* to draw Sierpinski triangle
*/

#include "libs/LSystem.cpp"
#include <ctime>
#include <iostream>

using namespace std;

const float step = 3.0;
const float angle = 120.0;

LRule F('F', "F-G+F+G-F");
LRule G('G', "GG");

vector<LRule> rules = {F,G};
unordered_map<char, string> inter = {{'F', "move"}, {'+', "turnLeft"}, {'-', "turnRight"}, {'G', "move"}};

int main() {
  LSystem sierpinski("F-G-G", rules);
  sierpinski.setColor(120, 168, 93);
  sierpinski.iterate(5);
  sierpinski.interpret(inter, step, angle);
  return 0;
}
