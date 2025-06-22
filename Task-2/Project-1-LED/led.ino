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
