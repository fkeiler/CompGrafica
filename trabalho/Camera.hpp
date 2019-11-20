//
// Created by daniel on 16/11/2019.
//

#ifndef TRABALHO_CAMERA_HPP
#define TRABALHO_CAMERA_HPP

#include "CG.hpp"

class Camera {
    LinearAlgebra::Matrix4Df transformationMatrix;
    LinearAlgebra::Vector4Df P0, lookAt, viewUp, d;

    CG::Result *plateBuffer;
    float plateDistance, plateSizeVertical, plateSizeHorizontal;
    int numberOfHolesVertical, numberOfHolesHorizontal;

    Camera(float, float, float, int, int);
};


#endif //TRABALHO_CAMERA_HPP
