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

    ls.setStep(0.0005);
    ls.setAngle(60.0);

    clock_t start = clock();
    ls.build("F++F++F", rules, 12);
    clock_t end = clock();

    cout << 1000*(((double)(end - start))/CLOCKS_PER_SEC);
    ls.loop();
  return 0;
}
