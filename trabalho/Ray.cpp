//
// Created by daniel on 04/10/2019.
//

#include "Ray.hpp"

Ray::Ray(Coordinate p0i)
{
    P0 = p0i;
}

Coordinate Ray::point(double t)
{
    return P0 + d*t;
}