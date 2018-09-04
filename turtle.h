class Turtle{
  public:
    Turtle();

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
    void setWidth(int);
    ~Turtle();

  private:
    float x = 0.0; // координата черепахи в оси x
    float y = 0.0; // координата черепахи в оси y
    double direction = 90.0;  // положение головы черепахи в пространстве( в градусах )
    bool pen = false; // опущенно ли перо черепахи или нет
};
