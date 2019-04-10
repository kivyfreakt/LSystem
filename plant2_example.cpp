#include "src/StochasticLSystem.cpp"
#include <SDL2/SDL.h>
#include <iostream>

using namespace std;

const float step = 1.0;
const float angle = 25.7;


int main(int argc, char *argv[]) {
  vector<string> rules = {"F => F[+F]F[-F][F] (0.5)", "F => F[+F]F (0.3)", "F => F[-F]F (0.2)"};
  StochasticLSystem plant("F", rules);
  plant.moveto(250,0);
  plant.setColor(67,160,71);
  plant.iterate(6);
  plant.interpret(step, angle);
  plant.flush();
  SDL_Delay(5000);
  return 0;
}
