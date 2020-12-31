#include "Turtle.h"

Turtle::Turtle(){
  direction = degToRad(-90);
  vArray.setPrimitiveType(sf::Lines);
  vArray.resize(0);
  vArray.clear();
}
// --------------- Getters and Setters ---------------

bool Turtle::getPen() {
  return pen;
}

void Turtle::setPen(bool npen) {
  pen = npen;
}

void Turtle::init(float _step, float _angle){
    step = _step;
    angle = _angle;
}

// --------------- Methods of movement ---------------

void Turtle::moveto(float x1, float y1){
  /* Move the turtle to a point with coordinates (x,y) */
  x = x1;
  y = y1;
}

void Turtle::move(float distance){
  /* Crawl distance steps forward */
  // calculate the new coordinates of the turtle
  float dx = x + distance * cos(direction);
  float dy = y + distance * sin(direction);

  //Append this position to the vertex vector
  if (getPen()){
    sf::Vertex tmp_x, tmp_y;
    tmp_x.position = sf::Vector2f(x, y);
    tmp_y.position = sf::Vector2f(dx, dy);
    vArray.append(tmp_x);
    vArray.append(tmp_y);
  }

  x = dx;
  y = dy;
}

void Turtle::turnRight(float angle){
  /* Turn the turtle to the right side */
    direction -= degToRad(angle);
}

void Turtle::turnLeft(float angle){
  /* Turn the turtle to the left side */
    direction += degToRad(angle);
}

void Turtle::save(){
  save_stack.push(x);
  save_stack.push(y);
  save_stack.push(direction);
}

void Turtle::restore(){
  direction = save_stack.top();
  save_stack.pop();
  float ny = save_stack.top();
  save_stack.pop();
  float nx = save_stack.top();
  save_stack.pop();
  x = nx;
  y = ny;
}

float Turtle::degToRad(float deg){
	return deg*0.0174532925;
}

// --------------- Drawing methods ---------------

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

// --------------- Interpret methods ---------------

void Turtle::interpret(Filter* result, vector<char> constants){
    /* interpretation of the alphabet in a certain action turtles */
    char c;
    while ((c = result->getc()) != -1)
    {
        switch (c) {
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
                if (find(constants.begin(), constants.end(), c) == constants.end())
                    move(step);
            break;
        }
    }
}

void Turtle::draw(sf::RenderWindow *disp){
  disp->draw(vArray);
}
