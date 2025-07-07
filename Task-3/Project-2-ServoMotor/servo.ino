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
