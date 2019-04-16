/*
* A class of turtle that can move in the coordinate
* system thanks to special commands that the user sets
* The class is used to interpret the lsystem alphabet
* into turtle drawing commands
*/
#pragma once

#include <stack>
#include <vector>
#include <string>
#include <algorithm>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

using namespace std;

class Turtle{
  public:
    // --------------- Methods of movement ---------------

    void moveto(float, float);
    void move(float);
    void turnRight(float);
    void turnLeft(float);
    void save();
    void restore();

    // --------------- Drawing methods ---------------

    void penDown();
    void penUp();

  // --------------- Interpret methods ---------------

    void interpret(sf::RenderWindow* ,string, vector<char>);
    void init(float, float);

  private:
    // --------------- Getters and Setters ---------------
    float getDirection();
    void setDirection(float);
    bool getPen();
    void setPen(bool);

    float step;
    float angle;

    sf::VertexArray vArray; //Representation of the script iteration as a set of vertexes
    sf::Vector2f turtlePos = sf::Vector2f(0.f, 0.f); //Current position of the turtle
    float direction = 0.0;  // he position of the turtle's head in space( in degrees )
    bool pen = false;
    stack <float> save_stack; // stack to store coordinates
    sf::RenderWindow window;
};
