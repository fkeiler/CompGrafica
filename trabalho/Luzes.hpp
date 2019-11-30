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
            /* Iluminação Ambiente */
            LinearAlgebra::Vector3Df cor = Ia * res->objectMaterial.Ia;
            /* Iluminação Difusa */
            float fatorDifuso = (LinearAlgebra::Vector4Df{0, 0, 0, 0} - this->direcao).dot_product(res->normal); // Cosseno do angulo entre a normal e a iluminação
            if(fatorDifuso <= 0) return cor;
            cor = cor + (Id*fatorDifuso*res->objectMaterial.Id);
            /* Iluminação Especular */
            LinearAlgebra::Vector4Df reflexao = (direcao + (res->normal * 2)) * direcao.dot_product(res->normal); // Vetor refletido
            float fatorEspecular = reflexao.dot_product(observador - res->Pint); // Cosseno do angulo entre vetor refletido e o vetor em direção o observador
            cor = cor + (Is*powf(fatorEspecular, res->objectMaterial.m)*res->objectMaterial.Is);

            return cor;
        }
    };

    struct Pontual{
        struct{
            LinearAlgebra::Vector4Df origem;
            LinearAlgebra::Vector3Df Ia, Id, Is;
            float atenuacaoLinear;
        };

        LinearAlgebra::Vector3Df iluminar(CG::Result *res, LinearAlgebra::Vector4Df observador){
            /* Iluminação Ambiente */
            LinearAlgebra::Vector3Df cor = Ia * res->objectMaterial.Ia;
            /* Iluminação Difusa */
            LinearAlgebra::Vector4Df direcao = (res->Pint - origem).normalize();
            float atenuacao =  1 / (atenuacaoLinear * (res->Pint - origem).dot_product(direcao));
            float fatorDifuso = (LinearAlgebra::Vector4Df{0, 0, 0, 0} - direcao).dot_product(res->normal); // Cosseno do angulo entre a normal e a iluminação
            if(fatorDifuso <= 0) return cor;
            cor = cor + (Id*fatorDifuso*res->objectMaterial.Id*intensidadeAtenuacao);
            /* Iluminação Especular */
            LinearAlgebra::Vector4Df reflexao = (direcao + (res->normal * 2)) * direcao.dot_product(res->normal); // Vetor refletido
            float fatorEspecular = reflexao.dot_product(observador - res->Pint); // Cosseno do angulo entre vetor refletido e o vetor em direção o observador
            cor = cor + (Is*powf(fatorEspecular, res->objectMaterial.m)*res->objectMaterial.Is*atenuacaoLinear);
        }
    };

    struct Spot{
        struct{
            LinearAlgebra::Vector4Df origem;
            LinearAlgebra::Vector3Df Ia, Id, Is;
            float atenuacaoLinear, cossenoAbertura;
        };

        LinearAlgebra::Vector3Df iluminar(CG::Result *res, LinearAlgebra::Vector4Df observador){
            /* Iluminação Ambiente */
            LinearAlgebra::Vector3Df cor = Ia * res->objectMaterial.Ia;
            /* Iluminação Difusa */
            LinearAlgebra::Vector4Df direcao = (res->Pint - origem).normalize();
            float atenuacao =  1 / (atenuacaoLinear * (res->Pint - origem).dot_product(direcao));
            float fatorDifuso = (LinearAlgebra::Vector4Df{0, 0, 0, 0} - direcao).dot_product(res->normal); // Cosseno do angulo entre a normal e a iluminação
            if(fatorDifuso >= cossenoAbertura){
                atenuacao *= cossenoAbertura/fatorDifuso;
            }
            if(fatorDifuso <= 0) return cor;
            cor = cor + (Id*fatorDifuso*res->objectMaterial.Id*intensidadeAtenuacao);
            /* Iluminação Especular */
            LinearAlgebra::Vector4Df reflexao = (direcao + (res->normal * 2)) * direcao.dot_product(res->normal); // Vetor refletido
            float fatorEspecular = reflexao.dot_product(observador - res->Pint); // Cosseno do angulo entre vetor refletido e o vetor em direção o observador
            cor = cor + (Is*fatorEspecular*res->objectMaterial.Is*atenuacao);
        }
    };
}

#endif //TRABALHO_LUZES_HPP
