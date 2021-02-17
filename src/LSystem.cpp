#include "LSystem.h"

LSystem::LSystem()
{
    window.create(sf::VideoMode(800, 800), "LSystem");
    window.setVerticalSyncEnabled(true);
    sf::View view(sf::Vector2f(0.f,0.f), sf::Vector2f(800.f, 800.f));
    window.setView(view);
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
    else{
        StochasticGrammar ls(axiom, rules);
        ls.iterate(iterations);
        result = ls.getResult();
    }

    turtle.init(step, angle);
    turtle.interpret(result, constants);
}

void LSystem::loop(){
    sf::Event event;
    float w, h;
    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::Closed:
                    window.close();
                break;
                case sf::Event::Resized:
                    w = static_cast<float>(event.size.width);
                    h = static_cast<float>(event.size.height);
                    window.setView(
                        sf::View(
                            sf::Vector2f(w / 2.0, h / 2.0),
                            sf::Vector2f(w, h)
                        )
                    );
                break;
                case sf::Event::MouseWheelScrolled:
                    sf::View view = window.getView();
                    if (event.mouseWheelScroll.delta > 0)
                        view.zoom(0.99);
                    else
                        view.zoom(1.01);
                    window.setView(view);
                break;
            }
        }
        window.clear();
        turtle.draw(&window);
        window.display();
    }
}
