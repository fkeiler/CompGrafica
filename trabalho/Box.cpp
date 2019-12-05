//
// Created by daniel on 03/12/2019.
//

#include "Box.hpp"

Box::Box(LinearAlgebra::Vector4Df _min, LinearAlgebra::Vector4Df _max, CG::Material mi, int li){
    min = _min;
    max = _max;
    material = mi;
    id = li;
    colision = true;
}

std::vector<CG::Result> Box::verifyCollision(LinearAlgebra::Vector4Df P0, LinearAlgebra::Vector4Df d){
    std::vector<CG::Result> retorno;

    float tmin = (min.x - P0.x) / d.x;
    float tmax = (max.x - P0.x) / d.x;

    if (tmin > tmax){
        float aux = tmin;
        tmin = tmax;
        tmax = aux;
    }

    float tymin = (min.y - P0.y) / d.y;
    float tymax = (max.y - P0.y) / d.y;

    if (tymin > tymax) {
        float aux = tymin;
        tymin = tymax;
        tymax = aux;
    }

    if ((tmin > tymax) || (tymin > tmax))
        return retorno;

    if (tymin > tmin)
        tmin = tymin;

    if (tymax < tmax)
        tmax = tymax;

    float tzmin = (min.z - P0.z) / d.z;
    float tzmax = (max.z - P0.z) / d.z;

    if (tzmin > tzmax) {
        float aux = tzmin;
        tzmin = tzmax;
        tzmax = aux;
    }

    if ((tmin > tzmax) || (tzmin > tmax))
        return retorno;

    if (tzmin > tmin)
        tmin = tzmin;

    if (tzmax < tmax)
        tmax = tzmax;

    LinearAlgebra::Vector4Df P = P0 + d*tmin;
    retorno.push_back(CG::Result{
        tmin,
        P,
        normal(P),
        material,
        id
    });
    P = P0 + d*tmax;
    retorno.push_back(CG::Result{
        tmin,
        P,
        normal(P),
        material,
        id
    });

    return retorno;
};

LinearAlgebra::Vector4Df Box::normal(LinearAlgebra::Vector4Df Pint){
    if(Pint.x == min.x){
        if(Pint.y == min.y){
            return {0, 0, 1, 1};
        }
        return {0, 1, 0, 1};
    }
    return {1, 0, 0, 1};
}