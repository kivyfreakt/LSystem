#include "src/StandartGrammar.cpp"
#include <iostream>

using namespace std;

int main( int argc, char *argv[]) {

  	StandartGrammar ls("[7]++[7]++[7]++[7]++[7]");

    ls.addConstant('6');
    ls.addConstant('7');
    ls.addConstant('8');
    ls.addConstant('9');
    ls.addRule("6 => 81++91----71[-81----61]++");
    ls.addRule("7 => +81--91[---61--71]+");
    ls.addRule("8 => -61++71[+++81++91]-");
    ls.addRule("9 => --81++++61[+91++++71]--71");
    ls.addRule("1 => ");

    ls.iterate(6);
    cout << ls.getResult();
  return 0;
}
