#include "LSystem.h"

void LSystem::addConstant(char constant){
      constants.push_back(constant);
}

void LSystem::build(){
  turtle.init(step, angle);//!!!!!!!!!!!!!
  result = lsg.getResult();
  turtle.interpret(result, constants);
}
