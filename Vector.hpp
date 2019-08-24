#include "Point.hpp"
#ifndef VECTOR_HPP
#define VECTOR_HPP

class Vector
{
public:
  double x, y, z;
  Vector(double, double, double); // Prototipo do Construtor
  Vector(Point, Point); // Prototipo do Construtor
  double norm(); // Norma do vetor
  // Sobrecarga de operadores
  Vector operator+(double); // Soma som escalar
  Vector operator-(double); // Subtração som escalar
  Vector operator*(double); // Multiplicação som escalar
  Vector operator/(double); // Divisão som escalar
  Vector operator+(Vector);
};

#endif
