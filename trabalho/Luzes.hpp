//
// Created by felip on 19/11/2019.
//

#ifndef TRABALHO_LUZES_HPP
#define TRABALHO_LUZES_HPP

#include "CG.hpp"

namespace Luz{
    struct Ambiente{
        struct {
            LinearAlgebra::Vector3Df intensidade;
        };

        LinearAlgebra::Vector3Df iluminar(const CG::Result *res){
            return this->intensidade * res->objectMaterial.Ia;
        }
    };

    struct Remota{
        struct{
            LinearAlgebra::Vector4Df direcao; // Vetor na direção dos raios
            LinearAlgebra::Vector3Df Ia, Id, Is; // Intensidade ambiente, difusa, especular
        };

        LinearAlgebra::Vector3Df iluminar(CG::Result *res, LinearAlgebra::Vector4Df observador){
            LinearAlgebra::Vector3Df cor = Ia * res->objectMaterial.Ia;
            /* Iluminação Difusa */
            float fatorDifuso = (LinearAlgebra::Vector4Df{0, 0, 0, 0} - this->direcao).dot_product(res->normal);
            if(fatorDifuso <= 0) return cor;
            cor = cor + (Id*fatorDifuso*res->objectMaterial.Id);
            /* Iluminação Especular */
            LinearAlgebra::Vector4Df reflexao = direcao - res->normal * 2 * direcao.dot_product(res->normal);
            float fatorEspecular = reflexao.dot_product(observador - res->Pint);
            cor = cor + (Is*fatorEspecular*res->objectMaterial.Is);

            return cor;
        }
    };
}

#endif //TRABALHO_LUZES_HPP
