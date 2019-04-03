#include "src/StochasticLSystem.cpp"
#include <ctime>
#include <iostream>

using namespace std;

const float step = 1.0;
const float angle = 25.7;

vector<string> rules = {"F => F[+F]F[-F][F] (0.5)", "F => F[+F]F (0.3)","F => F[-F]F (0.2)"};

int main() {
  StochasticLSystem plant("F", rules);
  plant.moveto(250,0);
  plant.setColor(67,160,71);
  plant.iterate(6);
  plant.interpret(step, angle);
  cout << (float)clock()/CLOCKS_PER_SEC << '\n';
  return 0;
}
