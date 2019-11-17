//
// Created by daniel on 04/10/2019.
//

#include "Plane.hpp"

Plane::Plane()
{
}

Plane::Plane(LinearAlgebra::Vector4Df ip, LinearAlgebra::Vector4Df in, CG::Material im)
{
    point = ip;
    normal = in;
    material = im;
}

CG::Result Plane::intersection(LinearAlgebra::Vector4Df P0, LinearAlgebra::Vector4Df d)
{
    // Se d.n = 0 significa que o raio é paralelo ao plano
    if (d.dot_product(normal) == 0){
        CG::Result result;

        result.colision = false;

        return result;
    }
    else {
        CG::Result result;

        result.colision = true;
        result.t = ((point - P0).dot_product(normal))/(d.dot_product(normal));
        result.Pint = P0 + d*result.t;
        result.objectMaterial = material;
        result.label = "Plane";

        return result;
    }
}
