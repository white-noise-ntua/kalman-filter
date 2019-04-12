#include "Kalman.h"
#include <cstdlib>
#include <iostream>

using namespace std;

float randn() {
  return (float)rand() / (float) RAND_MAX;
}

int main() {
  Kalman *F = new Kalman(1, 1, 1, 1, 1);
  float z;
  for (int i = 0; i < 1000; i++) {
    z = randn();
    F->filter(z, 0);
    cout << "t: " << i << " x: " << F->x << " z: " << z << endl;

  }



}
