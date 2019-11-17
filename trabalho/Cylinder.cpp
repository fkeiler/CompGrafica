//
// Created by daniel on 04/10/2019.
//

#include "Cylinder.hpp"

Cylinder::Cylinder(double h, double r, Coordinate bi, Coordinate ui)
{
    height = h;
    radius = r;
    baseCenter = bi;
    unitaryDirection = ui;

    // Planos da base e do topo do cilindro
    basePlane.point = baseCenter;
    basePlane.normal = unitaryDirection;
    topPlane.point = baseCenter + unitaryDirection*height;
    topPlane.normal = unitaryDirection;
}

double* Cylinder::verifyColision(Ray ray)
{
    // Variaveis criadas para simplificar os calculos
    Coordinate v = (ray.P0-baseCenter)-unitaryDirection*(ray.P0-baseCenter).dot(unitaryDirection);
    Coordinate w = ray.d-unitaryDirection*ray.d.dot(unitaryDirection);

    // Valores de a,b e c calculados
    double a = w.dot(w);
    double b = 2*v.dot(w);
    double c = v.dot(v) - pow(radius, 2);

    // Caso a seja igual a zero, significa que d é paralelo a u, então a colisão vai ser com o topo ou base do cilindro
    // O que fazer?

    double delta = pow(b,2) - 4*a*c;


}