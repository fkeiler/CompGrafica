//
// Created by daniel on 03/12/2019.
//

#ifndef TRABALHO_BOX_HPP
#define TRABALHO_BOX_HPP


#include "CG.hpp"

class Box {
    LinearAlgebra::Vector4Df min;
    LinearAlgebra::Vector4Df max;
    CG::Material material;
    int id;
    bool colision;

    Box(LinearAlgebra::Vector4Df _min,
            LinearAlgebra::Vector4Df _max,
            CG::Material mi,
            int li);

    std::vector<CG::Result> verifyCollision(LinearAlgebra::Vector4Df P0, LinearAlgebra::Vector4Df d);
    LinearAlgebra::Vector4Df normal(LinearAlgebra::Vector4Df Pint);
};


#endif //TRABALHO_BOX_HPP
