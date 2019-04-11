#include "LSystem.h"

LSystem::LSystem(){
    SDL_Init(SDL_INIT_VIDEO);

    const short SCREEN_WIDTH = 640;
    const short SCREEN_HEIGHT = 640;

    window = SDL_CreateWindow("LSystem", 0, 30, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_RenderPresent(renderer);
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

    turtle.init(renderer, step, angle);
    turtle.setColor(147, 112, 219);
    turtle.interpret(result, constants);
}

void LSystem::loop(){
    bool quit = false;
    SDL_Event theEvent;
    while (!quit){
      while (SDL_PollEvent(&theEvent)){
        if(theEvent.type == SDL_QUIT){
          quit = true;
        }
      }
      SDL_RenderPresent(renderer);
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
