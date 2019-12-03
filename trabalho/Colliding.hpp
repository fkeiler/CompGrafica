//
// Created by felip on 03/12/2019.
//

#ifndef TRABALHO_COLLIDING_HPP
#define TRABALHO_COLLIDING_HPP

#include "CG.hpp"

class Colliding {
    public:
        virtual std::vector<CG::Result> verifyCollision(LinearAlgebra::Vector4Df P0, LinearAlgebra::Vector4Df d) = 0;
};

#endif //TRABALHO_COLLIDING_HPP
