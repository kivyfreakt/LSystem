/*
* A class of turtle that can move in the coordinate
* system thanks to special commands that the user sets
* The class is used to interpret the lsystem alphabet
* into turtle drawing commands
*/

#include <stack>

class Turtle{
  public:
    Turtle();
    // --------------- Getters and Setters ---------------
    float getCoord(short);
    void setCoords(float, float);
    float getDirection();
    void setDirection(float);
    int getWidth();
    void setWidth(int);
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

    void penDown();
    void penUp();
    void drawCircle(float);
    void drawCircle(float, float);
    void drawCircle(float, float, float);
    void drawLine(float, float);
    void setColor(double, double, double);
    void setColor(int, int, int);
    void setPictureSize();
    ~Turtle();

  private:
    float x = 0.0; // coordinate of the turtle to the x-axis
    float y = 0.0; // coordinate of the turtle to the y-axis
    float direction = 90.0;  // he position of the turtle's head in space( in degrees )
    bool pen = false;
    unsigned short int width = 1;
    stack <float> save_stack; // stack to store coordinates
    float picture_size[2][2] = {{1000, 1000}, {0,0}}; // image size
};
