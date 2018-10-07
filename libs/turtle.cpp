#include <fstream>
#include <cmath>
using namespace std;

ofstream temp_file ("tmp.ps"); // temporary file to save the image

#include "turtle.h"

Turtle::Turtle(){
  /* Class Constructor */
  temp_file << "/seg { 4 2 roll newpath moveto lineto stroke } def" << endl;
  temp_file << "1 setlinecap" << endl;
  temp_file << "1 setlinejoin" << endl;
}

// --------------- Getters and Setters ---------------
float Turtle::getCoord(short coord) {
  if (coord == 0)
    return x;
  else
    return y;
}

void Turtle::setCoords(float nx, float ny) {
  x = nx;
  y = ny;
}

float Turtle::getDirection() {
  return direction;
}

void Turtle::setDirection(float ndirection) {
  direction = ndirection;
}

int Turtle::getWidth() {
  return width;
}

void Turtle::setWidth(int wd){
  width = wd;
  temp_file << wd << " setlinewidth" << endl;
}

bool Turtle::getPen() {
  return pen;
}

void Turtle::setPen(bool npen) {
  pen = npen;
}

// --------------- Methods of movement ---------------

void Turtle::moveto(float x1, float y1){
  /* Move the turtle to a point with coordinates (x,y) */
  setCoords(x1,y1);
}

void Turtle::move(float distance){
  /* Crawl distance steps forward */
  // calculate the new coordinates of the turtle
  float x1 = getCoord(0) + distance * cos(getDirection() * M_PI / 180);
  float y1 = getCoord(1) + distance * sin(getDirection() * M_PI / 180);

  setPictureSize();

  if (getPen())
    drawLine(x1, y1);

  // set the new coordinates of the turtle
  setCoords(x1, y1);
  setPictureSize();
}

void Turtle::turnRight(float angle){
  /* Turn the turtle to the right side */
    setDirection(getDirection()-angle);
}

void Turtle::turnLeft(float angle){
  /* Turn the turtle to the left side */
    setDirection(getDirection()+angle);
}

void Turtle::save(){
  save_stack.push(getCoord(0));
  save_stack.push(getCoord(1));
  save_stack.push(getDirection());
}

void Turtle::restore(){
  setDirection(save_stack.top());
  save_stack.pop();
  float ny = save_stack.top();
  save_stack.pop();
  float nx = save_stack.top();
  save_stack.pop();
  setCoords(nx, ny);
}

void Turtle::reset(){
  /* Returns the turtle to its original position */
  setCoords(0.0, 0.0);
  setDirection(90.0);
}

// --------------- Drawing methods ---------------

void Turtle::penDown(){
  /* Lowers the pen-the turtle, after which
   * she leaves a trail when moving
   */
   setPen(true);
}

void Turtle::penUp(){
  /* Lifts the pen the turtle, after which
   * it ceases to leave a trail when moving
   */
   setPen(false);
}

void Turtle::drawCircle(float rad){
  /*  Draw round with some radius */
  if (getPen())
    temp_file << "newpath " << getCoord(0) << " " << getCoord(1) << " " << rad << " 0 360 arc stroke" << endl;
}

void Turtle::drawCircle(float rad, float angle){
  /*  Draw an arc*/
  if (getPen()){
    if (angle > 0 && angle <= 360)
      temp_file << "newpath " << getCoord(0) << " " << getCoord(1) << " " << rad << " 0 " << angle << " arc stroke" << endl;
  }
}

void Turtle::drawCircle(float rad, float start, float end){
  /*  Draw an arc from start point to end */
  if (getPen()){
    if (start >= 0 && start < end && end >= 360)
      temp_file << "newpath " << getCoord(0) << " " << getCoord(1) << " " << rad << " " << start << " " << end << " arc stroke" << endl;
  }
}

void Turtle::drawLine(float x1, float y1){
  /* Draws the path of the turtle if the pen is omitted */
  temp_file << getCoord(0) << " " << getCoord(1) << " " << x1 << " " << y1 <<" seg"<<endl;
}

void Turtle::setColor(double red, double green, double blue){
  /* Change the color of the turtle feather  */
  if (red <= 1 && green <= 1 && blue <= 1){
    temp_file << red << " " << green << " " << blue << " setrgbcolor"<< endl;
  }
}

void Turtle::setColor(int red, int green, int blue){
  /* Change the color of the turtle feather */
  if (red <= 255 && green <= 255 && blue <= 255) {
    temp_file << (float)red / 255 << " " << (float)green / 255 << " " << (float)blue / 255 << " setrgbcolor"<< endl;
  }
}


void Turtle::setPictureSize(){
  /* Changing the size of the final image */
  picture_size[0][0] = min(picture_size[0][0], getCoord(0)-getWidth()/2);
  picture_size[0][1] = min(picture_size[0][1], getCoord(1)-getWidth()/2);
  picture_size[1][0] = max(picture_size[1][0], getCoord(0)+getWidth()/2);
  picture_size[1][1] = max(picture_size[1][1], getCoord(1)+getWidth()/2);
}

Turtle::~Turtle(){
  /* Class Deconstructor */
  temp_file << "showpage" <<endl;
  temp_file.close();
  ifstream temp_file ("tmp.ps");
  ofstream output_file ("output.ps");
  output_file << "%!PS-Adobe-3.0 EPSF-3.0\n";
  // set picture size
  output_file << "%%BoundingBox: "<< round(picture_size[0][0]) << " " << round(picture_size[0][1]) << " " << round(picture_size[1][0]) << " " << round(picture_size[1][1]) << "\n";
  output_file << "%%HiResBoundingBox: "<< picture_size[0][0] << " " << picture_size[0][1] << " " << picture_size[1][0] << " " << picture_size[1][1] << "\n";
  output_file << "%%EndComments" <<endl;
  output_file << temp_file.rdbuf();
  // close files
  temp_file.close();
  output_file.close();
  remove("tmp.ps"); // delete the temporary file
}
