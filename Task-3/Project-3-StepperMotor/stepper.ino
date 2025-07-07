const int dirPin = 2;
const int stepPin = 3;
const int stepsPerRevolution = 200; 

int rotations = 2;    
bool clockwise = true;
int speedRPM = 60;

void setup(){
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);

  digitalWrite(dirPin, clockwise ? HIGH : LOW);

  int totalSteps = rotations * stepsPerRevolution;

  for (int i = 0; i < totalSteps; i++){
    digitalWrite(stepPin, HIGH);
    delay(10);
    digitalWrite(stepPin, LOW);
    delay(10);
  }
}

void loop(){
}
