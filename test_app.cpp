#include "turtle.h"

Turtle turtle;

void koch(int a, int n){
  if(n == 0){
    turtle.move(a);
    return;
  }
  koch(a/3,n-1);
  turtle.turn_left(60);
  koch(a/3,n-1);
  turtle.turn_right(120);
  koch(a/3,n-1);
  turtle.turn_left(60);
  koch(a/3,n-1);
}

int main() {
  turtle.pen_down();
  turtle.color(0.19,0.85, 0.39);
  turtle.move_to(150,150);

  koch(100, 2);
  turtle.turn_right(120);
  koch(100, 2);
  turtle.turn_right(120);
  koch(100, 2);

  return 0;
}
