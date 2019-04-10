#include "src/StochasticGrammar.cpp"
#include <iostream>

using namespace std;

vector<string> rules = {"F => F[+F]F[-F][F] (0.5)", "F => F[+F]F (0.3)", "F => F[-F]F (0.2)"};

int main(int argc, char *argv[]) {
  StochasticLSystem plant("F", rules);
  plant.iterate(5);
  cout<<plant.getResult();
  return 0;
}
