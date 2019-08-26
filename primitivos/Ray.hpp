#include "Point.hpp"
#include "Vector.hpp"
#ifndef RAY_HPP
#define RAY_HPP

class Ray
{
public:
  Point p0; // Ponto de partida do raio
  Vector d; // Vetor de direção e sentido do raio
  // Construtores
  Ray(Point, Vector); // Prototipo do Construtor
};

#endif
