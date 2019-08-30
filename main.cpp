#include <iostream>
#include "primitivos/Ray.hpp"
#include "primitivos/Cylinder.hpp"
#include "primitivos/Cone.hpp"

using namespace std;

int main() {
  // Point atirador;
  // Point pontoMatriz;
  // Matriz

  // Com base na matriz e no ponto do atirador
  Point p0(3, 3, 3);
  Vector d(-1, 0.6, -1);
  Ray raio(p0, d);
  // Cria o Raio: Ray(atirador, d)
  
  // Declara os valores e cria o Cone
  double alturaCone = 20;
  double raioCone = 20;
  Point centroCone(0, 0, 0);
  Vector direcaoCone(0, 1, 0);
  Cone cone(alturaCone, raioCone, centroCone, direcaoCone);
  
  Point *p = cone.colisionPoints(raio);

  cout << p0 << endl;

  // Declara os valores e cria o Cilindro
  // double alturaCilindro = 3;
  // double raioCilindro = 3;
  // Point centroCilindro(0, 0, 4);
  // Vector direcaoCilindro(0, 0, 1);
  // Cylinder cilindro1(alturaCone, raioCilindro, centroCilindro, direcaoCilindro);

  // Declara os valores e cria os Cubos
  // double arestaCubo;
  // Point centroBaseCubo;
  // Vector uCubo;
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
