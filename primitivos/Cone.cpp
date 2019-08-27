#include "Cone.hpp"
#include <cmath>
#include <cstdlib>

// Constructor
Cone::Cone(double Hi, double Ri, Point Ci, Vector ni)
{
  H = Hi;
  R = Ri;
  C = Ci;
  n = ni;
  
  // Calculando o valor do cos de Theta
  cosTheta = H / sqrt((H*H) + (R*R));

  // Calculando o Valor de V utilizando a formula 
  Point calculatedV(C.x + n.x*H, C.y + n.y*H, C.z + n.z*H);
  V = calculatedV;
}

Point *Cone::colisionPoints(Ray raio)
{
  double a, b, c, delta;
  Point *p;
  // Calculando um vetor v para simplificar os cálculos
  Vector v(V.x - raio.p0.x, V.y - raio.p0.y, V.z - raio.p0.z);

  // Calculando a, b e c
  a = pow(raio.d.dotProduct(n), 2) - raio.d.dotProduct(raio.d)*pow(cosTheta, 2);
  b = 2*(v.dotProduct(raio.d)*pow(cosTheta, 2) - v.dotProduct(n)*raio.d.dotProduct(n));
  c = pow(v.dotProduct(n),2) - v.dotProduct(v)*pow(cosTheta, 2);

  // Verificando casos especificos envolvendo a base do cone
  if (a == 0 && b != 0) {
    double t = -c/(2*b);
    Point pAux(raio.p0.x + t*raio.d.x, raio.p0.y + t*raio.d.y, raio.p0.z + t*raio.d.z);
    double aux = (C.x - pAux.x)*n.x + (C.y - pAux.y)*n.y + (C.z - pAux.z)*n.z;

    if(aux >= 0 && aux <= H){
      // Caso que ele acerta a base do cone e está na altura correta
      p = (Point *) malloc(sizeof(Point));
      p[0] = pAux;
    } else {
      // Caso ele não acerte na altura correta
      p = NULL;
    }
  } 
  else if (a == 0 && b == 0) {
    // Caso invalido
    p = NULL;
  }

  delta = pow(b,2) - 4*a*c;

  if(delta < 0) {
    // Caso não teha nenhum ponto
    p = NULL;
  } 
  else if(delta == 0) {
    // Caso um único ponto seja encontrado
    // Calculando o valor de t
    double t = -b/(2*a);
    // Calculando os valores da coordenada do ponto
    Point pAux(raio.p0.x + t*raio.d.x, raio.p0.y + t*raio.d.y, raio.p0.z + t*raio.d.z);
    // Variável utilizada para auxiliar na verificação da altura
    double aux = (C.x - pAux.x)*n.x + (C.y - pAux.y)*n.y + (C.z - pAux.z)*n.z;

    // Verificando se o ponto acerta o cone numa altura válida
    if(aux >= 0 && aux <= H){
      // Caso que ele acerte o cone numa altura correta
      p = (Point *) malloc(sizeof(Point));
      p[0] = pAux;
    } else {
      // Caso ele não acerte na altura correta
      p = NULL;
    }
  } 
  else {
    // Dois Pontos
    double t1 = (sqrt(delta)-b)/(2*a);
    double t2 = (-sqrt(delta)-b)/(2*a);
    
    // Pontos encontrados
    Point p1(raio.p0.x + t1*raio.d.x, raio.p0.y + t1*raio.d.y, raio.p0.z + t1*raio.d.z);
    Point p2(raio.p0.x + t2*raio.d.x, raio.p0.y + t2*raio.d.y, raio.p0.z + t2*raio.d.z);

    double aux1 = (C.x - p1.x)*n.x + (C.y - p1.y)*n.y + (C.z - p1.z)*n.z;
    double aux2 = (C.x - p2.x)*n.x + (C.y - p2.y)*n.y + (C.z - p2.z)*n.z;

    // Verificando o critério da altura
    if (aux1 >= 0 && aux1 <=H && aux2 >= 0 && aux2 <=H){
      // Caso os dois pontos estejam com a altura correta
      p = (Point *) malloc(2*sizeof(Point));

      p[0] = p1;
      p[1] = p2;
    } else if (aux1 >= 0 && aux1 <=H) {
      // Caso apenas o ponto p1 esteja com a altura correta
      p = (Point *) malloc(sizeof(Point));

      p[0] = p1;
    } else if (aux2 >= 0 && aux2 <=H) {
      // Caso apenas o ponto p2 esteja com a altura correta
      p = (Point *) malloc(sizeof(Point));

      p[0] = p2;
    } else {
      // Caso nenhum dos dois esteja com a altura correta
      p = NULL;
    }
  }

  return p;
}
