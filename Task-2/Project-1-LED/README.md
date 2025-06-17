# Project 1: Controlling LED Brightness with a Button (3 Levels)

## Overview

This project demonstrates how to control the **brightness of an LED** using a **push button**. With each button press, the brightness cycles through **three levels**: low, medium, and high.

---

## Components Used

- 1x Arduino Uno R3
- 1x Red LED
- 1x 220Ω Resistor
- 1x 10kΩ Resistor
- 1x Push Button
- Jumper wires
- Breadboard

---

## Circuit Explanation

- The **LED** is connected to **pin 11** (PWM output), allowing brightness control using `analogWrite()`.
- The **button** is connected to **pin 10** and is used to cycle through brightness levels.
- Each button press increases the brightness. Once it passes the maximum (`255`), it loops back to the first level.

---

## Code

```cpp
int led = 11;
int button = 10;

int brightness = 0;
int step = 80;

bool lastButtonState = LOW;

void setup(){
  pinMode(led, OUTPUT);
  pinMode(button, INPUT);
  analogWrite(led, brightness);
}

void loop(){
  bool currentButtonState = digitalRead(button);

  if (currentButtonState == HIGH && lastButtonState == LOW){
    brightness += step;
    if (brightness > 255){
      brightness = step;
    }
    analogWrite(led, brightness);
    delay(50);
  }

  lastButtonState = currentButtonState;
}

## Simulation

[Tinkercad Simulation - LED Brightness Control](https://www.tinkercad.com/things/7ZZD9IJRQOg-controlling-led-brightness-with-a-button/editel?returnTo=https%3A%2F%2Fwww.tinkercad.com%2Fdashboard)
