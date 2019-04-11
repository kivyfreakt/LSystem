#include "src/LSystem.cpp"

using namespace std;

vector<string> rules = {"F => F[+F]F[-F][F] (0.5)", "F => F[+F]F (0.3)", "F => F[-F]F (0.2)"};

int main(int argc, char *argv[]) {
  LSystem plant;
  plant.setStep(1.0);
  plant.setAngle(25.7);
  plant.build("F", rules, 6);
  plant.loop();
  return 0;
}
