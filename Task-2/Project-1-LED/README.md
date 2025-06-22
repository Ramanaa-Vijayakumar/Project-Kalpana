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

- The **LED** is connected to **pin 11**, which supports PWM (Pulse Width Modulation) for brightness control via `analogWrite()`.
- The **push button** is connected to **pin 10**.
- Each press of the button cycles the LED brightness through three levels: `0` (off), `125` (medium), and `255` (full brightness).
- Debouncing is implemented in code to prevent multiple triggers from a single press.

---

## Code

```cpp
const int led = 11;
const int button = 10;

const int brightnessLevels[3] = {0, 125, 255};
int levelIndex = 0;

unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 50;

bool lastButtonState = LOW;
bool currentButtonState;
bool buttonPressed = false;

void setup(){
  pinMode(led, OUTPUT);
  pinMode(button, INPUT);
  analogWrite(led, brightnessLevels[levelIndex]);
}

void loop(){
  bool reading = digitalRead(button);

  if (reading != lastButtonState){
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay){
    if (reading == HIGH && !buttonPressed){
      buttonPressed = true;

      levelIndex = (levelIndex + 1) % 3;
      analogWrite(led, brightnessLevels[levelIndex]);
    }
  }

  if (reading == LOW){
    buttonPressed = false;
  }

  lastButtonState = reading;
}

```

## Simulation

[Tinkercad Simulation - LED Brightness Control](https://www.tinkercad.com/things/7ZZD9IJRQOg-controlling-led-brightness-with-a-button)
