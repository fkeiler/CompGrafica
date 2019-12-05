//
// Created by daniel on 03/12/2019.
//

#include "Cluster.hpp"

Cluster::Cluster(LinearAlgebra::Vector4Df pi, float ri)
{
    colisionSphere.center = pi;
    colisionSphere.radius = ri;
};


Cluster Cluster::scenario()
{
    Cluster scenaryObjects({17.5, 0, 17.5, 1}, 40);

    Cluster waterTank({25, 5, 25, 1}, 6);

    float fenceVertHeigh = 1.1;
    float fenceHoriHeigh = 23;
    float fenceRadius = 0.1;
    LinearAlgebra::Vector4Df dx{1, 0, 0, 0};
    LinearAlgebra::Vector4Df dy{0, 1, 0, 0};
    LinearAlgebra::Vector4Df dz{0, 0, 1, 0};
    LinearAlgebra::Vector4Df fence1VertCoord{6, 0, 6, 1};
    LinearAlgebra::Vector4Df fence2VertCoord{17.5, 0, 6, 1};
    LinearAlgebra::Vector4Df fence3VertCoord{29, 0, 6, 1};
    LinearAlgebra::Vector4Df fence4VertCoord{6, 0, 17.5, 1};
    LinearAlgebra::Vector4Df fence5VertCoord{29, 0, 17.5, 1};
    LinearAlgebra::Vector4Df fence6VertCoord{6, 0, 29, 1};
    LinearAlgebra::Vector4Df fence7VertCoord{17.5, 0, 29, 1};
    LinearAlgebra::Vector4Df fence8VertCoord{29, 0, 29, 1};

    LinearAlgebra::Vector4Df fence1HoriCoord{6, 0.3, 6, 1};
    LinearAlgebra::Vector4Df fence2HoriCoord{6, 0.6, 6, 1};
    LinearAlgebra::Vector4Df fence3HoriCoord{6, 0.9, 6, 1};

    LinearAlgebra::Vector4Df fence4HoriCoord{29, 0.3, 29, 1};
    LinearAlgebra::Vector4Df fence5HoriCoord{29, 0.6, 29, 1};
    LinearAlgebra::Vector4Df fence6HoriCoord{29, 0.9, 29, 1};

    scenaryObjects.Cylinders.emplace_back(fenceVertHeigh, fenceRadius, fence1VertCoord, dy, CG::Wood(), 1);
    scenaryObjects.Cylinders.emplace_back(fenceVertHeigh, fenceRadius, fence2VertCoord, dy, CG::Wood(), 2);
    scenaryObjects.Cylinders.emplace_back(fenceVertHeigh, fenceRadius, fence3VertCoord, dy, CG::Wood(), 3);
    scenaryObjects.Cylinders.emplace_back(fenceVertHeigh, fenceRadius, fence4VertCoord, dy, CG::Wood(), 4);
    scenaryObjects.Cylinders.emplace_back(fenceVertHeigh, fenceRadius, fence5VertCoord, dy, CG::Wood(), 5);
    scenaryObjects.Cylinders.emplace_back(fenceVertHeigh, fenceRadius, fence6VertCoord, dy, CG::Wood(), 6);
    scenaryObjects.Cylinders.emplace_back(fenceVertHeigh, fenceRadius, fence7VertCoord, dy, CG::Wood(), 7);
    scenaryObjects.Cylinders.emplace_back(fenceVertHeigh, fenceRadius, fence8VertCoord, dy, CG::Wood(), 8);

    scenaryObjects.Cylinders.emplace_back(fenceHoriHeigh, fenceRadius, fence1HoriCoord, dz, CG::Wood(), 1);
    scenaryObjects.Cylinders.emplace_back(fenceHoriHeigh, fenceRadius, fence2HoriCoord, dz, CG::Wood(), 2);
    scenaryObjects.Cylinders.emplace_back(fenceHoriHeigh, fenceRadius, fence3HoriCoord, dz, CG::Wood(), 3);

    scenaryObjects.Cylinders.emplace_back(fenceHoriHeigh, fenceRadius, fence1HoriCoord, dx, CG::Wood(), 4);
    scenaryObjects.Cylinders.emplace_back(fenceHoriHeigh, fenceRadius, fence2HoriCoord, dx, CG::Wood(), 5);
    scenaryObjects.Cylinders.emplace_back(fenceHoriHeigh, fenceRadius, fence3HoriCoord, dx, CG::Wood(), 6);

    scenaryObjects.Cylinders.emplace_back(fenceHoriHeigh, fenceRadius, fence4HoriCoord, dz*-1, CG::Wood(), 1);
    scenaryObjects.Cylinders.emplace_back(fenceHoriHeigh, fenceRadius, fence5HoriCoord, dz*-1, CG::Wood(), 2);
    scenaryObjects.Cylinders.emplace_back(fenceHoriHeigh, fenceRadius, fence6HoriCoord, dz*-1, CG::Wood(), 3);

    scenaryObjects.Cylinders.emplace_back(fenceHoriHeigh, fenceRadius, fence4HoriCoord, dx*-1, CG::Wood(), 4);
    scenaryObjects.Cylinders.emplace_back(fenceHoriHeigh, fenceRadius, fence5HoriCoord, dx*-1, CG::Wood(), 5);
    scenaryObjects.Cylinders.emplace_back(fenceHoriHeigh, fenceRadius, fence6HoriCoord, dx*-1, CG::Wood(), 6);

    scenaryObjects.Planes.emplace_back(scenaryObjects.colisionSphere.center, dy, CG::sGreenMaterial(), 1);


    return scenaryObjects;
}