/*
  Copyright(C) 2019- White Noise Team

  One dimensional Kalman Filter implementation for
  use with BNO055 IMU to filter noisy gyro and
  accelerometer measurements.

  This software is distributed under the MIT License

  This file includes the source of the Kalman Filter API
*/

#include "Kalman.h"

Kalman::Kalman(float r, float q, float a, float b, float c) {
  R = r;
  Q = q;
  A = a;
  B = b;
  C = c;
  init = false;
}

float Kalman::filter(float z, float u) {
  if (!init) {
    x = 1 / C * z;
    cov = Q / (C * C);
  }

  else {
    float pred = predict(u);
    float p_cov = uncertainty();

    float K = p_cov * C / (C * C * p_cov + Q);

    x = pred + K * (z - C * pred);
    cov = p_cov - K * C * p_cov;

  }

  return x;

}

float Kalman::predict(float u) {
  return A * x + B * u;
}

float Kalman::uncertainty() {
  return A * A * cov + R;
}
