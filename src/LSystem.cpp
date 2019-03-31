#include "LSystem.h"

LSystem::LSystem(string axiom, vector<string> &rul):condition(axiom),rules(rul){
    /* Class Constructor */
    penDown();
}

LSystem::LSystem(vector<string> &rul):rules(rul){
    /* Class Constructor */
    penDown();
}

LSystem::LSystem(string axiom):condition(axiom){
    /* Class Constructor */
    penDown();
}

LSystem::LSystem(){
    /* Class Constructor */
    penDown();
}


void LSystem::addRule(string rule){
    rules.push_back(rule);
}

void LSystem::setAxiom(const string &axiom){
    condition = axiom;
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
