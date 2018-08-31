#include "turtle.h"

int main() {
  Turtle turtle;
  turtle.pen_down();
  turtle.color(0.19,0.85, 0.39);

  for (short int i = 0; i < 4; i++) {
    turtle.move(100);
    turtle.turn_right();
  }

  turtle.color(237, 71, 71);
  turtle.move_to(160,50);
  turtle.circle(50);

  return 0;
}
