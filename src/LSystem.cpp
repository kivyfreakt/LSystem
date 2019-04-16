#include "LSystem.hpp"

LSystem::LSystem(){
  window.setSize(sf::Vector2u(640, 480));
}

int LSystem::checkGrammar(vector<string> rules){
  string r = rules[0];
  short pos = r.find(" (");
  if (-1 != pos)
    return 1;
  else
    return 0;
}


void LSystem::addConstant(char constant){
    constants.push_back(constant);
}

void LSystem::setStep(float _step){
  step = _step;
}

void LSystem::setAngle(float _angle){
  angle = _angle;
}

void LSystem::build(string axiom, vector<string> rules, int iterations){
    string result;
    if(checkGrammar(rules) == 0){
      StandartGrammar ls(axiom, rules);
      ls.iterate(iterations);
      result = ls.getResult();
    }
    else{
      StochasticGrammar ls(axiom, rules);
      ls.iterate(iterations);
      result = ls.getResult();
    }

    turtle.init(step, angle);
    turtle.moveto(250,250);
    turtle.interpret(&window, result, constants);
}

void LSystem::loop(){
  while (window.isOpen())
  {
      sf::Event event;
      while (window.pollEvent(event))
      {
          if (event.type == sf::Event::Closed)
              window.close();
      }
      window.clear(sf::Color::Black);

      window.display();
  }
}
