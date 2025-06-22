# 4-Bit Up Counter Using LEDs

Create a 4-bit up counter using LEDs. The counter increases from 0 to 15, displaying the binary equivalent using four LEDs connected to an Arduino Uno.

---

## Components Used

- Arduino Uno R3
- 4 × Red  LEDs
- 4 × 220Ω Resistors
- Breadboard
- Jumper Wires

---

## Working Principle

The counter value is stored in a variable and updated in each loop. Each bit of the counter is sent to a specific LED. Once the value exceeds 15, the counter resets to 0.

Each LED represents one bit:
- LED 1 → LSB
- LED 4 → MSB

---

## Code

```cpp
const int ledPins[4] = {2, 3, 4, 5};
int counter = 0;

void setup(){
  for (int i = 0; i < 4; i++){
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop(){
  for (int i = 0; i < 4; i++){
    int bitValue = (counter >> i) & 1;
    digitalWrite(ledPins[i], bitValue);
  }

  delay(1000);

  counter++;
  if (counter > 15){
    counter = 0;
  }
}
```

## Simulation

[Tinkercad Simulation - 4-Bit Up Counterl](https://www.tinkercad.com/things/08Lvx1YWLgN-4-bit-up-counter-using-leds)
