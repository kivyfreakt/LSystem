#include <iostream>
#include <cmath>

using namespace std;

class Turtle {
  private:
    float x = 0;
    float y = 0;
    int direction = 90;
    bool is_pen = false;
  public:
    void pen_down(){
      is_pen = true;
    }

    void pen_up(){
      is_pen = false;
    }

    void move(int distance){
      float x1 = x + distance*cos(direction*PI_M/180);
      float y1 = x + distance*sin(direction*PI_M/180);
    }

    void move_to(float x1, float y1){
      x = x1;
      y = y1;
    }

    void turn(int angle){
      if (direction > 0){
        direction-=angle;
      }else{
        direction=360-angle;
      }
    }

    void turn_right(){
      if (direction > 0){
        direction-=90;
      }else{
        direction=270;
      }
    }

    void turn_left(){
      if (direction < 360){
        direction+=90;
      }else{
        direction=90;
      }
    }
};
