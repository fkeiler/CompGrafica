//
// Created by abraao on 20/11/2019.
//

#ifndef TRABALHO_CONE_HPP
#define TRABALHO_CONE_HPP

#include "CG.hpp"
#include "Plane.hpp"

class Cone
{
public:
    float height, radius, cosTheta; // Altura do cone, Raio do Cone e Coseno do angulo que a geratriz forma com o eixo do cone
    LinearAlgebra::Vector4Df baseCenter, unitaryDirection, vertex; // Centro da base do cone, Vetor unitário que define a direção do cone, Vértice do cone
    Plane basePlane; //Base inferior do Cone
    CG::Material material;
    std::string label;
    bool colision;

    // Construtor de cone comum com material
    Cone(float hi, float ri, LinearAlgebra::Vector4Df bi, LinearAlgebra::Vector4Df ui, CG::Material mi, std::string li);

    std::vector<CG::Result> verifyColision(LinearAlgebra::Vector4Df P0, LinearAlgebra::Vector4Df d);
    LinearAlgebra::Vector4Df normal(LinearAlgebra::Vector4Df Pint);

};

#endif //TRABALHO_CONE_HPP
