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

LinearAlgebra::Vector4Df Camera::convertCoord(LinearAlgebra::Vector4Df vector)
{
    return transformationMatrix * vector;
}

Cluster Camera::convertObjects(Cluster objects)
{
    Cluster returnCluster(objects.colisionSphere.center, objects.colisionSphere.radius);
    returnCluster.colisionSphere.center = convertCoord(returnCluster.colisionSphere.center);

    // Clusters
    if(!objects.Clusters.empty()){
        for(auto& cluster: objects.Clusters){
            returnCluster.Clusters.push_back(convertObjects(cluster));
        }
    }

    // Planes
    if(!objects.Planes.empty()){
        for(auto& plane: objects.Planes){
            plane.point = convertCoord(plane.point);
            plane.normal = convertCoord(plane.normal);

            returnCluster.Planes.push_back(plane);
        }
    }

    // Spheres
    if(!objects.Spheres.empty()){
        for(auto& sphere: objects.Spheres){
            sphere.center = convertCoord(sphere.center);

            returnCluster.Spheres.push_back(sphere);
        }
    }
    // Cylinders
    if(!objects.Cylinders.empty()){
        for(auto& cylinder: objects.Cylinders){
            cylinder.baseCenter = convertCoord(cylinder.baseCenter);
            cylinder.unitaryDirection = convertCoord(cylinder.unitaryDirection);

            returnCluster.Cylinders.push_back(cylinder);
        }
    }

    // Cones
    if(!objects.Cones.empty()){
        for(auto& cone: objects.Cones){
            cone.vertex = convertCoord(cone.vertex);
            cone.baseCenter = convertCoord(cone.baseCenter);
            cone.unitaryDirection = convertCoord(cone.unitaryDirection);

            returnCluster.Cones.push_back(cone);
        }
    }
    // Triangles
    if(!objects.Triangles.empty()){
        for(auto& triangle: objects.Triangles){
            triangle.p1 = convertCoord(triangle.p1);
            triangle.p2 = convertCoord(triangle.p2);
            triangle.p3 = convertCoord(triangle.p3);

            triangle.vertices.clear();

            triangle.vertices.push_back(triangle.p1);
            triangle.vertices.push_back(triangle.p2);
            triangle.vertices.push_back(triangle.p3);

            returnCluster.Triangles.push_back(triangle);
        }
    }

    return returnCluster;
}

std::vector<CG::Result> Camera::verifyClusterCollision(Cluster cluster, LinearAlgebra::Vector4Df P0i, LinearAlgebra::Vector4Df di)
{
    std::vector<CG::Result> result, tempResult;

    // Verificar se colide com o cluster
    if(!cluster.colisionSphere.verifyCollision(P0i, di).empty())
    {
        // Caso tenham clusters dentro do cluster, verificamos possíveis colisões com ele
        if(!cluster.Clusters.empty()) {
            for (auto& tempCluster: cluster.Clusters){
                tempResult = verifyClusterCollision(tempCluster, P0i, di);
                if(!tempResult.empty()){
                    result.insert(result.end(), tempResult.begin(), tempResult.end());
                }
            }
        }

        // Verificar colisões com planos
        if(!cluster.Planes.empty()) {
            for (auto& plane: cluster.Planes){
                tempResult = plane.verifyCollision(P0i, di);
                if(!tempResult.empty()){
                    result.insert(result.end(), tempResult.begin(), tempResult.end());
                }
            }
        }

        // Verificar colisões com esferas
        if(!cluster.Spheres.empty()) {
            for (auto& sphere: cluster.Spheres){
                tempResult = sphere.verifyCollision(P0i, di);
                if(!tempResult.empty()){
                    result.insert(result.end(), tempResult.begin(), tempResult.end());
                }
            }
        }
    }

    return result;
}

void Camera::renderScenery(Cluster objetcs)
{
    std::vector<CG::Result> result, tempResult;
    CG::Result noneResult{0,LinearAlgebra::Vector4Df{0, 0, 0, 1},LinearAlgebra::Vector4Df{0, 0, 0, 0},CG::sBlackMaterial(), -127};

    LinearAlgebra::Vector4Df platePoint{0, 0, 0, 1}, p0{0, 0, 0, 1};
    float deltaX = sizeHorizontal/(float)nHolesHorizontal, deltaY = sizeVertical/(float)nHolesVertical;
    int minIndex;

    for(int line = 0; line < nHolesVertical; line++){
        for(int column = 0; column < nHolesHorizontal; column++){
            platePoint.x = -sizeHorizontal/2 + deltaX/2 + (float)column*deltaX;
            platePoint.y = sizeVertical/2 + deltaY/2 - (float)line*deltaY;
            platePoint.z = -(float)plateDistance;

            d = (platePoint - p0).normalize();

            // Calcula possiveis colisões com o cluster naquele momento
            if(!objetcs.colisionSphere.verifyCollision(p0, d).empty()){
                tempResult = verifyClusterCollision(objetcs, p0, d);
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

