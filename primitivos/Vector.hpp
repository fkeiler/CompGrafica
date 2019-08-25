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
  Vector normalize(); // Vetor normalizado
  // Sobrecarga de operadores
  Vector operator+(double); // Soma com escalar
  Vector operator-(double); // Subtração com escalar
  Vector operator*(double); // Multiplicação com escalar
  Vector operator/(double); // Divisão com escalar
  Vector operator+(Vector); // Soma escalar com vetor
  Vector operator-(Vector); // Subtração escalar com vetor
  Vector operator*(Vector); // Multiplicação escalar com vetor
  Vector operator/(Vector); // Divisão escalar com vetor
};

#endif
