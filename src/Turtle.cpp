#include "Turtle.hpp"

// --------------- Getters and Setters ---------------

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

void Turtle::init(float _step, float _angle){
    step = _step;
    angle = _angle;
}

// --------------- Methods of movement ---------------

void Turtle::moveto(float x1, float y1){
  /* Move the turtle to a point with coordinates (x,y) */
  turtlePos.x = x1;
  turtlePos.y = y1;
}

void Turtle::move(float distance){
  /* Crawl distance steps forward */
  // calculate the new coordinates of the turtle
  turtlePos.x = turtlePos.x + distance *cos(getDirection() * M_PI / 180);
  turtlePos.y = turtlePos.y + distance *sin(getDirection() * M_PI / 180);
  //Append this position to the vertex vector
  if (getPen())
    vArray.append(sf::Vertex(turtlePos));
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
  save_stack.push(turtlePos.x);
  save_stack.push(turtlePos.y);
  save_stack.push(getDirection());
}

void Turtle::restore(){
  setDirection(save_stack.top());
  save_stack.pop();
  float ny = save_stack.top();
  save_stack.pop();
  float nx = save_stack.top();
  save_stack.pop();
  turtlePos.x = nx;
  turtlePos.y = ny;
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

void Turtle::interpret(sf::RenderWindow *disp, string result, vector<char> constants){
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
    disp->draw(vArray);
  }
