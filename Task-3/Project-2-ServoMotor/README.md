# Servo Motor Control

## Overview

This project demonstrates how to control a servo motor by oscillating it between two positions using an Arduino. The servo moves from **0° to 180°**, pauses, then returns to **0°**, creating a back-and-forth motion. This simple setup is useful for understanding basic servo operation and can be adapted for gates, arms, or mechanical indicators.

---

## Components Used

- 1x Arduino Uno R3
- 1x Positional Micro Servo

---

## Circuit Explanation

The servo motor is connected to pin 9 on the Arduino. The `Servo` library is used to control the motor’s position. In the `loop()`, the servo first rotates to 0°, waits for 1.5 seconds, then moves to 180°, waits again, and finally returns to 0° without an additional delay—creating a complete oscillation cycle.
This illustrates basic position control of a servo and the use of delays to pace motion.

---

## Code

```cpp
#include <Servo.h>

Servo myServo;
int angle = 180;

void setup(){
  myServo.attach(9);
}

void loop(){
  myServo.write(0);
  delay(1500);
  myServo.write(angle);
  delay(1500);
  myServo.write(0);
}


```

## Simulation

[Tinkercad Simulation - Servo Motor Control](https://www.tinkercad.com/things/jp9YtITgMNd-servo-motor-from-0-to-x-degrees-and-back-to-0)
