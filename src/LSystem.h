#ifndef LSYSTEM_H
#define LSYSTEM_H

#include <SFML/Graphics.hpp>

#include "Turtle.h"
#include "StandartGrammar.h"
// #include "StochasticGrammar.cpp"

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

#endif
