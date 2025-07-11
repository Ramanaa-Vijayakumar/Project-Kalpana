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
