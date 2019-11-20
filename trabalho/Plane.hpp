//
// Created by daniel on 04/10/2019.
//

#ifndef TRABALHO_PLANE_HPP
#define TRABALHO_PLANE_HPP

#include "CG.hpp"

class Plane
{
public:
    LinearAlgebra::Vector4Df point; // Ponto conhecido do plano
    LinearAlgebra::Vector4Df normal;  // Vetor unitário perpendicular ao plano
    CG::Material material;
    std::string label;
    bool colision;

    Plane(); // Construtor padrão
    Plane(LinearAlgebra::Vector4Df ip, LinearAlgebra::Vector4Df in, CG::Material im, std::string li); // Construtor
    std::vector<CG::Result> verifyColision(LinearAlgebra::Vector4Df P0, LinearAlgebra::Vector4Df d);
};


#endif //TRABALHO_PLANE_HPP
