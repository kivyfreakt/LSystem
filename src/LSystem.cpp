#include "LSystem.h"

LSystem::LSystem()
{
    window.create(sf::VideoMode(800, 800), "LSystem");
    sf::View myView(sf::Vector2f(0.f,0.f), sf::Vector2f(800.f, 800.f));
    window.setView(myView);
}

int LSystem::checkGrammar(vector<string> rules)
{
    string r = rules[0];
    short pos = r.find(" (");
    if (-1 != pos)
        return 1;
    else
        return 0;
}


void LSystem::addConstant(char constant)
{
    constants.push_back(constant);
}

void LSystem::setStep(float _step)
{
    step = _step;
}

void LSystem::setAngle(float _angle)
{
    angle = _angle;
}

void LSystem::save(string path)
{
    sf::Vector2u windowSize = window.getSize();
    sf::Texture texture;
    texture.create(windowSize.x, windowSize.y);
    texture.update(window);
    sf::Image screenshot = texture.copyToImage();
    screenshot.saveToFile(path);
}

void LSystem::build(string axiom, vector<string> rules, int iterations){
    Filter *result = nullptr;
    if(checkGrammar(rules) == 0)
    {
        StandartGrammar ls(axiom, rules);
        ls.iterate(iterations);
        result = ls.getResult();
    }
    // else{
    //   StochasticGrammar ls(axiom, rules);
    //   ls.iterate(iterations);
    //   result = ls.getResult();
    // }

    turtle.init(step, angle);
    turtle.interpret(result, constants);
}

void LSystem::loop(){
    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        turtle.draw(&window);
        window.display();
    }
}
