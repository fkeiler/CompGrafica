#include "Vector.hpp"
#include <cmath>

// Construtor
Vector::Vector(double xi, double yi, double zi)
{
  x = xi; 
  y = yi; 
  z = zi;
}

// Construtor utilizando dois pontos
Vector::Vector(Point p1, Point p2)
{
  x = p2.x - p1.x;
  y = p2.y - p1.y;
  z = p2.z - p1.z;
}

// Método que retorna a norma do vetor
double Vector::norm()
{
  return sqrt(x*x + y*y + z*z);
}

// Sobrecarga dos operadores + - * / para operações com escalares
// Soma com escalar
Vector Vector::operator+(double a)
{
  double xn, yn, zn;

  xn = x + a;
  yn = y + a;
  zn = z + a;

  return Vector(xn, yn, zn);
}
// Soma com vetor
Vector Vector::operator+(Vector W)
{
  double xn, yn, zn;

  xn = x + W.x;
  yn = y + W.y;
  zn = z + W.z;

  return Vector(xn, yn, zn);
}
// Multiplicação por escalar
Vector Vector::operator*(double a){
  double xn, yn, zn;

  xn = x * a;
  yn = y * a;
  zn = z * a;

  return Vector(xn, yn, zn);
}
// Divisão por escalar
Vector Vector::operator/(double a){
  double xn, yn, zn;

  xn = x / a;
  yn = y / a;
  zn = z / a;

  return Vector(xn, yn, zn);
}
