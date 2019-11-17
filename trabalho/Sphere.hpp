//
// Created by daniel on 05/11/2019.
//

#ifndef TRABALHO_SPHERE_HPP
#define TRABALHO_SPHERE_HPP

#include "CG.hpp"

class Sphere {
public:
    LinearAlgebra::Vector4Df center;
    float radius;
    CG::Material material;

    Sphere(LinearAlgebra::Vector4Df ci, float ri, CG::Material mi);

    CG::Result verifyColision(LinearAlgebra::Vector4Df P0, LinearAlgebra::Vector4Df d);
    LinearAlgebra::Vector4Df normal(LinearAlgebra::Vector4Df Pint);
};


#endif //TRABALHO_SPHERE_HPP
