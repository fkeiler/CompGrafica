#include "Cone.hpp"
#include <cmath>

// Constructor
Cone::Cone(double Hi, double Ri, Point Ci, Vector ni)
{
  H, R = Hi, Ri;
  C = Ci;
  n = ni;
  
  // Calculando o valor do cos de Theta
  cosTheta = H / sqrt((H*H) + (R*R));

  // Calculando o Valor de V utilizando a formula 
  Point calculatedV(C.x - n.x*H, C.y - n.y*H, C.z - n.z*H);
  V = calculatedV;
}
