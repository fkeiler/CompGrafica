//
// Created by daniel on 03/12/2019.
//

#include "Triangle.hpp"

Triangle::Triangle(LinearAlgebra::Vector4Df p1i, LinearAlgebra::Vector4Df p2i, LinearAlgebra::Vector4Df p3i, CG::Material mi, int idi)
{
    p1 = p1i;
    p2 = p2i;
    p3 = p3i;
    material = mi;
    id = idi;
}

std::vector<CG::Result> Triangle::verifyCollision(LinearAlgebra::Vector4Df P0, LinearAlgebra::Vector4Df d)
{

}

LinearAlgebra::Vector4Df Triangle::normal(LinearAlgebra::Vector4Df Pint)
{
    LinearAlgebra::Vector4Df N = (p2 - p1).cross_product(p3 - p1);
    LinearAlgebra::Vector4Df n = N/N.normalize();
}