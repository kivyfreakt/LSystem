#include "turtle.h"

int main() {
  Turtle turtle;
  turtle.pen_down();
  turtle.move(100);
  turtle.turn_right();
  turtle.color(0.19,0.85, 0.39);
  turtle.move(100);
  turtle.turn_right();
  turtle.color(237, 71, 71);
  turtle.move(100);
  turtle.turn_right();
  turtle.move(100);
  return 0;
}
