#include "src/StandartLSystem.cpp"
#include <iostream>
#include <SDL2/SDL.h>

using namespace std;

const float step = 9.0;
const float angle = 36.0;

int main( int argc, char *argv[]) {
    SDL_Init(SDL_INIT_VIDEO);


    SDL_Window* window = SDL_CreateWindow("LSystem", 0, 30, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

  	//gets the size of the user's screen
  	SDL_DisplayMode currentDisplayMode;
  	SDL_GetCurrentDisplayMode(0, &currentDisplayMode);
  	SCREEN_WIDTH = currentDisplayMode.w;
  	SCREEN_HEIGHT = currentDisplayMode.h-75;

  	StandartLSystem ls("[7]++[7]++[7]++[7]++[7]");

    ls.addConstant('6');
    ls.addConstant('7');
    ls.addConstant('8');
    ls.addConstant('9');
    ls.addRule("6 => 81++91----71[-81----61]++");
    ls.addRule("7 => +81--91[---61--71]+");
    ls.addRule("8 => -61++71[+++81++91]-");
    ls.addRule("9 => --81++++61[+91++++71]--71");
    ls.addRule("1 => ");

    ls.moveto(250,250);

    ls.setColor(147, 112, 219);
    ls.iterate(6);
    ls.interpret(step, angle);
    ls.flush();
    SDL_Delay(5000);

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
  return 0;
}
