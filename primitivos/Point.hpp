#ifndef POINT_HPP
#define POINT_HPP

class Point
{
public:
  double x, y, z;
  // Construtores
  Point(); // Prototipo de Construtor Padrão
  Point(double, double, double); //Prototipo do Construtor
  // Sobrecarga de operadores
  Point operator+(Point); // Soma escalar com point
  Point operator-(Point); // Subtração escalar com point
  Point operator*(Point); // Multiplicação escalar com point
  Point operator/(Point); // Divisão escalar com point
};

#endif
