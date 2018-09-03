#include <fstream>
#include <cmath>

using namespace std;

ofstream psfile ("output.ps"); // открываем файл, в котором будет рисунок

class Turtle {
  private:
    float x = 0; // координата черепахи в оси x
    float y = 0; // координата черепахи в оси y
    double direction = 90;  // положение головы черепахи в пространстве( в градусах )
    bool is_pen = false; // опущенно ли перо черепахи или нет
  public:

    Turtle(){
      /* Конструктор */
      psfile << "1 setlinecap" << endl;
      psfile << "1 setlinejoin" << endl;
    }

    // --------------- Методы передвижения ---------------

    void move(float distance){
      /* Проползти на distance шагов вперед */
      // расчитываем новые координаты черепахи
      float x1 = x + distance * cos(direction * M_PI / 180);
      float y1 = y + distance * sin(direction * M_PI / 180);

      if (is_pen)
        draw_line(x1, y1);

      // устанавливаем новые координаты черепахи
      x = x1;
      y = y1;
    }

    void move_to(float x1, float y1){
      /* Переместить черепаху в точку с координатами (x,y) */
      x = x1;
      y = y1;
    }

    void turn_right(float angle){
      /* Поворот черепахи в правую сторону на угол angle */
        direction-=angle;
    }

    void turn_left(float angle){
      /* Поворот черепахи в левую сторону на угол angle */
        direction+=angle;
    }

    void reset(){
      /* Возвращяет черепаху в исходное положение */
      x = 0;
      y = 0;
      direction = 90;
    }

    // --------------- Методы рисования ---------------

    void pen_down(){
      /* Опускает перо у черепашки, после чего
       * она оставляет след при движении
       */
      is_pen = true;
    }

    void pen_up(){
      /* Поднимает перо у черепашки, после чего
       * она перестает оставлять след при движении
       */
      is_pen = false;
    }

    void circle(float rad){
      /*  Рисует круг радиуса rad с центром
       *  в месте, в котором стоит черепаха.
       */
      if(is_pen)
        psfile << "newpath " << x << " " << y << " " << rad << " 0 360 arc stroke" << endl;
    }

    void circle(float rad, float angle){
      /*  Рисует дугу радиуса rad с углом angle */
      if(is_pen)
        psfile << "newpath " << x << " " << y << " " << rad << " 0 " << angle << " arc stroke" << endl;
    }

    void circle(float rad, float start, float end){
      /*  Рисует дугу радиуса rad от start до end */
      if(is_pen)
        psfile << "newpath " << x << " " << y << " " << rad << " " << start << " " << end << " arc stroke" << endl;
    }

    void draw_line(float x1, float y1){
      /* Рисует путь черепахи, если перо опущенно */
      psfile << "newpath " << x << " " << y <<" moveto "<< x1 << " " << y1 <<" lineto stroke"<<endl;
    }

    void color(double red, double green, double blue){
      /* Смена цвета пера черепахи  */
      psfile << red << " " << green << " " << blue << " setrgbcolor"<< endl;
    }

    void color(int red, int green, int blue){
      /* Смена цвета пера черепахи */
      psfile << (float)red/255 << " " << (float)green/255 << " " << (float)blue/255 << " setrgbcolor"<< endl;
    }

    // void width( int width ){
    //   /* Изменяем ширину линии */
    //   psfile << width << " setlinewidth" << endl;
    // }

    ~Turtle(){
      /* Деконструктор */
      psfile << "showpage" <<endl;
      psfile.close(); // закрываем файл
    }

};
