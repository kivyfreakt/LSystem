#include "Turtle.h"

// --------------- Getters and Setters ---------------
float Turtle::getCoord(short coord) {
  if (coord == 0)
    return x;
  else
    return y;
}

void Turtle::setCoords(float nx, float ny) {
  x = nx;
  y = ny;
}

float Turtle::getDirection() {
  return direction;
}

void Turtle::setDirection(float ndirection) {
  direction = ndirection;
}

bool Turtle::getPen() {
  return pen;
}

void Turtle::setPen(bool npen) {
  pen = npen;
}

void Turtle::init(sf::RenderTexture _render, float _step, float _angle){
    render = _render;
    step = _step;
    angle = _angle;
}


// --------------- Methods of movement ---------------

void Turtle::moveto(float x1, float y1){
  /* Move the turtle to a point with coordinates (x,y) */
  setCoords(x1,y1);
}

void Turtle::move(float distance){
  /* Crawl distance steps forward */
  // calculate the new coordinates of the turtle
  float x1 = getCoord(0) + distance * cos(getDirection() * M_PI / 180);
  float y1 = getCoord(1) + distance * sin(getDirection() * M_PI / 180);


  if (getPen())
    drawLine(x1, y1);

  // set the new coordinates of the turtle
  setCoords(x1, y1);
}

void Turtle::turnRight(float angle){
  /* Turn the turtle to the right side */
    setDirection(getDirection()-angle);
}

void Turtle::turnLeft(float angle){
  /* Turn the turtle to the left side */
    setDirection(getDirection()+angle);
}

void Turtle::save(){
  save_stack.push(getCoord(0));
  save_stack.push(getCoord(1));
  save_stack.push(getDirection());
}

void Turtle::restore(){
  setDirection(save_stack.top());
  save_stack.pop();
  float ny = save_stack.top();
  save_stack.pop();
  float nx = save_stack.top();
  save_stack.pop();
  setCoords(nx, ny);
}

void Turtle::reset(){
  /* Returns the turtle to its original position */
  setCoords(0.0, 0.0);
  setDirection(90.0);
}

// --------------- Drawing methods ---------------
void Turtle::clear(){

}

void Turtle::penDown(){
  /* Lowers the pen-the turtle, after which
   * she leaves a trail when moving
   */
   setPen(true);
}

void Turtle::penUp(){
  /* Lifts the pen the turtle, after which
   * it ceases to leave a trail when moving
   */
   setPen(false);
}


void Turtle::drawLine(float x1, float y1){
  /* Draws the path of the turtle if the pen is omitted */
  sf::Vertex line[] =
  {
      sf::Vertex(sf::Vector2f(x, y)),
      sf::Vertex(sf::Vector2f(x1, y1))
  };
  window.draw(line, 2, sf::Lines);
}


void Turtle::setColor(int red, int green, int blue){
  /* Change the color of the turtle feather */
  if (red <= 255 && green <= 255 && blue <= 255) {

  }
}
// --------------- Interpret methods ---------------

void Turtle::interpret(string result, vector<char> constants){
    /* interpretation of the alphabet in a certain action turtles */
    for (unsigned int i = 0, size = result.size(); i < size ; ++i) {
      switch (result[i]) {
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
          if (find(constants.begin(), constants.end(), result[i]) == constants.end())
            move(step);
        break;
      }
    }

  }
