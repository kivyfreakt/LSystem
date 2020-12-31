/*
* A class of turtle that can move in the coordinate
* system thanks to special commands that the user sets
* The class is used to interpret the lsystem alphabet
* into turtle drawing commands
*/
#ifndef TURTLE_H
#define TURTLE_H

#include <stack>
#include <vector>
#include <string>
#include <algorithm>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

#include "Filter.h"

using namespace std;

class Turtle{
  public:
    // --------------- Methods of movement ---------------
    Turtle();
    void moveto(float, float);
    void move(float);
    void turnRight(float);
    void turnLeft(float);
    void save();
    void restore();
    float degToRad(float);

    // --------------- Drawing methods ---------------

    void penDown();
    void penUp();

  // --------------- Interpret methods ---------------

    void interpret(Filter*, vector<char>);
    void init(float, float);
    void draw(sf::RenderWindow *);

  private:
    // --------------- Getters and Setters ---------------
    bool getPen();
    void setPen(bool);

    float step;
    float angle;

    sf::VertexArray vArray; //Representation of the script iteration as a set of vertexes
    float x = 0.f; //Current position of the turtle
    float y = 0.f; //Current position of the turtle
    float direction = 0.f;  // he position of the turtle's head in space( in degrees )
    bool pen = true;
    stack <float> save_stack; // stack to store coordinates
};

#endif
