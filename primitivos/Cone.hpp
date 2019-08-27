#ifndef CONE_HPP
#define CONE_HPP

#include "Point.hpp"
#include "Vector.hpp"
#include "Ray.hpp"

class Cone
{
public:
  double H; // Altura do Cone
  double R; // Raio do Cone
  double cosTheta; // Theta é o ângulo que a geratriz forma com o eixo do cone
  Point C; // Centro da base do cone
  Point V; // Vertice do cone
  Vector n; // Vetor unitário que define a direção e sentido do raio
  // Construtores
  Cone(double, double, Point, Vector); // Prototipo do Construtor
  Point *colisionPoints(Ray); // Retorna os pontos de colisão do raio com o sólido
};

#endif
