/*
  Copyright(C) 2019- White Noise Team

  One dimensional Kalman Filter implementation for
  use with BNO055 IMU to filter noisy gyro and
  accelerometer measurements.

  This software is distributed under the MIT License

  This file includes the headers of the Kalman Filter API
*/

class Kalman {
public:
  float R, Q, A, B, C;
  float cov;
  float x; // Signal without noise
  bool init;

  Kalman(float r, float q, float a, float b, float c);

  float filter(float z, float u);

  float predict(float u);

  float uncertainty();

};
