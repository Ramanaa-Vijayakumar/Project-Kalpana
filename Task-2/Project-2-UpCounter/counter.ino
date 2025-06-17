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
