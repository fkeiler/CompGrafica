//
// Created by daniel on 03/12/2019.
//

#ifndef TRABALHO_CLUSTER_HPP
#define TRABALHO_CLUSTER_HPP

#include "CG.hpp"

// Objetos
#include "Plane.hpp"
#include "Sphere.hpp"
#include "Cylinder.hpp"
#include "Cone.hpp"
#endif //TRABALHO_CLUSTER_HPP

#include "Triangle.hpp"
#include "Box.hpp"

class Cluster
{
public:
    Sphere colisionSphere;

    std::vector<Cluster> Clusters;
    std::vector<Plane> Planes;
    std::vector<Sphere> Spheres;
    std::vector<Cylinder> Cylinders;
    std::vector<Cone> Cones;
    std::vector<Triangle> Triangles;
    std::vector<Box> Boxes;

    // Constructor
    Cluster(LinearAlgebra::Vector4Df pi, float ri);
    Cluster scenario();
};
