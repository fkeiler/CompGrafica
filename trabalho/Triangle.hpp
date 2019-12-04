//
// Created by daniel on 03/12/2019.
//

#ifndef TRABALHO_TRIANGLE_HPP
#define TRABALHO_TRIANGLE_HPP

#include "CG.hpp"

class Triangle {
public:
    LinearAlgebra::Vector4Df p1, p2, p3; // Vertices do Triângulo
    std::vector<LinearAlgebra::Vector4Df> vertices;
    CG::Material material;
    int id;
    bool colision;

    Triangle(LinearAlgebra::Vector4Df p1i, LinearAlgebra::Vector4Df p2i, LinearAlgebra::Vector4Df p3i, CG::Material mi, int idi);
};


#endif //TRABALHO_TRIANGLE_HPP
