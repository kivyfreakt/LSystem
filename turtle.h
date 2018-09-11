class Turtle{
  public:
    Turtle();
    // --------------- Геттеры и сеттеры ---------------
    float getCoord(short);
    void setCoords(float, float);
    float getDirection();
    void setDirection(float);
    int getWidth();
    void setWidth(int);
    bool getPen();
    void setPen(bool);
    // --------------- Методы передвижения ---------------

    void moveto(float, float);
    void move(float);
    void turnRight(float);
    void turnLeft(float);
    void reset();

    // --------------- Методы рисования ---------------

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
    float x = 0.0; // координата черепахи в оси x
    float y = 0.0; // координата черепахи в оси y
    double direction = 90.0;  // положение головы черепахи в пространстве( в градусах )
    bool pen = false; // опущенно ли перо черепахи или нет
    unsigned short int width = 1; // толщина линии
    float picture_size[2][2] = {{1000, 1000}, {0,0}}; // размеры изображения
};
