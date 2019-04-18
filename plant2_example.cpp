#include "src/LSystem.cpp"

using namespace std;

// vector<string> rules = {"F => F[+F]F[-F][F] (0.5)", "F => F[+F]F (0.3)", "F => F[-F]F (0.2)"};
vector<string> rules = {"X => F+[[X]-X]-F[-FX]+X", "F => FF"};

int main(int argc, char *argv[]) {
  LSystem plant;
  plant.setStep(5.0);
  plant.setAngle(25.0);
  plant.build("X", rules, 6);
  plant.loop();
  return 0;
}
