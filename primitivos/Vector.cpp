#include "Vector.hpp"
#include <cmath>

// Construtor Padrão
Vector::Vector()
{
  x = 1;
  y = 1;
  z = 1;
}

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
// Subtração com escalar
Vector Vector::operator-(double a)
{
  double xn, yn, zn;

  xn = x - a;
  yn = y - a;
  zn = z - a;

  return Vector(xn, yn, zn);
}
// Multiplicação com escalar
Vector Vector::operator*(double a)
{
  double xn, yn, zn;

  xn = x * a;
  yn = y * a;
  zn = z * a;

  return Vector(xn, yn, zn);
}
// Divisão com escalar
Vector Vector::operator/(double a)
{
  double xn, yn, zn;

  xn = x / a;
  yn = y / a;
  zn = z / a;

  return Vector(xn, yn, zn);
}

// Soma escalar com vetor
Vector Vector::operator+(Vector v)
{
  double xn, yn, zn;

  xn = x + v.x;
  yn = y + v.y;
  zn = z + v.z;

  return Vector(xn, yn, zn);
}
// Subtração escalar com vetor
Vector Vector::operator-(Vector v)
{
  double xn, yn, zn;

  xn = x - v.x;
  yn = y - v.y;
  zn = z - v.z;

  return Vector(xn, yn, zn);
}
// Multiplicação escalar com vetor
Vector Vector::operator*(Vector v)
{
  double xn, yn, zn;

  xn = x * v.x;
  yn = y * v.y;
  zn = z * v.z;

  return Vector(xn, yn, zn);
}
// Divisão escalar com vetor
Vector Vector::operator/(Vector v)
{
  double xn, yn, zn;

  xn = x / v.x;
  yn = y / v.y;
  zn = z / v.z;

  return Vector(xn, yn, zn);
}

// Métodos
// Método que retorna a norma do vetor
double Vector::norm()
{
  return sqrt(x*x + y*y + z*z);
}

// Método que retorna o vetor normalizado
Vector Vector::normalize()
{
  // Calcula valor da norma
  double norm = sqrt(x*x + y*y + z*z);
  double xn = x/norm;
  double yn = y/norm;
  double zn = z/norm;
  Vector n(xn, yn, zn);
  
  return n;
}

double Vector::dotProduct(Vector w)
{
  return x*w.x + y*w.y + z*w.z;
}
Vector Vector::crossProduct(Vector w)
{
  return Vector((y*w.z - z*w.y), (z*w.x - x*w.z), (x*w.y - y*w.x));
}