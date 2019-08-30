#include "Cube.hpp"
#include <cmath>

Cube::Cube(double Ai, Point Ci){
  A = Ai;
  C = Ci;
}
Point *Cube::colisionPoints(Ray R){
  Point inf = Point(C.x - A/2, C.y, C.z - A/2);
  Point sup = Point(C.x + A/2, C.y + A, C.z + A/2);
  tmin = min(inf.x - R.p0.x, inf.y - R.p0.y, inf.z - R.p0.z);
  tmax = min(sup.x - R.p0.x, sup.y - R.p0.y, inf.z - R.p0.z);
  
}
