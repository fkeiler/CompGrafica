#include <iostream>
#include "primitivos/Point.hpp"
#include "primitivos/Vector.hpp"

using namespace std;

int main() {
  Vector V(3, -4, -3);
  Vector W(0, 1, 0);
  Vector result = V.normalize();
  
  cout << result.x << endl << result.y << endl << result.z << endl;

  return 0;
}
