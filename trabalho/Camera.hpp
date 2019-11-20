//
// Created by daniel on 16/11/2019.
//

#ifndef TRABALHO_CAMERA_HPP
#define TRABALHO_CAMERA_HPP

#include "CG.hpp"

class Camera {
    LinearAlgebra::Matrix4Df transformationMatrix;
    LinearAlgebra::Vector4Df P0, lookAt, viewUp, d;

    std::vector<CG::Result> buffer;

    float plateDistance, sizeVertical, sizeHorizontal;
    int nHolesVertical, nHolesHorizontal;

    Camera(float, float, float, int, int);
    LinearAlgebra::Vector4Df convert(LinearAlgebra::Vector4Df coord);
};

#endif //TRABALHO_CAMERA_HPP
