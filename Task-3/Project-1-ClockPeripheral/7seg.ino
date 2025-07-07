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
