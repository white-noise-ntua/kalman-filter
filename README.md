# kalman-filter

One Dimensional Lightweight Kalman Filter for use with Arduino

## :nut_and_bolt: Usage

To use the Kalman Filter please refer to `example.cpp`.

## Parameters

* R is the process noise (internal noise of the system)
* Q is the measurement noise (how much noise is caused by your measurements)
* A, B, C are the system parameters. The system is described as `x[k + 1] = A x[k] + B u[k]`
