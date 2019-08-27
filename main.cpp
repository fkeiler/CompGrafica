#include <iostream>
#include "primitivos/Point.hpp"
#include "primitivos/Vector.hpp"

using namespace std;

int main() {
  Point atirador;
  Point pontoMatriz;
  // Matriz

  // Com base na matriz e no ponto do atirador
  Vector d(atirador, pontoMatriz);

  // Cria o Raio: Ray(atirador, d)
  
  // Declara os valores e cria o Cone
  double alturaCone = 4;
  double raioCone = 3;
  Point centroCone(0, 0, 4);
  Vector direcaoCone(0, 0, 1);
  // Cone cone1(alturaCone, raioCone, centroCone, direcaoCone);
  
  // Declara os valores e cria o Cilindro
  double alturaCilindro = 3;
  double raioCilindro = 3;
  Point centroCilindro(0, 0, 4);
  Vector direcaoCilindro(0, 0, 1);
  // Cylinder cilindro1(alturaCone, raioCilindro, centroCilindro, direcaoCilindro);

  // Declara os valores e cria os Cubos
  double arestaCubo;
  Point centroBaseCubo;
  Vector uCubo;
  // Cube cubo1(arestaCubo, centroBaseCubo, uCubo);
  
  
  // Verifica colisão com cada objeto
  // cone1.verificaColisao(raio); => Struct True or False
  // cilindro.verificaColisao(raio); => Struct True or False
  // cubo1.verificaColisao(raio);
  // cubo2.verificaColisao(raio);
  // cubo3.verificaColisao(raio);

/*
  {
    Point
    Colisions = [
      {
        Cone1;
        Ponto1;
        Ponto2;
      }
    ];
  }
*/

  return 0;
}
