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

    LinearAlgebra::Vector4Df dx{1, 0, 0, 0};
    LinearAlgebra::Vector4Df dy{0, 1, 0, 0};
    LinearAlgebra::Vector4Df dz{0, 0, 1, 0};

    float waterTankTopRadius = 1.5;
    float waterTankTopHeight = 0.8;

    float waterTankRadius = 1;
    float waterTankHeight = 3;

    float waterTankBaseHeight = 0.1;
    float waterTankBaseRadius = 1.4;

    float waterTankBaseLegRadius = 0.3;
    float waterTankBaseLegHeight = 4;

    LinearAlgebra::Vector4Df wtbl1Coord{24.2, 0, 24.2, 1};
    LinearAlgebra::Vector4Df wtbl2Coord{25.8, 0, 24.2, 1};
    LinearAlgebra::Vector4Df wtbl3Coord{24.2, 0, 25.8, 1};
    LinearAlgebra::Vector4Df wtbl4Coord{25.8, 0, 25.8, 1};
    LinearAlgebra::Vector4Df wtbCoord{25, 4, 25, 1};
    LinearAlgebra::Vector4Df wtCoord{25, 4.1, 25, 1};
    LinearAlgebra::Vector4Df wttCoord{25, 7.1, 25, 1};

    waterTank.Cylinders.emplace_back(waterTankBaseLegHeight, waterTankBaseLegRadius, wtbl1Coord, dy, CG::sGrayMaterial(), 1);
    waterTank.Cylinders.emplace_back(waterTankBaseLegHeight, waterTankBaseLegRadius, wtbl2Coord, dy, CG::sGrayMaterial(), 1);
    waterTank.Cylinders.emplace_back(waterTankBaseLegHeight, waterTankBaseLegRadius, wtbl3Coord, dy, CG::sGrayMaterial(), 1);
    waterTank.Cylinders.emplace_back(waterTankBaseLegHeight, waterTankBaseLegRadius, wtbl4Coord, dy, CG::sGrayMaterial(), 1);
    waterTank.Cylinders.emplace_back(waterTankBaseHeight, waterTankBaseRadius, wtbCoord, dy, CG::sGrayMaterial(), 2 );
    waterTank.Cylinders.emplace_back(waterTankHeight, waterTankRadius, wtCoord, dy, CG::WaterTank(), 3 );
    waterTank.Cones.emplace_back(waterTankTopRadius, waterTankTopHeight, wttCoord, dy, CG::sRedMaterial(), 4 );

    scenaryObjects.Clusters.push_back(waterTank);

    float fenceVertHeigh = 1.1;
    float fenceHoriHeigh = 23;
    float fenceRadius = 0.1;

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