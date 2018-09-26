#include "LSystem.h"

LSystem::LSystem(string axiom, const map<char,string> &rul):condition(axiom), rules(rul){
    /* Class Constructor */
    penDown();
}

void LSystem::iter(const int &iterations){
    /* the development of the lsystem */
    int i = 0;
    while (i<=iterations) {
      string new_cond;
      for (unsigned int j = 0, size = condition.size(); j < size ; ++j) {
        if(rules.find(condition[j]) != rules.end())
          new_cond += rules[condition[j]];
        else
          new_cond += condition[j];
      }
        condition = new_cond;
      ++i;
    }
}

void LSystem::interpret(map<char,string> &actions, const float &step, const float &angle){
    /* interpretation of the alphabet in a certain action turtles */
    for (unsigned int i = 0, size = condition.size(); i < size ; ++i) {
      if(actions.find(condition[i]) != actions.end())
          if ("move" == actions[condition[i]]){
            move(step);
          } else if ("turnLeft" == actions[condition[i]]){
            turnLeft(angle);
          } else if ("turnRight" == actions[condition[i]]){
            turnRight(angle);
          } else if ("save" == actions[condition[i]]){
            save();
          } else if ("restore" == actions[condition[i]]){
            restore();
          }
    }
}
