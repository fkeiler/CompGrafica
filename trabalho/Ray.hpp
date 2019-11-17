//
// Created by daniel on 04/10/2019.
//

#ifndef TRABALHO_RAY_HPP
#define TRABALHO_RAY_HPP

#include "Coordinate.hpp"

class Ray
{
public:
    Coordinate P0; // Ponto de partida do raio
    Coordinate d; // Vetor de direção do raio

    Ray(Coordinate p0i); // Construtor do raio utilizando apenas o ponto de partida
    Coordinate point(double t); // Ponto P(t) sendo t um escalar que indica a distância entre o ponto P(t) e o ponto P0
};


#endif //TRABALHO_RAY_HPP
