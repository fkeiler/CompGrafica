#include "Ray.hpp"
#include <cmath>

// Constructor
Ray::Ray(Point p0i, Vector di)
{
  p0 = p0i;
  d = di;
}
