#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

ofstream psfile ("output.ps");

class Turtle {
  private:
    float x = 0;
    float y = 0;
    unsigned int direction = 90;
    bool is_pen = false;
  public:
    Turtle(){
      psfile << "1 setlinewidth" << endl;
      psfile << "1 setlinecap" << endl;
      psfile << "1 setlinejoin" << endl;
      psfile << "0 0 0 setrgbcolor"<< endl;
    }

    void move(float distance){
      float x1 = x + distance * cos(direction * M_PI / 180);
      float y1 = y + distance * sin(direction * M_PI / 180);

      if (is_pen)
        draw_line(x, y, x1, y1);

      x = x1;
      y = y1;
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

    void pen_down(){
      is_pen = true;
    }

    void pen_up(){
      is_pen = false;
    }

    void draw_line(float x, float y, float x1, float y1){
      psfile << "newpath " << x << " " << y <<" moveto "<< x1 << " " << y1 <<" lineto stroke"<<endl;
    }

    ~Turtle(){
      psfile << "showpage" <<endl;
      psfile.close();
    }

};
