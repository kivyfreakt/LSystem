#include <iostream>
#include <cmath>
using namespace std;


#include "turtle2.h"

Turtle2::Turtle2(){
  /* Class Constructor */
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	 cout << "SDL_Init Error: " << SDL_GetError() << endl;
   window = SDL_CreateWindow("lsystem", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
   renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

// --------------- Getters and Setters ---------------
float Turtle2::getCoord(short coord) {
  if (coord == 0)
    return x;
  else
    return y;
}

void Turtle2::setCoords(float nx, float ny) {
  x = nx;
  y = ny;
}

float Turtle2::getDirection() {
  return direction;
}

void Turtle2::setDirection(float ndirection) {
  direction = ndirection;
}

int Turtle2::getWidth() {
  return width;
}

void Turtle2::setWidth(int wd){
  width = wd;
}

bool Turtle2::getPen() {
  return pen;
}

void Turtle2::setPen(bool npen) {
  pen = npen;
}

// --------------- Methods of movement ---------------

void Turtle2::moveto(float x1, float y1){
  /* Move the turtle to a point with coordinates (x,y) */
  setCoords(x1,y1);
}

void Turtle2::move(float distance){
  /* Crawl distance steps forward */
  // calculate the new coordinates of the turtle
  float x1 = getCoord(0) + distance * cos(getDirection() * M_PI / 180);
  float y1 = getCoord(1) + distance * sin(getDirection() * M_PI / 180);


  if (getPen())
    drawLine(x1, y1);

  // set the new coordinates of the turtle
  setCoords(x1, y1);
}

void Turtle2::turnRight(float angle){
  /* Turn the turtle to the right side */
    setDirection(getDirection()-angle);
}

void Turtle2::turnLeft(float angle){
  /* Turn the turtle to the left side */
    setDirection(getDirection()+angle);
}

void Turtle2::save(){
  save_stack.push(getCoord(0));
  save_stack.push(getCoord(1));
  save_stack.push(getDirection());
}

void Turtle2::restore(){
  setDirection(save_stack.top());
  save_stack.pop();
  float ny = save_stack.top();
  save_stack.pop();
  float nx = save_stack.top();
  save_stack.pop();
  setCoords(nx, ny);
}

void Turtle2::reset(){
  /* Returns the turtle to its original position */
  setCoords(0.0, 0.0);
  setDirection(90.0);
}

// --------------- Drawing methods ---------------
void Turtle2::clear(){
  SDL_RenderClear(renderer);
}

void Turtle2::flush(){
  SDL_RenderPresent(renderer);
}

void Turtle2::penDown(){
  /* Lowers the pen-the turtle, after which
   * she leaves a trail when moving
   */
   setPen(true);
}

void Turtle2::penUp(){
  /* Lifts the pen the turtle, after which
   * it ceases to leave a trail when moving
   */
   setPen(false);
}


void Turtle2::drawLine(float x1, float y1){
  /* Draws the path of the turtle if the pen is omitted */
  SDL_RenderDrawLine(renderer,x,y,x1,y1);
}


void Turtle2::setColor(int red, int green, int blue){
  /* Change the color of the turtle feather */
  if (red <= 255 && green <= 255 && blue <= 255) {
    SDL_SetRenderDrawColor(renderer, red, green, blue, 255);
  }
}


Turtle2::~Turtle2(){
  /* Class Deconstructor */
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}
