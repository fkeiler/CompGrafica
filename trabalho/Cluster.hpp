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
/*
#include "Triangle.hpp"
#include "Box.hpp"
*/
class Cluster
{
public:
    std::vector<Cluster> Clusteres;
    std::vector<Plane> Planes;
    std::vector<Sphere> Spheres;
    std::vector<Cylinder> Cyliders;
    std::vector<Cone> Cones;
    //std::vector<Triangle> Triangles;
    //std::vector<Box> Boxes;

    Cluster(); // Construtor Padrão
};

#endif //TRABALHO_CLUSTER_HPP
