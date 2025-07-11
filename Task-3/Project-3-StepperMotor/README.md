# Stepper Motor Control

## Overview

This project demonstrates how to rotate a stepper motor a specific number of revolutions using an Arduino. The motor rotates exactly two full turns in a specified direction and then stops. This is ideal for learning stepper control basics, precise positioning, and understanding how digital pulses translate to mechanical motion.

---

## Components Used

- 1x Arduino Uno R3
- 1x Bipolar Stepper Motor
- 1x A4988 Stepper Motor Driver

---

## Circuit Explanation

The stepper motor is controlled using two pins: one for the step signal (pin 3) and one for the direction signal (pin 2). The direction is set using a Boolean variable that determines the logic level on the direction pin. The motor receives 400 pulses (2 revolutions × 200 steps per revolution), toggling the step pin HIGH and LOW with a 10ms delay between changes to control the speed (approximately 60 RPM).
Since the control logic runs in setup(), the motor executes its motion once and stops. The loop() is left empty.

---

## Code

```cpp
const int dirPin = 2;
const int stepPin = 3;
const int stepsPerRotation = 200;

int rotations = 2;
bool clockwise = true;
int speedRPM = 60;

void setup(){
  Serial.begin(9600);
  delay(100);

  pinMode(dirPin, OUTPUT);
  pinMode(stepPin, OUTPUT);

  digitalWrite(dirPin, clockwise ? HIGH : LOW);

  Serial.println("Stepper Motor Control");
  Serial.print("Direction: ");
  Serial.println(clockwise ? "CounterClockwise" : "Clockwise");
  Serial.print("Rotations: ");
  Serial.println(rotations);
  Serial.print("Steps per rotation: ");
  Serial.println(stepsPerRotation);
  Serial.print("Speed (RPM): ");
  Serial.println(speedRPM);

  int totalSteps = rotations * stepsPerRotation;
  Serial.print("Total steps to move: ");
  Serial.println(totalSteps);

  for (int i = 0; i < totalSteps; i++){
    digitalWrite(stepPin, HIGH);
    delay(10);
    digitalWrite(stepPin, LOW);
    delay(10);
  }

  Serial.println("Movement complete.");
}

void loop(){
}


```

## Simulation

[Wokwi Simulation - LED Brightness Control](https://wokwi.com/projects/435793604204770305)
