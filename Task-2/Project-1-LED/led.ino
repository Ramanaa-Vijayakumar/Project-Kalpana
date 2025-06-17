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
