int segmentPin1[7] = {13, 12, 11, 10, 9, 8, 7}; 
int segmentPin2[7] = {6, 5, 4, 3, 2, A1, A0}; 

int t = 500;

const int digitPatterns[10][7] = {
  {0,0,0,0,0,0,1}, // 0
  {1,0,0,1,1,1,1}, // 1
  {0,0,1,0,0,1,0}, // 2
  {0,0,0,0,1,1,0}, // 3
  {1,0,0,1,1,0,0}, // 4
  {0,1,0,0,1,0,0}, // 5
  {0,1,0,0,0,0,0}, // 6
  {0,0,0,1,1,1,1}, // 7
  {0,0,0,0,0,0,0}, // 8
  {0,0,0,0,1,0,0}  // 9
};

void displayDigit(int segPins[7], int number){
  for (int i = 0; i < 7; i++){
    digitalWrite(segPins[i], digitPatterns[number][i]);
  }
}

void setup(){
  for (int i = 0; i < 7; i++){
    pinMode(segmentPin1[i], OUTPUT);
    pinMode(segmentPin2[i], OUTPUT);
  }
}

void loop(){
  for (int i = 0; i <= 40; i++){
    int tens = i / 10;
    int ones = i % 10;
    displayDigit(segmentPin1, tens);
    displayDigit(segmentPin2, ones);
    delay(t);
  }
  for (int i = 39; i >= 0; i--){
    int tens = i / 10;
    int ones = i % 10;
    displayDigit(segmentPin1, tens);
    displayDigit(segmentPin2, ones);
    delay(t);
  }
}
