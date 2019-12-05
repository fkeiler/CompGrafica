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
    Cluster scenaryObjects({10, 0, 10, 1}, 20);

    float fenceHeigh = 1.1;

    return scenaryObjects;
}