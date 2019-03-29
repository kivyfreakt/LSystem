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

vector<string> rules = {"F -> F-G+F+G-F","G -> GG"};

int main() {
  LSystem sierpinski("F-G-G", rules);
  sierpinski.setColor(120, 168, 93);
  sierpinski.iterate(5);
  sierpinski.interpret(step, angle);
  cout << (float)clock()/CLOCKS_PER_SEC << '\n';
  return 0;
}
