//
// Created by daniel on 03/12/2019.
//

#include "Triangle.hpp"

Triangle::Triangle(LinearAlgebra::Vector4Df p1i, LinearAlgebra::Vector4Df p2i, LinearAlgebra::Vector4Df p3i, CG::Material mi, int idi)
{
    p1 = p1i;
    p2 = p2i;
    p3 = p3i;
    vertices.push_back(p1);
    vertices.push_back(p2);
    vertices.push_back(p3);
    material = mi;
    id = idi;
}

std::vector<CG::Result> Triangle::verifyCollision(LinearAlgebra::Vector4Df P0, LinearAlgebra::Vector4Df d)
{
    std::vector<CG::Result> resultado;

    LinearAlgebra::Vector4Df v1 = p2 - p1;
    LinearAlgebra::Vector4Df v2 = p3 - p1;
    LinearAlgebra::Vector4Df normal = v1.cross_product(v2);
    if(d.dot_product(normal) == 0){
        return resultado;
    };
    float tint = (p1 - P0).dot_product(normal) / d.dot_product(normal);
    LinearAlgebra::Vector4Df Pint = P0 + LinearAlgebra::Vector4Df({d.x*tint, d.y*tint, d.z*tint, 1});
    if((p2 - p1).cross_product((Pint - p1)).dot_product(normal) < 0) return resultado;
    if((p3 - p2).cross_product((Pint - p2)).dot_product(normal) < 0) return resultado;
    if((p1 - p3).cross_product((Pint - p3)).dot_product(normal) < 0) return resultado;
    resultado.push_back(CG::Result{
        tint,
        P0 + d*tint,
        normal,
        material,
        id
    });
    return resultado;
}

LinearAlgebra::Vector4Df Triangle::normal(LinearAlgebra::Vector4Df Pint)
{
    LinearAlgebra::Vector4Df N = (p2 - p1).cross_product(p3 - p1);
    return N.normalize();
}