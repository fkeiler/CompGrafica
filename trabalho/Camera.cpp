//
// Created by daniel on 16/11/2019.
//

#include "Camera.hpp"

Camera::Camera(LinearAlgebra::Vector4Df pi, LinearAlgebra::Vector4Df li, LinearAlgebra::Vector4Df vi, int height, int width)
{
    P0 = pi; lookAt = li; viewUp = vi; // P0, Look At, View UP
    nHolesVertical = height; nHolesHorizontal = width;

    // Criando matriz de transformação
    LinearAlgebra::Vector4Df Kc = (P0-lookAt).normalize();
    LinearAlgebra::Vector4Df Ic = (viewUp-P0).cross_product(Kc).normalize();
    LinearAlgebra::Vector4Df Jc = Kc.cross_product(Ic);

    transformationMatrix = LinearAlgebra::indentityMatrix();

    for(int i = 0; i < 3; i++){
        transformationMatrix._matrix[0][i] = Ic.value[i];
        transformationMatrix._matrix[1][i] = Jc.value[i];
        transformationMatrix._matrix[2][i] = Kc.value[i];
    }

    transformationMatrix._matrix[0][3] = -P0.dot_product(Ic);
    transformationMatrix._matrix[1][3] = -P0.dot_product(Jc);
    transformationMatrix._matrix[2][3] = -P0.dot_product(Kc);

    plateDistance = 4; sizeVertical = 3; sizeHorizontal = 4;
}

LinearAlgebra::Vector4Df Camera::convert(LinearAlgebra::Vector4Df coord)
{
    return transformationMatrix * coord;
}

void Camera::renderScenery(std::vector<Cluster*> objetos)
{
    std::vector<CG::Result> result, tempResult;
    CG::Result noneResult{0,LinearAlgebra::Vector4Df{0, 0, 0, 1},LinearAlgebra::Vector4Df{0, 0, 0, 0},CG::sBlackMaterial(),"Null"};
    LinearAlgebra::Vector4Df platePoint{0, 0, 0, 1}, p0{0, 0, 0, 1};
    float deltaX = sizeHorizontal/(float)nHolesHorizontal, deltaY = sizeVertical/(float)nHolesVertical;
    int minIndex;

    for(int line = 0; line < nHolesVertical; line++){
        for(int column = 0; column < nHolesHorizontal; column++){
            platePoint.x = -sizeHorizontal/2 + deltaX/2 + (float)column*deltaX;
            platePoint.y = sizeVertical/2 + deltaY/2 - (float)line*deltaY;
            platePoint.z = -(float)plateDistance;

            d = (platePoint - p0).normalize();

            for(Cluster* c : objetos){
                tempResult = c->verifyCollision(p0, d);
                if(!tempResult.empty()){
                    result.insert(result.end(), tempResult.begin(), tempResult.end());
                }
            }
            // Verifica se aconteceu colisão
            if(!result.empty()){
                // Guarda qual colisão aconteceu primeiro
                minIndex = 0;

                for(int i = 0; i < result.size(); i++){
                    if(result[i].t < result[minIndex].t) {
                        minIndex = i;
                    }
                }

                buffer.push_back(result[minIndex]);
            } else {
                buffer.push_back(noneResult);
            }

            result.clear(); tempResult.clear();
        }
    }
}

