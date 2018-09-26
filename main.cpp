/*
* Simple test app, which use LSystem library
* to draw Sierpinski triangle
*/

#include "LSystem.cpp"
#include <string>
#include <iostream>
#include <map>
#include <ctime>

using namespace std;

const float step = 2;
const float angle = 25;
map<char, string> rules = {{'X', "F-[[X]+X]+F[+FX]-X"}, {'F', "FF"}};
map<char, string> inter = {{'F', "move"}, {'+', "turnLeft"}, {'-', "turnRight"}, {'[', "save"}, {']', "restore"}};

int main() {
  LSystem lsystem("X", rules);
  // lsystem.setDirection(0);
  lsystem.setColor(120, 168, 93);
  lsystem.iter(5);
  lsystem.moveto(350,0);
  lsystem.interpret(inter, step, angle);
  cout << clock()/1000.0 <<endl;
  return 0;
}
