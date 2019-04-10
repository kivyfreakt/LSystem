#include "Turtle.cpp"

class LSystem{
  public:
    void addConstant(char);
    void build();
  private:
    Turtle turtle;
    vector <char> constants;
};
