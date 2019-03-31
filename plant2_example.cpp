#include "src/StochasticLSystem.cpp"
#include <ctime>
#include <iostream>

using namespace std;

const float step = 3.0;
const float angle = 45.0;

vector<string> rules = {"F => F[+FF]F[-F]F (0.5)", "F => F[+F]F (0.25)","F => F[-FF]F (0.25)"};

int main() {
  StochasticLSystem plant("F", rules);
  plant.moveto(250,250);
  plant.setColor(147, 112, 219);
  plant.iterate(7);
  plant.interpret(step, angle);
  cout << (float)clock()/CLOCKS_PER_SEC << '\n';
  return 0;
}
