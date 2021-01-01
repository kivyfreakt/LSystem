#include <vector>
#include <string>
#include <iostream>
#include <ctime>

#include "src/LSystem.h"

using namespace std;

vector<string> rules = {
  "F => F-F++F-F",
};

int main(int argc, char *argv[])
{
  	LSystem ls;

    ls.setStep(0.5);
    ls.setAngle(60.0);

    ls.build("F++F++F", rules, 7);
    
    ls.loop();
  return 0;
}
