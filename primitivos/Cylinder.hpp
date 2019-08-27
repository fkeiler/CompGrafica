#include "Point.hpp"
#include "Vector.hpp"
#ifndef CYLINDER_HPP
#define CYLINDER_HPP

class Cylinder
{
public:
  double H; // Altura do Cilindro
  double R; // Raio do Cilindro
  Point B; // Centro da base do Cilindro
  Vector u; // Vetor unitário que define a direção e sentido do raio
  // Construtores
  Cylinder(double, double, Point, Vector); // Prototipo do Construtor
};

#endif
