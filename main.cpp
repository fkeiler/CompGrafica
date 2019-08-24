#include <iostream>
#include "primitivos/Point.hpp"
#include "primitivos/Vector.hpp"

using namespace std;

int main() {
  Vector vetor(3, -4, -3);
  Vector result = vetor + 3;
  
  cout << result.x << endl << result.y << endl << result.z << endl;

  return 0;
}
