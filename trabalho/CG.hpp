//
// Created by daniel on 15/11/2019.
//

#ifndef TRABALHO_CG_HPP
#define TRABALHO_CG_HPP

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

namespace LinearAlgebra {
    // Tipo de vetor de 3 valores apenas, usado para os materiais
    struct Vector3Df
    {
        union {
            struct { float x, y, z; };
            float value[3];
        };

        inline Vector3Df operator+(const Vector3Df v) {return Vector3Df{x+v.x, y+v.y, z+v.z};}
        inline Vector3Df operator-(const Vector3Df v) {return Vector3Df{x-v.x, y-v.y, z-v.z};}
        inline Vector3Df operator*(const Vector3Df v) {return Vector3Df{x*v.x, y*v.y, z*v.z};}
        inline Vector3Df operator/(const Vector3Df v) {return Vector3Df{x/v.x, y/v.y, z/v.z};}

        inline Vector3Df operator+(const float a) {return Vector3Df{x+a, y+a, z+a};}
        inline Vector3Df operator-(const float a) {return Vector3Df{x-a, y-a, z-a};}
        inline Vector3Df operator*(const float a) {return Vector3Df{x*a, y*a, z*a};}
        inline Vector3Df operator/(const float a) {return Vector3Df{x/a, y/a, z/a};}

        inline float norm(void) { return sqrtf(powf(x, 2) + powf(y,2)+powf(z,2)); }
        inline float dot_product(const Vector3Df v) {return x*v.x + y*v.y + z*v.z;}
        inline Vector3Df normalize(void) { return Vector3Df{x, y, z}/norm(); }
        inline Vector3Df cross_product(const Vector3Df v) { return Vector3Df{y*v.z - z*v.y, z*v.x - x*v.z, x*v.y - y*v.x};}

        friend std::ostream& operator<<(std::ostream& out, const Vector3Df& v) { out << "[" << v.x << ", "; out <<  v.y << ", "; out <<  v.z << ", "; out << "]"; return out; }
    };

    // Vetores de 4 valores usados para o sistema de coordenadas diferenciando pontos de vetores com o w
    struct Vector4Df
    {
        union {
            struct { float x, y, z, w; };
            float value[4];
        };

        inline Vector4Df operator+(const Vector4Df v) {return Vector4Df{x+v.x, y+v.y, z+v.z, w};}
        inline Vector4Df operator-(const Vector4Df v) {return Vector4Df{x-v.x, y-v.y, z-v.z, w-v.w};}
        inline Vector4Df operator*(const Vector4Df v) {return Vector4Df{x*v.x, y*v.y, z*v.z, w};}
        inline Vector4Df operator/(const Vector4Df v) {return Vector4Df{x/v.x, y/v.y, z/v.z, w};}

        inline Vector4Df operator+(const float a) {return Vector4Df{x+a, y+a, z+a, w};}
        inline Vector4Df operator-(const float a) {return Vector4Df{x-a, y-a, z-a, w};}
        inline Vector4Df operator*(const float a) {return Vector4Df{x*a, y*a, z*a, w};}
        inline Vector4Df operator/(const float a) {return Vector4Df{x/a, y/a, z/a, w};}

        inline float norm(void) { return sqrt(pow(x, 2) + pow(y,2)+pow(z,2)); }
        inline float dot_product(const Vector4Df v) {return x*v.x + y*v.y + z*v.z + w*v.w;}
        inline Vector4Df normalize(void) { return Vector4Df{x,y,z,w}/norm(); }
        inline Vector4Df cross_product(const Vector4Df v) { return Vector4Df{y*v.z - z*v.y,z*v.x - x*v.z,x*v.y - y*v.x,w};}


        friend std::ostream& operator<<(std::ostream& out, const Vector4Df& v) { out << "[" << v.x << ", "; out <<  v.y << ", "; out <<  v.z << ", "; out <<  v.w << "]"; return out; }
    };

    struct Matrix4Df
    {
        union {
            float matrix[16];
            Vector4Df row[4];
            float _matrix[4][4];
        };

        inline Vector4Df operator*(const Vector4Df v) { return Vector4Df{row[0].dot_product(v), row[1].dot_product(v), row[2].dot_product(v), row[3].dot_product(v)}; }
    };

    inline Matrix4Df indentityMatrix(void) {return Matrix4Df{1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1};}
}

namespace CG {
    struct Material{
        LinearAlgebra::Vector3Df Ia, Id, Is; // Intensidade ambiente. Intensidade difusa. Intensidade especular
        float m; // Para calcular a reflexão
    };

    struct Result {
        float t;
        LinearAlgebra::Vector4Df Pint;
        LinearAlgebra::Vector4Df normal;
        Material objectMaterial;
        std::string label;
    };
}


#endif //TRABALHO_CG_HPP
