#include "LSystem.h"

LSystem::LSystem(string axiom, vector<string> &rul):condition(axiom){
    /* Class Constructor */
    for (auto r : rul){
        auto pos = r.find(" => ");
        if (pos != -1){
          string var = r.substr(0,pos);
          string rule = r.substr(pos+4);
          addRule(var, rule);
        }
    }
    penDown();
}

void LSystem::addRule(string name, string rule){
    // to do rules check
    LRule n(name, rule);
    rules.push_back(n);
}

void LSystem::iterate(const int &iterations = 1){
    for (unsigned int i = 0; i <= iterations ; ++i){
        string new_cond;
        for (int j = 0; j < condition.size(); ++j){
            string cur;
            cur += condition[j];
            string replacement = cur;
            for (auto r : rules){
                if(cur == r.variable){
                    replacement = r.rule;
                    break;
                }
            }
            new_cond += replacement;
          }
        condition = new_cond;
    }
}

string LSystem::getCondition(){
    return condition;
}

void LSystem::interpret(const float &step, const float &angle){
    /* interpretation of the alphabet in a certain action turtles */
    for (unsigned int i = 0, size = condition.size(); i < size ; ++i) {
      switch (condition[i]) {
        case '+':
          turnLeft(angle);
        break;
        case '-':
          turnRight(angle);
        break;
        case '[':
          save();
        break;
        case ']':
          restore();
        break;
        default:
          move(step);
        break;
      }
    }
}
