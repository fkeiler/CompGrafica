//
// Created by daniel on 16/11/2019.
//

#ifndef TRABALHO_CAMERA_HPP
#define TRABALHO_CAMERA_HPP

#include "CG.hpp"
#include "Sphere.hpp"
#include "Plane.hpp"

class Camera
{
public:
    LinearAlgebra::Matrix4Df transformationMatrix;
    LinearAlgebra::Vector4Df P0, lookAt, viewUp, d;

    std::vector<CG::Result> buffer;

    float plateDistance, sizeVertical, sizeHorizontal;
    int nHolesVertical, nHolesHorizontal;

    Camera( LinearAlgebra::Vector4Df pi, LinearAlgebra::Vector4Df li, LinearAlgebra::Vector4Df vi, int height, int width );
    LinearAlgebra::Vector4Df convert(LinearAlgebra::Vector4Df coord);
    void renderScenary(Sphere esfera, Plane plano);
};

#endif //TRABALHO_CAMERA_HPP
