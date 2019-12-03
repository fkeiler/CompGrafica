//
// Created by abraao on 20/11/2019.
//

#include "Cone.hpp"

Cone::Cone(float hi, float ri, LinearAlgebra::Vector4Df bi, LinearAlgebra::Vector4Df ui, CG::Material mi, std::string li)
{
    height = hi;
    radius = ri;
    baseCenter = bi;
    unitaryDirection = ui;
    material = mi;
    label = li;

    vertex = bi + ui*hi;
    cosTheta = hi/(sqrt(powf(hi, 2) + powf(ri, 2) ));

    basePlane.point = bi;
    basePlane.normal = ui*-1;
    basePlane.material = mi;
    basePlane.label = li;

    colision = true;
}

std::vector<CG::Result> Cone::verifyCollision(LinearAlgebra::Vector4Df P0, LinearAlgebra::Vector4Df d)
{
    std::vector<CG::Result> results, planeResult;

    // Caso a colisão do objeto esteja desligada retornamos uma lista de colisões vazia
    if (!colision) {
        return results;
    }

    // Verificando colisões com a base do cone
    planeResult = basePlane.verifyCollision(P0, d);
    if(!planeResult.empty()){
        if((planeResult[0].Pint - basePlane.point).norm() <= radius){
            results.push_back(planeResult[0]);
        }
    }

    LinearAlgebra::Vector4Df v = vertex - P0;

    float a, b, c, delta;

    a = powf((d.dot_product(unitaryDirection)), 2) - d.dot_product(d)*cosTheta;
    b = powf((v.dot_product(unitaryDirection)), 2)*cosTheta - (v.dot_product(unitaryDirection)*d.dot_product(unitaryDirection));
    c = powf((v.dot_product(unitaryDirection)), 2) - v.dot_product(v)*powf(cosTheta, 2);

    delta = powf(b,2) - 4*a*c;

    /*
     *  Calculando o valor de delta podemos chegar ao número inicial de colisões:
     *    -Se delta < 0 não ocorre nenhuma colisão
     *    -Se delta = 0 ocorre apenas uma colisão
     *    -Se delta > 0 ocorrem duas colisões
     */

    if (delta < 0){
        // Nenhuma Colisão
        return results;
    }
    else if(delta == 0) {
        // Uma colisão
        float tint = -b/(2*a);
        LinearAlgebra::Vector4Df Pint =  P0 + d*tint;

        if((vertex - Pint).dot_product(unitaryDirection) <= height){
            results.push_back(CG::Result{
                    tint,
                    Pint,
                    normal(Pint),
                    material,
                    label
            });
        }


        return results;
    }
    else{
        // Duas colisões
        float tint = (-b-sqrtf(delta))/(2*a);
        LinearAlgebra::Vector4Df Pint =  P0 + d*tint;

        if((vertex - Pint).dot_product(unitaryDirection) <= height){

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
        }

        return results;
    }
}

LinearAlgebra::Vector4Df Cone::normal(LinearAlgebra::Vector4Df Pint)
{
    LinearAlgebra::Vector4Df PintMinusBC = Pint - baseCenter;
    float aux = PintMinusBC.dot_product(unitaryDirection);
    LinearAlgebra::Vector4Df Pe = baseCenter + unitaryDirection*aux;
    // = equação da reta com (basecenter, aux, unitaryDirection): retorna Ponto (V4Df) base.x + aux * unitary.x. y and z
    //tomei como base o código da fernanda, que está com uma nomenclatura diferente do pdf do creto, mas aparenta ter a mesma forma, só n tenho certeza da declaração do Pe
    LinearAlgebra::Vector4Df PintMinusPe = Pint - Pe;
    LinearAlgebra::Vector4Df PiV = vertex - Pint;

    LinearAlgebra::Vector4Df T = PiV.cross_product(PintMinusPe);
    LinearAlgebra::Vector4Df N = T.cross_product(PiV);

    return N/N.norm();

}