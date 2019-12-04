//
// Created by daniel on 04/10/2019.
//

#ifndef TRABALHO_CYLINDER_HPP
#define TRABALHO_CYLINDER_HPP

#include "Plane.hpp"

class Cylinder
{
public:
    float height, radius; // Altura Cilindro e Raio Cilindro
    LinearAlgebra::Vector4Df baseCenter, unitaryDirection; // Centro base cilindro e Vetor unitário que define a direção do cilindro
    Plane basePlane, topPlane; // Parte de baixo do cilindro e "Tampa" do cilindro
    CG::Material material;
    int id;
    bool colision;

    // Construtor de cilindro comum
    Cylinder(float hi, float ri, LinearAlgebra::Vector4Df bi, LinearAlgebra::Vector4Df ui, CG::Material mi, int idi);

    std::vector<CG::Result> verifyCollision(LinearAlgebra::Vector4Df P0, LinearAlgebra::Vector4Df d);
    LinearAlgebra::Vector4Df normal(LinearAlgebra::Vector4Df Pint);
};


#endif //TRABALHO_CYLINDER_HPP
