#include "Point.hpp"
#include <iostream>

using namespace std;

// Construtor padrão
Point::Point()
{
  x = 0;
  y = 0;
  z = 0;
}

// Construtor
Point::Point(double xi, double yi, double zi)
{
  x = xi;
  y = yi;
  z = zi;
}

// Sobrecarga de operadores
// Soma escalar
Point Point::operator+(Point v)
{
  double xn, yn, zn;

  xn = x + v.x;
  yn = y + v.y;
  zn = z + v.z;

  return Point(xn, yn, zn);
}
// Subtração escalar
Point Point::operator-(Point v)
{
  double xn, yn, zn;

  xn = x - v.x;
  yn = y - v.y;
  zn = z - v.z;

  return Point(xn, yn, zn);
}
// Multiplicação escalar
Point Point::operator*(Point v)
{
  double xn, yn, zn;

  xn = x * v.x;
  yn = y * v.y;
  zn = z * v.z;

  return Point(xn, yn, zn);
}
// Divisão escalar
Point Point::operator/(Point v)
{
  double xn, yn, zn;

  xn = x / v.x;
  yn = y / v.y;
  zn = z / v.z;

  return Point(xn, yn, zn);
}
// Output stream 
std::ostream& operator<<(std::ostream& out, const Point& p)
{
  out << "(" << p.x << ", ";
  out << p.y << ", ";
  out << p.z << ")";
  return out;
}
