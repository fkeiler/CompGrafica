//
// Created by daniel on 04/10/2019.
//

#include "Plane.hpp"

Plane::Plane()
{
    colision = true;
}

Plane::Plane(LinearAlgebra::Vector4Df ip, LinearAlgebra::Vector4Df in, CG::Material im, std::string li)
{
    point = ip;
    normal = in;
    material = im;
    colision = true;
    label = li;
}

std::vector<CG::Result> Plane::verifyColision(LinearAlgebra::Vector4Df P0, LinearAlgebra::Vector4Df d)
{
    std::vector<CG::Result> results;

    // Se d.n = 0 significa que o raio é paralelo ao plano
    if (d.dot_product(normal) == 0 || !colision){
        return results;
    }
    else {
        float tint = ((point - P0).dot_product(normal))/(d.dot_product(normal));
        LinearAlgebra::Vector4Df Pint = P0 + d*tint;

        results.push_back(CG::Result{
                tint,
                Pint,
                normal,
                material,
                label
        });

        return results;
    }
}