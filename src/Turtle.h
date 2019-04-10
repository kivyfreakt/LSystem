/*
* A class of turtle that can move in the coordinate
* system thanks to special commands that the user sets
* The class is used to interpret the lsystem alphabet
* into turtle drawing commands
*/

#include <stack>
#include <SDL2/SDL.h>
#include <iostream>
#include <cmath>

class Turtle{
  public:
    Turtle();
    // --------------- Getters and Setters ---------------
    float getCoord(short);
    void setCoords(float, float);
    float getDirection();
    void setDirection(float);
    bool getPen();
    void setPen(bool);

    // --------------- Methods of movement ---------------

    void moveto(float, float);
    void move(float);
    void turnRight(float);
    void turnLeft(float);
    void save();
    void restore();
    void reset();

    // --------------- Drawing methods ---------------

    void clear();
    void penDown();
    void penUp();
    void drawLine(float, float);
    void setColor(int, int, int);

  private:
    float x = 0.0; // coordinate of the turtle to the x-axis
    float y = 0.0; // coordinate of the turtle to the y-axis
    float direction = 90.0;  // he position of the turtle's head in space( in degrees )
    bool pen = false;
    stack <float> save_stack; // stack to store coordinates
    SDL_Renderer *turtleRenderer;
};
