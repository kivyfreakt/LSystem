
#pragma once

#include "Turtle.cpp"
#include "StandartGrammar.cpp"
#include "StochasticGrammar.cpp"
#include <SFML/Graphics.hpp>

class LSystem{
  public:
    LSystem();
    int checkGrammar(vector<string>);
    void addConstant(char);
    void setStep(float);
    void setAngle(float);
    void save(string);
    void build(string, vector<string>, int);
    void loop();
  private:
    sf::RenderWindow window;
    Turtle turtle;
    vector <char> constants;
    float step;
    float angle;
};
