//
// Created by daniel on 04/10/2019.
//

#ifndef TRABALHO_CYLINDER_HPP
#define TRABALHO_CYLINDER_HPP

#include "Plane.hpp"

class Cylinder
{
public:
    double height; // Altura Cilindro
    double radius; // Raio Cilindro
    Coordinate baseCenter; // Centro base cilindro
    Coordinate unitaryDirection; // Vetor unitário que define a direção do cilindro

    Plane basePlane; // Parte de baixo do cilindro
    Plane topPlane; // "Tampa" do cilindro

    Cylinder(double, double, Coordinate, Coordinate); // Construtor
    double *verifyColision(Ray ray);
};


#endif //TRABALHO_CYLINDER_HPP
