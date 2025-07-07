# Bouncing Counter on a 7-Segment Clock Peripheral

## Overview

This project demonstrates how to implement a simple bouncing counter using a 4-digit 7-segment display driven by the Adafruit LED Backpack library. The counter starts at 0, increases to 40, then reverses and decreases back to 0, repeating indefinitely. The display updates at regular intervals to show the current value.

---

## Components Used

- 1x Arduino Uno R3
- 1x Red, 112 (0x70) 7-Segment Clock Display
- 2x 220Ω Resistor
- Jumper wires
- Breadboard

---

## Circuit Explanation

- The 7-segment display used is an I2C-compatible module from Adafruit, which simplifies wiring and communication. It connects to the Arduino via the `SDA` and `SCL` pins (A4 and A5 on an Uno). The `Adafruit_LEDBackpack` and `Adafruit_GFX` libraries are used to control the display.
- The counter value is updated every 200 milliseconds. It increases by 1 until it reaches 40, then reverses and decreases by 1 until it reaches 0, creating a "bouncing" numeric effect. The display brightness is set to maximum (15) for clear visibility.

---

## Code

```cpp
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_LEDBackpack.h>

Adafruit_7segment display = Adafruit_7segment();

int current = 0;
int direction = 1;
unsigned long lastUpdate = 0;
const int delayTime = 200;

void setup(){
  display.begin(0x70);
  display.setBrightness(15);
}

void loop(){
  if (millis() - lastUpdate >= delayTime){
    lastUpdate = millis();
    current += direction;
    if (current >= 40) direction = -1;
    if (current <= 0) direction = 1;
    display.print(current);
    display.writeDisplay();
  }
}

```

## Simulation

[Tinkercad Simulation - 7Segment Clock Peripheral](https://www.tinkercad.com/things/icOkxN9FkWg-7segment-clock)
