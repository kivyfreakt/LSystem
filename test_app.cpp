#include "turtle.h"

Turtle turtle;

void draw_koch(int a, int n){
  if(n == 0){
    turtle.move(a);
    return;
  }
  draw_koch(a/3,n-1);
  turtle.turn_left(60);
  draw_koch(a/3,n-1);
  turtle.turn_right(120);
  draw_koch(a/3,n-1);
  turtle.turn_left(60);
  draw_koch(a/3,n-1);
}

int main() {
  turtle.pen_down();
  turtle.color(0.19,0.85, 0.39);
  turtle.move_to(250,250);

  turtle.turn_right(30);
  for (int i = 0; i < 3; i++) {
    draw_koch(200, 3);
    turtle.turn_right(120);
  }

  return 0;
}
