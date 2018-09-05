#include <fstream>
#include <cmath>
using namespace std;

ofstream psfile ("output.ps"); // открываем файл, в котором будет рисунок

#include "turtle.h"

Turtle::Turtle(){
  /* Конструктор */
  psfile << "1 setlinecap" << endl;
  psfile << "1 setlinejoin" << endl;
}

// --------------- Методы передвижения ---------------

void Turtle::moveto(float x1, float y1){
  /* Переместить черепаху в точку с координатами (x,y) */
  x = x1;
  y = y1;
}

void Turtle::move(float distance){
  /* Проползти на distance шагов вперед */
  // расчитываем новые координаты черепахи
  float x1 = x + distance * cos(direction * M_PI / 180);
  float y1 = y + distance * sin(direction * M_PI / 180);

  if (pen)
    drawLine(x1, y1);

  // устанавливаем новые координаты черепахи
  moveto(x1, y1);
}

void Turtle::turnRight(float angle){
  /* Поворот черепахи в правую сторону на угол angle */
    direction-=angle;
}

void Turtle::turnLeft(float angle){
  /* Поворот черепахи в левую сторону на угол angle */
    direction+=angle;
}

void Turtle::reset(){
  /* Возвращяет черепаху в исходное положение */
  x = 0.0;
  y = 0.0;
  direction = 90.0;
}

// --------------- Методы рисования ---------------

void Turtle::penDown(){
  /* Опускает перо у черепашки, после чего
   * она оставляет след при движении
   */
  pen = true;
}

void Turtle::penUp(){
  /* Поднимает перо у черепашки, после чего
   * она перестает оставлять след при движении
   */
  pen = false;
}

void Turtle::drawCircle(float rad){
  /*  Рисует круг радиуса rad с центром
   *  в месте, в котором стоит черепаха.
   */
  if (pen)
    psfile << "newpath " << x << " " << y << " " << rad << " 0 360 arc stroke" << endl;
}

void Turtle::drawCircle(float rad, float angle){
  /*  Рисует дугу радиуса rad с углом angle */
  if (pen){
    if (angle > 0 && angle <= 360)
      psfile << "newpath " << x << " " << y << " " << rad << " 0 " << angle << " arc stroke" << endl;
  }
}

void Turtle::drawCircle(float rad, float start, float end){
  /*  Рисует дугу радиуса rad от start до end */
  if (pen){
    if (start >= 0 && start < end && end >= 360)
      psfile << "newpath " << x << " " << y << " " << rad << " " << start << " " << end << " arc stroke" << endl;
  }
}

void Turtle::drawLine(float x1, float y1){
  /* Рисует путь черепахи, если перо опущенно */
  psfile << "newpath " << x << " " << y <<" moveto "<< x1 << " " << y1 <<" lineto stroke"<<endl;
}

void Turtle::setColor(double red, double green, double blue){
  /* Смена цвета пера черепахи  */
  if (red <= 1 && green <= 1 && blue <= 1){
    psfile << red << " " << green << " " << blue << " setrgbcolor"<< endl;
  }
}

void Turtle::setColor(int red, int green, int blue){
  /* Смена цвета пера черепахи */
  if (red <= 255 && green <= 255 && blue <= 255) {
    psfile << (float)red / 255 << " " << (float)green / 255 << " " << (float)blue / 255 << " setrgbcolor"<< endl;
  }
}

void Turtle::setWidth(int width){
  /* Изменяем ширину линии */
  psfile << width << " setlinewidth" << endl;
}

Turtle::~Turtle(){
  /* Деконструктор */
  psfile << "showpage" <<endl;
  psfile.close(); // закрываем файл
}
