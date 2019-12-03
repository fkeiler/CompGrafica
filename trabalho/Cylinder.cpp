//
// Created by daniel on 04/10/2019.
//

#include "Cylinder.hpp"

Cylinder::Cylinder(float hi, float ri, LinearAlgebra::Vector4Df bi, LinearAlgebra::Vector4Df ui, std::string li)
{
    height = hi;
    radius = ri;
    baseCenter = bi;
    unitaryDirection = ui;
    label = li;

    basePlane.point = bi;
    basePlane.normal = ui*-1;
    basePlane.label = li;

    topPlane.point = bi+ui*hi;
    topPlane.normal = ui;
    topPlane.label = li;

    colision = true;
}

Cylinder::Cylinder(float hi, float ri, LinearAlgebra::Vector4Df bi, LinearAlgebra::Vector4Df ui, CG::Material mi,
                   std::string li)
{
    height = hi;
    radius = ri;
    baseCenter = bi;
    unitaryDirection = ui;
    material = mi;
    label = li;

    basePlane.point = bi;
    basePlane.normal = ui*-1;
    basePlane.material = mi;
    basePlane.label = li;

    topPlane.point = bi+ui*hi;
    topPlane.normal = ui;
    topPlane.material = mi;
    topPlane.label = li;

    colision = true;
}

std::vector<CG::Result> Cylinder::verifyCollision(LinearAlgebra::Vector4Df P0, LinearAlgebra::Vector4Df d)
{
    std::vector<CG::Result> results, planeResult;

    // Caso a colisão do objeto esteja desligada retornamos uma lista de colisões vazia
    if (!colision) {
        return results;
    }

    // Verificando colisões com a base do cilindro
    planeResult = basePlane.verifyCollision(P0, d);
    if(!planeResult.empty()){
        if((planeResult[0].Pint - basePlane.point).norm() <= radius){
            results.push_back(planeResult[0]);
        }
    }

    // Verificando colisões com o topo do cilindro
    planeResult = topPlane.verifyCollision(P0, d);
    if(!planeResult.empty()){
        if((planeResult[0].Pint - topPlane.point).norm() <= radius){
            results.push_back(planeResult[0]);
        }
    }

    LinearAlgebra::Vector4Df w = d - unitaryDirection*(d.dot_product(unitaryDirection));;
    if(w.norm() == 0)
    {
        return results;
    }

    LinearAlgebra::Vector4Df v = (P0 - baseCenter) - unitaryDirection*((P0 - baseCenter).dot_product(unitaryDirection));
    float a, b, c, delta;

    a = w.dot_product(w);
    b = 2*(v.dot_product(w));
    c = v.dot_product(v) - powf(radius,2);

    delta = powf(b,2) - 4*a*c;

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

LinearAlgebra::Vector4Df Cylinder::normal(LinearAlgebra::Vector4Df Pint)
{
    LinearAlgebra::Vector4Df Pintl = baseCenter + unitaryDirection*((Pint - baseCenter).dot_product(unitaryDirection));

    return (Pint-Pintl)/radius;
}