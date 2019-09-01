#include "Point.hpp"
#include "Vector.hpp"
#include "Ray.hpp"
#ifndef POLYGON_HPP
#define POLYGON_HPP

class Polygon
{
public:
    // Pontos do poligono
    Point p1;
    Point p2;
    Point p3;
    Polygon(Point, Point, Point); //Construtor
    double colisionPoints(Ray);  //Colisão
};

#endif