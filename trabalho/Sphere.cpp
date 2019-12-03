//
// Created by daniel on 05/11/2019.
//

#include "Sphere.hpp"

// Esfera de colisão
Sphere::Sphere(LinearAlgebra::Vector4Df ci, float ri, std::string li)
{
    center = ci;
    radius = ri;
    label = li;
    colision = true;
}

// Esfera comum
Sphere::Sphere(LinearAlgebra::Vector4Df ci, float ri, CG::Material mi, std::string li)
{
    center = ci;
    radius = ri;
    material = mi;
    label = li;
    colision = true;
}

std::vector<CG::Result> Sphere::verifyColision(LinearAlgebra::Vector4Df P0, LinearAlgebra::Vector4Df d)
{
    std::vector<CG::Result> results;

    // Caso a colisão do objeto esteja desligada retornamos uma lista de colisões vazia
    if (!colision) {
        return results;
    }

    float a, b, c, delta;

    a = d.dot_product(d); // d.d
    b = 2*(P0 - center).dot_product(d); // 2*((P0-C).d)
    c = (P0 - center).dot_product(P0 - center) - (radius*radius); // ((P0-C).(P0-C) - R²)

    delta = b*b - 4*a*c;

    /*
     *  Calculando o valor de delta podemos chegar ao número inicial de colisões:
     *    -Se delta < 0 não ocorre nenhuma colisão
     *    -Se delta = 0 ocorre apenas uma colisão
     *    -Se delta > 0 ocorrem duas colisões
     */

    if(delta < 0) {
        // Nenhuma Colisão
        return results;
    } else if (delta == 0) {
        // Uma colisão
        float tint = -b/(2*a);
        LinearAlgebra::Vector4Df Pint =  P0 + d*tint;

        results.push_back(CG::Result{
                tint,
                Pint,
                normal(Pint),
                material,
                label
        });

        return results;
    } else {
        // Duas colisões
        float tint = (-b-sqrtf(delta))/(2*a);
        LinearAlgebra::Vector4Df Pint =  P0 + d*tint;

        // Colisão 1
        results.push_back(CG::Result{
                tint,
                Pint,
                normal(Pint),
                material,
                label
        });

        tint = (-b+sqrtf(delta))/(2*a);
        Pint =  P0 + d*tint;

        // Colisão 2
        results.push_back(CG::Result{
                tint,
                Pint,
                normal(Pint),
                material,
                label
        });

        return results;
    }
}

LinearAlgebra::Vector4Df Sphere::normal(LinearAlgebra::Vector4Df pint)
{
    LinearAlgebra::Vector4Df R = pint - center;

    return R.normalize();
}