/*
* Simple test app, which use LSystem library
* to draw gosper curve
*/

#include "src/StandartLSystem.cpp"
#include <ctime>
#include <iostream>

using namespace std;

const float step = 3.0;
const float angle = 60.0;

vector<string> rules = {"A => A-B--B+A++AA+B-"};

int main() {
  StandartLSystem gosper("A", rules);
  gosper.moveto(250,250);
  gosper.addRule("B => +A-BB--B-A++A+B");
  gosper.setColor(147, 112, 219);
  gosper.iterate(3);
  gosper.interpret(step, angle);
  cout << (float)clock()/CLOCKS_PER_SEC << '\n';
  return 0;
}
