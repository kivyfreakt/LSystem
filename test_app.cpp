#include "turtle.cpp"

Turtle turtle;

void draw_koch(int a, int n);

int main() {
  turtle.penDown();
  turtle.setColor(0.19,0.85, 0.39);
  turtle.moveto(250,250);

  turtle.turnRight(30);
  for (int i = 0; i < 3; i++) {
    draw_koch(500, 3);
    turtle.turnRight(120);
  }
  return 0;
}

void draw_koch(int a, int n){
  if(n == 0){
    turtle.move(a);
    return;
  }
  draw_koch(a/3,n-1);
  turtle.turnLeft(60);
  draw_koch(a/3,n-1);
  turtle.turnRight(120);
  draw_koch(a/3,n-1);
  turtle.turnLeft(60);
  draw_koch(a/3,n-1);
}
