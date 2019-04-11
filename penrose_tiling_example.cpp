#include "src/LSystem.cpp"

using namespace std;

vector<string> rules = {
  "6 => 81++91----71[-81----61]++",
  "7 => +81--91[---61--71]+",
  "8 => -61++71[+++81++91]-",
  "9 => --81++++61[+91++++71]--71",
  "1 => "
};

int main( int argc, char *argv[]) {
  	LSystem ls;

    ls.addConstant('6');
    ls.addConstant('7');
    ls.addConstant('8');
    ls.addConstant('9');

    ls.setStep(1.0);
    ls.setAngle(36.0);

    ls.build("[7]++[7]++[7]++[7]++[7]", rules, 5);
    ls.loop();
  return 0;
}
