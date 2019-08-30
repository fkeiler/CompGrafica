#ifndef CUBE_HPP
#define CUBE_HPP

#include "Point.hpp"
#include "Ray.hpp"

class Cube
{
public:
  double A; // Tamanho da aresta
  Point C; // Centro da base do cone
  Cube(Point, double); //Construtor
  Point *Cube::colisionPoints(Ray); //Pontos de colisao 
}

#endif
