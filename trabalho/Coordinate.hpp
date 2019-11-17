//
// Created by daniel on 02/10/2019.
//

#ifndef TRABALHO_COORDINATE_HPP
#define TRABALHO_COORDINATE_HPP

#include <iostream>
#include <cmath>

class Coordinate
{
public:
    double *value;

    Coordinate();
    Coordinate(double *);
    Coordinate(std::initializer_list<double> inputValue);

    // Sobrecarga de operadores
    Coordinate operator+(Coordinate);
    Coordinate operator-(Coordinate);
    Coordinate operator*(Coordinate);
    Coordinate operator/(Coordinate);
    Coordinate operator+(double);
    Coordinate operator-(double);
    Coordinate operator*(double);
    Coordinate operator/(double);

    // Operações de AL
    double norm();
    Coordinate normalize();
    double dot(Coordinate);
    Coordinate cross(Coordinate);

    // To String
    friend std::ostream& operator<<(std::ostream& out, const Coordinate& c);
};


#endif //TRABALHO_COORDINATE_HPP
