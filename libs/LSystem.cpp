#include "LSystem.h"

LSystem::LSystem(string axiom, vector<LRule> &rul):condition(axiom), rules(rul){
    /* Class Constructor */
    penDown();
}

void LSystem::iterate(const int &iterations = 1){
    for (unsigned int i = 0; i <= iterations ; ++i){
        string new_cond;
        for (int j = 0; j < condition.size(); ++j){
            char cur = condition[j];
            string replacement;
            replacement += cur;
            for (int r = 0; r < rules.size(); ++r){
                if(cur == rules[r].variable){
                    replacement = rules[r].rule;
                    break;
                }
            }
            new_cond += replacement;
          }
        condition = new_cond;
    }
}

void LSystem::interpret(unordered_map<char,string> &actions, const float &step, const float &angle){
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
