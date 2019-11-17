//
// Created by daniel on 05/11/2019.
//

#include "Sphere.hpp"

Sphere::Sphere(LinearAlgebra::Vector4Df ci, float ri, CG::Material mi)
{
    center = ci;
    radius = ri;
    material = mi;
}

CG::Result Sphere::verifyColision(LinearAlgebra::Vector4Df P0, LinearAlgebra::Vector4Df d)
{
    float a, b, c, delta, t1, t2;
    CG::Result result;

    a = d.dot_product(d); // d.d
    b = 2*(P0 - center).dot_product(d); // 2*((P0-C).d)
    c = (P0 - center).dot_product(P0 - center) - (radius*radius); // ((P0-C).(P0-C) - R²)

    delta = b*b - 4*a*c;

    /*
     *  Calculando o valor de delta podemos chegar ao número inicial de colisões:
     *    Se delta < 0 não ocorre nenhuma colisão
     *    Se delta = 0 ocorre apenas uma colisão
     *    Se delta > 0 ocorrem duas colisões
     */

    if(delta < 0) {
        // Nenhuma Colisão
        result.colision = false; return result;
    } else if (delta == 0) {
        // Uma colisão
        result.colision = true;
        result.t = -b/(2*a);
        result.Pint = P0 + d*result.t;
        result.normal = normal(result.Pint);
        result.objectMaterial = material;
        result.label = "Sphere";

        return result;
    } else {
        // Duas colisões
        result.colision = true;

        if (a > 0) {
            result.t = (-b-sqrtf(delta))/(2*a);
        } else {
            result.t = (-b+sqrtf(delta))/(2*a);
        }

        result.Pint = P0 + d*result.t;
        result.normal = normal(result.Pint);
        result.objectMaterial = material;
        result.label = "Sphere";

        return result;
    }
}

LinearAlgebra::Vector4Df Sphere::normal(LinearAlgebra::Vector4Df pint)
{
    LinearAlgebra::Vector4Df R = pint - center;

    return R/(R.normalize());
}