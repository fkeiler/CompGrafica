//
// Created by felip on 19/11/2019.
//

#ifndef TRABALHO_LUZES_HPP
#define TRABALHO_LUZES_HPP

#include "CG.hpp"

namespace Luz{
    struct Luz {
    public:
        virtual LinearAlgebra::Vector3Df iluminar(CG::Result *res, LinearAlgebra::Vector4Df observador) = 0;
    };

    class Ambiente : public Luz{
    public:
        LinearAlgebra::Vector3Df intensidade;

        Ambiente(LinearAlgebra::Vector3Df cor){
            intensidade = cor;
        }

        LinearAlgebra::Vector3Df iluminar(CG::Result *res, LinearAlgebra::Vector4Df observador){
            return intensidade * res->objectMaterial.Ia;
        }
    };

    class Remota : public Luz{
    public:
        LinearAlgebra::Vector4Df direcao; // Vetor na direção dos raios
        LinearAlgebra::Vector3Df Ia, Id, Is; // Intensidade ambiente, difusa, especular

        Remota(LinearAlgebra::Vector4Df dir, LinearAlgebra::Vector3Df Amb, LinearAlgebra::Vector3Df Dir, LinearAlgebra::Vector3Df Spec){
            direcao = dir.normalize();
            Ia = Amb;
            Id = Dir;
            Is = Spec;
        }

        LinearAlgebra::Vector3Df iluminar(CG::Result *res, LinearAlgebra::Vector4Df observador) override{
            /* Iluminação Ambiente */
            LinearAlgebra::Vector3Df cor = Ia * res->objectMaterial.Ia;

            /* Iluminação Difusa */
            float fatorDifuso = (-direcao).dot_product(res->normal); // Cosseno do angulo entre a normal e a iluminação
            if(fatorDifuso < 0) return cor;
            cor += (Id*fatorDifuso*res->objectMaterial.Id);

            /* Iluminação Especular */
            LinearAlgebra::Vector4Df reflexao =  direcao - (res->normal * 2 * direcao.dot_product(res->normal)); // Vetor refletido
            float fatorEspecular = reflexao.dot_product(observador - res->Pint); // Cosseno do angulo entre vetor refletido e o vetor em direção o observador
            if(fatorEspecular < 0) return cor;
            cor += (Is*powf(fatorEspecular, res->objectMaterial.m)*res->objectMaterial.Is);

            if(cor.x > 1) cor.x = 1;
            if(cor.y > 1) cor.y = 1;
            if(cor.z > 1) cor.z = 1;

            return cor;
        }
    };

    class Pontual : public Luz{
    public:
        LinearAlgebra::Vector4Df origem;
        LinearAlgebra::Vector3Df Ia, Id, Is;
        float atenuacaoLinear;

        Pontual(LinearAlgebra::Vector4Df o, LinearAlgebra::Vector3Df amb, LinearAlgebra::Vector3Df dif, LinearAlgebra::Vector3Df spc, float a){
            origem = o;
            Ia = amb;
            Id = dif;
            Is = spc;
            atenuacaoLinear = a;
        }

        LinearAlgebra::Vector3Df iluminar(CG::Result *res, LinearAlgebra::Vector4Df observador){
            /* Iluminação Ambiente */
            LinearAlgebra::Vector3Df cor = Ia * res->objectMaterial.Ia;

            /* Iluminação Difusa */
            LinearAlgebra::Vector4Df direcao = (origem - res->Pint);
            float atenuacao = 1 / (direcao.norm() * atenuacaoLinear);
            direcao = direcao.normalize();
            float fatorDifuso = (-direcao).dot_product(res->normal); // Cosseno do angulo entre a normal e a iluminação
            if(fatorDifuso < 0) return cor;
            cor += (Id * fatorDifuso * res->objectMaterial.Id * atenuacao);

            /* Iluminação Especular */
            LinearAlgebra::Vector4Df reflexao =  direcao - (res->normal * 2 * direcao.dot_product(res->normal)); // Vetor refletido
            float fatorEspecular = reflexao.dot_product(observador - res->Pint); // Cosseno do angulo entre vetor refletido e o vetor em direção o observador
            if(fatorEspecular < 0) return cor;
            cor += (Is*powf(fatorEspecular, res->objectMaterial.m)*res->objectMaterial.Is * atenuacao);

            if(cor.x > 1) cor.x = 1;
            if(cor.y > 1) cor.y = 1;
            if(cor.z > 1) cor.z = 1;

            return cor;
        }
    };

    class Spot : public Luz{
    public:
        LinearAlgebra::Vector4Df origem, direcaoSpot;
        LinearAlgebra::Vector3Df Ia, Id, Is;
        float atenuacaoLinear, cossenoAbertura;

        Spot(LinearAlgebra::Vector4Df o, LinearAlgebra::Vector4Df dir, LinearAlgebra::Vector3Df amb, LinearAlgebra::Vector3Df dif, LinearAlgebra::Vector3Df spc, float a, float f){
            origem = o;
            direcaoSpot = dir.normalize();
            Ia = amb;
            Id = dif;
            Is = spc;
            atenuacaoLinear = a;
            cossenoAbertura = f;
        }

        LinearAlgebra::Vector3Df iluminar(CG::Result *res, LinearAlgebra::Vector4Df observador){
            /* Iluminação Ambiente */
            LinearAlgebra::Vector3Df cor = Ia * res->objectMaterial.Ia;

            /* Iluminação Difusa */
            LinearAlgebra::Vector4Df direcao = (origem - res->Pint);
            float atenuacao =  1 / (atenuacaoLinear * direcao.norm());
            direcao = direcao.normalize();
            float fatorDifuso = (-direcao).dot_product(res->normal); // Cosseno do angulo entre a normal e a iluminação
            float anguloRaioSpot = direcao.dot_product(direcaoSpot);
            if(fatorDifuso <= 0 || anguloRaioSpot < cossenoAbertura) return cor;
            cor = cor + (Id * fatorDifuso * res->objectMaterial.Id * atenuacao);

            /* Iluminação Especular */
            LinearAlgebra::Vector4Df reflexao =  direcao - (res->normal * 2 * direcao.dot_product(res->normal)); // Vetor refletido
            float fatorEspecular = reflexao.dot_product(observador - res->Pint); // Cosseno do angulo entre vetor refletido e o vetor em direção o observador
            if(fatorEspecular < 0) return cor;
            cor += (Is*powf(fatorEspecular, res->objectMaterial.m)*res->objectMaterial.Is * atenuacao);

            if(cor.x > 1) cor.x = 1;
            if(cor.y > 1) cor.y = 1;
            if(cor.z > 1) cor.z = 1;

            return cor;
            return cor;
        }
    };
}

#endif //TRABALHO_LUZES_HPP
