//
// Created by daniel on 02/10/2019.
//

#include "Coordinate.hpp"

// Construtores
Coordinate::Coordinate()
{
    value = new double[4];

    for (int i = 0; i < 3; i++) {
        value[i] = 0.0;
    }
    value[3] = 1.0;
}

Coordinate::Coordinate(double *inputValue)
{
    value = new double[4];

    for (int i = 0; i < 4; i++) {
        value[i] = inputValue[i];
    }
}

Coordinate::Coordinate(std::initializer_list<double> inputValue)
{
    value = new double[4];

    for (int i = 0; i < 4; i++) {
        std::copy(inputValue.begin(), inputValue.end(), value);
    }
}


// Sobrecarga de operações
// Operações entre pontos/vetores
Coordinate Coordinate::operator+(Coordinate inputCoordinate)
{
    double result[4];

    for (int i = 0; i < 4; i++) {
        result[i] = value[i] + inputCoordinate.value[i];
    }

    if(result[3] > 1){
        result[3] = 1;
    }

    return {result};
}

Coordinate Coordinate::operator-(Coordinate inputCoordinate)
{
    double result[4];

    for (int i = 0; i < 4; i++) {
        result[i] = value[i] - inputCoordinate.value[i];
    }

    if(result[3] < 0){
        result[3] = 0;
    }

    return {result};
}

Coordinate Coordinate::operator*(Coordinate inputCoordinate)
{
    double result[4];

    for (int i = 0; i < 4; i++) {
        result[i] = value[i] * inputCoordinate.value[i];
    }

    return {result};
}

Coordinate Coordinate::operator/(Coordinate inputCoordinate)
{
    double result[4];

    for (int i = 0; i < 4; i++) {
        result[i] = value[i] / inputCoordinate.value[i];
    }

    return {result};
}


// Operações com escalares
// Adição de escalar
Coordinate Coordinate::operator+(double e)
{
    double result[4];

    for (int i = 0; i < 3; i++) {
        result[i] = value[i] + e;
    }

    result[3] = value[3];

    return {result};
}

// Subtração de escalar
Coordinate Coordinate::operator-(double e)
{
    double result[4];

    for (int i = 0; i < 3; i++) {
        result[i] = value[i] - e;
    }

    result[3] = value[3];

    return {result};
}

// Multiplicação por escalar
Coordinate Coordinate::operator*(double e)
{
    double result[4];

    for (int i = 0; i < 3; i++) {
        result[i] = value[i] * e;
    }

    result[3] = value[3];

    return {result};
}

// Divisão por escalar
Coordinate Coordinate::operator/(double e)
{
    double result[4];

    for (int i = 0; i < 3; i++) {
        result[i] = value[i]/e;
    }

    result[3] = value[3];

    return {result};
}

// Norma
double Coordinate::norm()
{
    return sqrt(pow(value[0],2)+ pow(value[1],2)+ pow(value[2],2));
}

// Normaliza
Coordinate Coordinate::normalize()
{
    Coordinate result={value};

    return result/norm();
}

// Dot Product
double Coordinate::dot(Coordinate w)
{
    double result = 0;

    result = value[0] * w.value[0]
           + value[1] * w.value[1]
           + value[2] * w.value[2];

    return result;
}

// Cross Product
Coordinate Coordinate::cross(Coordinate w)
{
    Coordinate r = {value[1]*w.value[2] - value[2]*w.value[1],
                    value[2]*w.value[0] - value[0]*w.value[2],
                    value[0]*w.value[1] - value[1]*w.value[0],
                    value[3]};
    return r;
}

// Para poder printar o valor no cout sem problemas
std::ostream& operator<<(std::ostream& out, const Coordinate& c)
{
    out << "[" << c.value[0] << ", ";
    out <<  c.value[1] << ", ";
    out <<  c.value[2] << ", ";
    out <<  c.value[3] << "]";

    return out;
}
